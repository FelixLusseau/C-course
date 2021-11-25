tests: tests.c xmlp.o
	gcc -o tests.o -c tests.c -Wall -Wextra -Werror -g
	gcc -o tests tests.o xmlp.o -Wall -Wextra -Werror -g

xmlp.o: xmlp.c
	gcc -o xmlp.o -c xmlp.c -Wall -Wextra -Werror -g

clean:
	rm -f *.o tests