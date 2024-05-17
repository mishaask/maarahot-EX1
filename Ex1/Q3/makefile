all: main

main: main.c libPoisson.so
	gcc -o main main.c -L. -lPoisson -Wl,-rpath,. -lm

libPoisson.so: Poisson.c
	gcc -shared -o libPoisson.so Poisson.c

run:
	./main

clean:
	rm -f main libPoisson.so
