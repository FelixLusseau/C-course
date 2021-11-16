CFLAGS ?= -Wall -Wextra -Werror
LDLIBS ?= 

tests: tests.o list.o
	gcc -o tests tests.o list.o $(CFLAGS)

tests.o: tests.c
	gcc -o tests.o -c tests.c $(CFLAGS)

list.o: list.c
	gcc -o list.o -c list.c $(CFLAGS)

clean:
	rm -f *.o tests