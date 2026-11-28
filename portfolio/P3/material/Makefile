# Compile with: make
# All .c files of this folder are part of the program.
CC = gcc
CFLAGS = -std=c11 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -g
SRC = $(wildcard *.c)

mgrep: $(SRC) mgrep.h
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f mgrep
