#include <stdlib.h>
#include <stdio.h>
#include "ca_malloc.h"

int sizeg=0;

void * ca_malloc(int size){
    sizeg=size;
    int * tab = malloc(size+16*sizeof(int));
    if (tab==NULL)
        exit(42);
    for (int i=0; i<8; i++){
        tab[i]=6;
    }
    for (int j=15+size/4; j>=8+size/4; j--){
        tab[j]=6;
    }
    return tab+8;
}

void ca_free(int * pointeur){
    int * pointeurbis = pointeur-8;
    /* for (int k=0; k<16+sizeg; k++)
        printf("%i\n", pointeurbis[k]); */
    for (int i=0; i<8; i++){
        //fprintf(stderr, "%i\n", pointeurbis[i]);
        if (pointeurbis[i]!=6){
            fprintf(stderr, "/!\\ un canary a été modifié !!");
            break;
        }
    }
    for (int j=15+sizeg/4; j>=8+sizeg/4; j--){
        //fprintf(stderr, "%i\n", pointeurbis[j]);
        if (pointeurbis[j]!=6){
            fprintf(stderr, "/!\\ un canary a été modifié !!");
            break;
        }
    }
    free(pointeurbis);
}