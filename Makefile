CFLAGS=-std=c99 -Wall
CC=gcc

transposition: transposition.o main.o
	$(CC) $(CFLAGS) transposition.o main.o -o transposition

main.o: main.c transposition.h
	$(CC) $(CFLAGS) -c main.c

transposition.o: transposition.h transposition.c
	$(CC) $(CFLAGS) -c transposition.c

clean:
	rm -f transposition *.o
