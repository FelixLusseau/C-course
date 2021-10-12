#include <stdio.h>
#include "permut.h" // <- la fonction permut doit se trouver dans ce fichier

int main(void) {

    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    permut(&a,&b,&c);
    printf("%i %i %i\n", a, b, c);

}
