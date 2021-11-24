#include <stdlib.h>
#include <stdio.h>
#include "ca_malloc.h"

int sizeg=0;

void * ca_malloc(int size){
    sizeg=size;
    char * tab = malloc(size+16);
    if (tab==NULL)
        exit(42);
    for (int i=0; i<8; i++){
        tab[i]=6;
    }
    for (int j=15+size; j>=8+size; j--){
        tab[j]=6;
    }
    return (int*)(tab+8);
}

void ca_free(int * pointeur){
    char * pointeurbis = (char*)pointeur-8;
    /* for (int k=0; k<16+sizeg; k++)
        printf("%i\n", pointeurbis[k]); */
    for (int i=0; i<8; i++){
        //fprintf(stderr, "%i\n", pointeurbis[i]);
        if ((char)pointeurbis[i]!=6){
            fprintf(stderr, "/!\\ un canary a été modifié !!");
            break;
        }
    }
    for (int j=15+sizeg; j>=8+sizeg; j--){
        //fprintf(stderr, "%i\n", pointeurbis[j]);
        if ((char)pointeurbis[j]!=6){
            fprintf(stderr, "/!\\ un canary a été modifié !!");
            break;
        }
    }
    free(pointeurbis);
}