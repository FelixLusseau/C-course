#include <stdio.h>
#include "minmax.h" // <- la fonction permut doit se trouver dans ce fichier

int main(void) {

    int n;
    scanf("%i", &n);

    int tn[n];

    for(int i = 0; i < n; i++) {
        scanf("%i", &tn[i]);
    }

    int min, max;
    // Appeler la fonction permut sur les entiers a, b et c
    // ....
    minmax(tn, n, &min, &max);


    printf("min: %i max: %i\n", min, max);  // doit afficher 2 3 1

}
