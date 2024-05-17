CC = gcc
CFLAGS = -Wall -Wextra -g -pg

all: main

main: main.o maxSubArraySum.o
	$(CC) $(CFLAGS) -o main main.o maxSubArraySum.o

main.o: main.c maxSubArraySum.h
	$(CC) $(CFLAGS) -c main.c

maxSubArraySum.o: maxSubArraySum.c maxSubArraySum.h
	$(CC) $(CFLAGS) -c maxSubArraySum.c

run: main
	./main 42 100
	./main 42 1000
	./main 42 10000
	gprof main gmon.out > analysis.txt

clean:
	rm -f main main.o maxSubArraySum.o
