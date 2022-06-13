CC=gcc
CFLAGS=-Wall -Wextra -g -std=c11 -pedantic
LIBS=
BINARY=rvm
SRC:=$(wildcard src/*.c)
OBJ:=$(SRC:.c=.o)

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(OBJ) -o $(BINARY)

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	@rm -v $(BINARY) $(OBJ)
