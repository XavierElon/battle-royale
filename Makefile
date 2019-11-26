CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: project4

project4: main.o character.o functions.o dice.o barbarian.o vampire.o blueMen.o medusa.o harryPotter.o 
	$(CC) main.o character.o functions.o dice.o barbarian.o vampire.o blueMen.o medusa.o harryPotter.o -o project4

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

character.o: character.cpp character.hpp
	$(CC) $(CFLAGS) character.cpp

functions.o: functions.cpp functions.hpp
	$(CC) $(CFLAGS) functions.cpp

dice.o: dice.cpp dice.hpp
	$(CC) $(CFLAGS) dice.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	$(CC) $(CFLAGS) barbarian.cpp

vampire.o: vampire.cpp vampire.hpp
	$(CC) $(CFLAGS) vampire.cpp

blueMen.o: blueMen.cpp blueMen.hpp
	$(CC) $(CFLAGS) blueMen.cpp

medusa.o: medusa.cpp medusa.hpp
	$(CC) $(CFLAGS) medusa.cpp

harryPotter.o: harryPotter.cpp harryPotter.hpp
	$(CC) $(CFLAGS) harryPotter.cpp

clean:
	rm -r *.o project4
