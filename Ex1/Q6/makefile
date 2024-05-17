all: add2PB findPhone

add2PB: add2PB.cpp
	g++ -Wall -std=c++11 add2PB.cpp -o add2PB

findPhone: findPhone.cpp
	g++ -Wall -std=c++11 findPhone.cpp -o findPhone

clean:
	rm -f add2PB findPhone

run: 
	./add2PB Mickey shmouse,0123456789
	./findPhone Mickey shmouse

.PHONY: all clean run
