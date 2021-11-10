CFLAGS ?= -Wall -Wextra -Werror

calc: calc.o parser.o calc-io.o
	gcc -o calc.o -c calc.c $(CFLAGS)
	gcc -o calc calc.o parser.o calc-io.o $(CFLAGS) -lm

parser.o: parser.c parser.h
	gcc -o parser.o -c parser.c $(CFLAGS)

calc-io.o: calc-io.c calc-io.h
	gcc -o calc-io.o -c calc-io.c $(CFLAGS)

tests: tests.c
	gcc -o tests.o -c tests.c $(CFLAGS)
	gcc -o tests tests.o parser.o calc-io.o $(CFLAGS) -lm

clean:
	rm -rf *.o calc tests