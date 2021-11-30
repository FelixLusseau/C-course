tests: tests.o str-extract.o
	gcc -o tests tests.o str-extract.o -Wall -Wextra -Werror

tests.o: tests.c
	gcc -o tests.o -c tests.c -Wall -Wextra -Werror

str-extract.o: str-extract.c
	gcc -o str-extract.o -c str-extract.c -Wall -Wextra -Werror

clean:
	rm -f *.o tests