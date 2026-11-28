#include "mgrep.h"
#include <string.h>

int parse_args(int argc, char *argv[], Options *opts) {
  opts->ignore_case = 0;
  opts->numbers = 0;
  opts->count_only = 0;
  opts->pattern = NULL;
  opts->first_file = argc;

  int i = 1;

  while (i < argc && argv[i][0] == '-') {

    if (strcmp(argv[i], "--") == 0) {
      i++;
      break;
    }

    int j = 1;

    while (argv[i][j] != '\0') {
      switch (argv[i][j]) {
      case 'i':
        opts->ignore_case = 1;
        break;

      case 'n':
        opts->numbers = 1;
        break;

      case 'c':
        opts->count_only = 1;
        break;

      default:
        fprintf(stderr, "Unknown option: -%c\n", argv[i][j]);
        return -1;
      }
      j++;
    }
    i++;
  }
  if (i >= argc) {
    return -1;
  }
  opts->pattern = argv[i];
  opts->first_file = i + 1;
  return 0;
}

int matcher_init(Matcher *m, const Options *opts) {
  m->opts = opts;
  m->start_flag = 0;
  m->end_flag = 0;
  m->pattern_len = strlen(opts->pattern);
  m->pattern = opts->pattern;

  if (m->pattern_len > 0 && m->pattern[m->pattern_len - 1] == '$') {
    m->pattern_len--;
    m->end_flag = 1;
  }

  if (m->pattern[0] == '^') {
    m->pattern_len--;
    m->start_flag = 1;
    m->pattern++;
  }

  return 0;
}
