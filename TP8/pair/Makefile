CFLAGS ?= -Wall -Wextra -Werror

tests: tests.o pair.o
	gcc -o tests.o -c tests.c $(CFLAGS)
	gcc -o tests tests.o pair.o $(CFLAGS)

pair.o: pair.c
	gcc -o pair.o -c pair.c $(CFLAGS)

clean:
	rm -f tests *.o