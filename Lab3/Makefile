#Name : Rory Garner
#Class : Sofward Development
#Year : 4 
#2017-2018
CC = g++
cFlags = -std=c++11 -pthread -o Lab3.cpp
cFiles = signal.cpp Semaphore.cpp
hFiles = Semaphore.h

ALL: $(cFiles) $(hFiles)
	$(CC) $(cFlags) $(cFiles) -o Lab3

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm*.o
