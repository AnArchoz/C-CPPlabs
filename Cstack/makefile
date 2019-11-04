# List your *.h files here:
headers = Stack.h

# List your *.c files here:
sources = Stack.c main.c

program: $(headers) $(sources)
	gcc -g -Wall -pedantic -std=c99 $(sources) -o program

.PHONY: clean check debug

clean:
	-rm program

check: program
	valgrind ./program

debug: program
	gdb program
