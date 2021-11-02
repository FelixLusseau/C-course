tests: tests.o linked-list.o
	gcc -o tests.o -c tests.c -Wall -Wextra -Werror -g
	gcc -o tests tests.o linked-list.o -Wall -Wextra -Werror -g
	
linked-list: linked-list.c linked-list.h
	gcc -o linked-list.o -c linked-list.c -Wall -Wextra -Werror -g

clean:
	rm -rf *.o
	rm -rf tests