FLAGS=-Wall

all: main.o debug.o storage.o
	gcc $(FLAGS) main.o debug.o storage.o

main.o: main.c debug.h storage.h
	gcc -c main.c

debug.o: debug.c debug.h
	gcc -c debug.c

storage.o: storage.c storage.h
	gcc -c storage.c

clean:
	rm *.o
