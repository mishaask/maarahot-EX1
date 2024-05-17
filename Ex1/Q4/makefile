CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic -fprofile-arcs -ftest-coverage

.PHONY: all clean coverage

all: Djikstras

Djikstras: Djikstras.o
	$(CC) $(CFLAGS) Djikstras.o -o Djikstras -lgcov

Djikstras.o: Djikstras.c
	$(CC) $(CFLAGS) -c Djikstras.c -o Djikstras.o

clean:
	rm -f Djikstras.o Djikstras

run: Djikstras
	./Djikstras
	gcov Djikstras.c

