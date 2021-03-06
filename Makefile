.SUFFIXES: .c .h .o

CC	= gcc
INCLDIR	= include/
BINDIR	= bin/
SRCDIR	= src/

_BIN	= a.out
BIN	= $(addprefix $(BINDIR), $(_BIN))

SRC	= $(wildcard src/*.c)

CFLAGS = -Wall -std=c17 -pedantic -g -I$(INCLDIR) -fsanitize=address -fsanitize=undefined  -lm 

$(BINDIR)/$(_BIN): $(SRC)
	@$(CC) $(SRC) $(CFLAGS) -o $@

gendir: 
	@mkdir include bin src

clean: 
	@rm bin/a.out

.PHONY: gendir
.PHONY: clean
