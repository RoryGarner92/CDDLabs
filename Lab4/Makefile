#Name : Rory Garner
#Class : Sofward Development
#Year : 4 
#2017-2018
CC = g++
cFlags = -std=c++11 -pthread -o Lab3.cpp
cFiles = signal.cpp Semaphore.cpp
hFiles = Semaphore.h

all: $(cFiles) $(hFiles)
	$(CC) $(cFlags) $(cFiles) -o Lab3

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

clean:
	rm*.o


CC=g++
CFLAGS= -std=c++11 -pthread -I.
DOXYGEN = doxygen
INDEX_SRC = docs/html/index.html
INDEX = firefox $(INDEX_SRC)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: Semaphore.o Barrier.o main.o
	$(CC) -o barrier Semaphore.o Barrier.o main.o $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

DOC: 
	$(DOXYGEN) Doxyfile
	$(INDEX)
DOC: ALL

CLEAN:
	rm *.o
