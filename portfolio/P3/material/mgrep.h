#ifndef MGREP_H
#define MGREP_H

#include <signal.h>
#include <stdio.h>

/* Result of the argument parsing. */
typedef struct {
  int ignore_case;     /* -i: ignore upper/lower case                    */
  int numbers;         /* -n: print line numbers                         */
  int count_only;      /* -c: print only the number of matching lines    */
  const char *pattern; /* pattern to search for (see matcher_match)      */
  int first_file;      /* index of the first FILE in argv, or argc       */
} Options;

/* The prepared pattern. You may add fields. */
typedef struct {
  const Options *opts;
} Matcher;

/* Parses argv. Options start with '-' and end at the first argument that
 * does not start with '-' or at "--". Several flags may be combined (-in).
 * Returns 0 on success and -1 on an unknown option or a missing PATTERN
 * (after printing a message to stderr for an unknown option). */
int parse_args(int argc, char *argv[], Options *opts);

/* Prepares the matcher (may be empty). Returns 0 on success, otherwise -1. */
int matcher_init(Matcher *m, const Options *opts);

/* Returns 1 if the line matches the pattern, otherwise 0. The line does NOT
 * contain the final line feed. You must implement the search yourself: strstr,
 * strcasestr, regcomp and similar functions are not allowed.
 *
 * Pattern language:
 *   any other character  matches itself (with -i: ignoring the case)
 *   .                    matches any single character
 *   ^  (first character) the match must start at the beginning of the line
 *   $  (last character)  the match must end at the end of the line
 * In all other positions ^ and $ are ordinary characters.
 * The pattern is searched anywhere in the line, unless it starts with ^. */
int matcher_match(const Matcher *m, const char *line);

/* Releases everything that matcher_init has allocated (may be empty). */
void matcher_free(Matcher *m);

/* Reads in line by line and writes every matching line to out (with the line
 * number and a colon in front if opts->numbers is set). Lines that are longer
 * than the internal buffer count as ONE line, are written completely, and
 * only their first characters are searched. With opts->count_only nothing is
 * written. The function stops reading as soon as g_interrupted is set.
 * Returns the number of matching lines. */
long grep_stream(FILE *in, const Matcher *m, FILE *out);

/* Set to 1 by the SIGINT handler. */
extern volatile sig_atomic_t g_interrupted;

/* Installs the SIGINT handler with sigaction. The handler only sets
 * g_interrupted. A blocking read must be interrupted by the signal (so the
 * flag SA_RESTART must not be set). Returns 0 on success, otherwise -1. */
int install_sigint_handler(void);

#endif
