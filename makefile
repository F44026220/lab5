lab5: main.o hugeInt.o
	g++ -o lab5 main.o hugeInt.o

main.o: main.cpp hugeInt.h
	g++ -c main.cpp

HugeInt.o: hugeInt.cpp hugeInt.h
	g++ -c hugeInt.cpp
