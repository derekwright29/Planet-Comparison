#ASEN 1969 Sample of Work Project
#Derek Wright
#Spring 2017
#CU Boulder

#Makefile to create executable file from planetcomp.c

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g

PROG = planetcomp
SRC = planetcomp.c

TAGS: $(SRC)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
