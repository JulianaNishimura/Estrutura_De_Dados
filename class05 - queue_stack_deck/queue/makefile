CC = gcc

CFLAGS = -Wall -Wextra

all: TAD_simple_queue

TAD_simple_queue: main.o queue.o
	$(CC) $(CFLAGS) -o TAD_simple_queue main.o queue.o

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c -o main.o main.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c -o queue.o queue.c

clean:
	rm -f TAD_simple_queue main.o queue.o