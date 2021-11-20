latex-indent: latex-indent.o latex-indent.c
	gcc -o latex-indent.o -c latex-indent.c -Wall -Wextra -Werror -g
	gcc -o latex-indent latex-indent.o -Wall -Wextra -Werror -g

mestests: mestests.c
	gcc -o mestests mestests.c -Wall -Wextra -Werror -g

clean:
	rm -f *.o latex-indent