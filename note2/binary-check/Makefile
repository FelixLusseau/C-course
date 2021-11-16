CFLAGS ?= -Wall -Wextra -Werror -g
LDLIBS ?=

tests: tests.o checked-int.o
	gcc -o tests tests.o checked-int.o $(CFLAGS)

tests.o: tests.c
	gcc -o tests.o -c tests.c $(CFLAGS)

checked-int.o: checked-int.c
	gcc -o checked-int.o -c checked-int.c $(CFLAGS)

clean: 
	rm -f tests *.o