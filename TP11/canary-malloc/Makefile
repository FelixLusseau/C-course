tests: ca_malloc.o
	gcc -o tests.o -c tests.c -Wall -Wextra -Werror -g
	gcc -o tests tests.o ca_malloc.o -Wall -Wextra -Werror -g

ca_malloc.o: ca_malloc.c
	gcc -o ca_malloc.o -c ca_malloc.c -Wall -Wextra -Werror -g

clean:
	rm -f *.o tests