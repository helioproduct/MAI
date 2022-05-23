CC = gcc

all: generate print main

generate: io.o generate.o
	$(CC) $^ -o $@

print: io.o print.o
	$(CC) $^ -o $@

main: io.o main.o
	$(CC) $^ -o $@

clean:
	rm -f *.o
