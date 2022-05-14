CC=gcc
CFLAGS=-Wall -Wextra -g -std=c11
LIBS=
BINARY=build/rvm

all:
	$(CC) -c src/machine.c -o build/machine.o $(CFLAGS) $(LIBS)
	$(CC) -c src/decode.c -o build/decode.o $(CFLAGS) $(LIBS)
	$(CC) -c src/main.c -o build/main.o $(CFLAGS) $(LIBS)
	$(CC) -o $(BINARY) build/main.o build/machine.o build/decode.o $(CFLAGS) $(LIBS) 