tests: tests.o append.o
	gcc -o tests.o -c tests.c -Wall -Wextra -Werror -g
	gcc -o tests tests.o append.o -Wall -Wextra -Werror -g

append.o: append.c append.h
	gcc -o append.o -c append.c -Wall -Wextra -Werror -g

clean:
	rm -f *.o tests