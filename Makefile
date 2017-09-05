CC = gcc
CFLAGS = -Wall

maxalloc: maxalloc.c
	$(CC) $(CFLAGS) -o $@ maxalloc.c

clean:
	rm -f maxalloc
