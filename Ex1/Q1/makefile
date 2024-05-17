.PHONY: all clean run debug no_debug ddd

all: divisionByZero stackOverflow uninitializedMemory

stackOverflow: stackOverflow.c
	gcc -g -o stackOverflow stackOverflow.c
	gcc -o stackOverflow_no_debug stackOverflow.c

divisionByZero: divisionByZero.c
	gcc -g -o divisionByZero divisionByZero.c
	gcc -o divisionByZero_no_debug divisionByZero.c

uninitializedMemory: uninitializedMemory.c
	gcc -g -o uninitializedMemory uninitializedMemory.c
	gcc -o uninitializedMemory_no_debug uninitializedMemory.c

run: divisionByZero stackOverflow uninitializedMemory divisionByZero_no_debug stackOverflow_no_debug uninitializedMemory_no_debug
	ulimit -c unlimited && ./divisionByZero || true
	ulimit -c unlimited && ./stackOverflow || true
	ulimit -c unlimited && ./uninitializedMemory || true
	ulimit -c unlimited && ./divisionByZero_no_debug || true
	ulimit -c unlimited && ./stackOverflow_no_debug || true
	ulimit -c unlimited && ./uninitializedMemory_no_debug || true

gdb:
	gdb ./divisionByZero core
	gdb ./stackOverflow core
	gdb ./uninitializedMemory core
	gdb ./divisionByZero_no_debug core
	gdb ./stackOverflow_no_debug core
	gdb ./uninitializedMemory_no_debug core

ddd:
	ddd ./divisionByZero core 
	ddd ./stackOverflow core 
	ddd ./uninitializedMemory core 
	ddd ./divisionByZero_no_debug core 
	ddd ./stackOverflow_no_debug core 
	ddd ./uninitializedMemory_no_debug core 

clean:
	rm -f divisionByZero stackOverflow uninitializedMemory divisionByZero_no_debug stackOverflow_no_debug uninitializedMemory_no_debug core
clean_core:
	rm -f core