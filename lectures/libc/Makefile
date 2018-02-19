CC=gcc
LDFLAGS=-lm
SOURCES=$(wildcard *.c)
EXECUTABLES=$(SOURCES:.c=.)

all: $(EXECUTABLES)

$(EXECUTABLES):
	$(CC) $@c $(LDFLAGS) -o $@out

clean:
	rm -f *.out
