CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=part1
SRC= $(wildcard *.c) $(wildcard **/*.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

part1: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c sorted_job_list.h
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf **/*.o

mrproper: clean
	rm -rf $(EXEC)
