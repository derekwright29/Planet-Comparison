CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g

PROG = planetcomp
SRC = planetcomp.c

TAGS: $(SRC)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
