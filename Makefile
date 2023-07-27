CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -pthread
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): main.o search_files.o
	$(CC) $(CFLAGS) main.o search_files.o -o $(EXECUTABLE)

main.o: main.cpp search_files.h
	$(CC) $(CFLAGS) -c main.cpp

search_files.o: search_files.cpp search_files.h
	$(CC) $(CFLAGS) -c search_files.cpp

clean:
	rm -f $(EXECUTABLE) *.o
