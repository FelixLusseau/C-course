custom-plaque: custom-plaque.o generer-plaque.o
	gcc -o custom-plaque.o -c custom-plaque.c
	gcc -o custom-plaque custom-plaque.o generer-plaque.o -lm

generer-plaque: generer-plaque-main.o generer-plaque.o
	gcc -o generer-plaque generer-plaque.o generer-plaque-main.o

generer-plaque.o: generer-plaque.c
	gcc -o generer-plaque.o -c generer-plaque.c
	
generer-plaque-main.o: generer-plaque-main.c
	gcc -o generer-plaque-main.o -c generer-plaque-main.c

clean:
	rm -f *.o generer-plaque custom-plaque