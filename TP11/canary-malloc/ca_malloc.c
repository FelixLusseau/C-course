#include <stdlib.h>
#include <stdio.h>
#include "ca_malloc.h"

void * ca_malloc(int size){
    char * tab = malloc(size+16+sizeof(unsigned long long int));
    if (tab==NULL)
        exit(42);
    for (unsigned long long int i=0+sizeof(unsigned long long int); i<8+sizeof(unsigned long long int); i++){
        tab[i]=6;
    }
    for (unsigned long long int j=15+size+sizeof(unsigned long long int); j>=8+size+sizeof(unsigned long long int); j--){
        tab[j]=6;
    }
    *(unsigned long long int*)tab=size;
    return (int*)(tab+8+sizeof(unsigned long long int));
}

void ca_free(int * pointeur){
    char * pointeurbis = (char*)pointeur-8-sizeof(unsigned long long int);
    for (unsigned long long int k=0; k<16+(*(unsigned long long int*)pointeurbis); k++)
        printf("%i\n", pointeurbis[k]);
    for (unsigned long long int i=0+sizeof(unsigned long long int); i<8+sizeof(unsigned long long int); i++){
        //fprintf(stderr, "%i\n", pointeurbis[i]);
        if ((char)pointeurbis[i]!=6){
            fprintf(stderr, "/!\\ un canary a été modifié !!");
            break;
        }
    }
    for (unsigned long long int j=15+(*(unsigned long long int*)pointeurbis)+sizeof(unsigned long long int); j>=8+(*(unsigned long long int*)pointeurbis)+sizeof(unsigned long long int); j--){
        //fprintf(stderr, "%i\n", pointeurbis[j]);
        if ((char)pointeurbis[j]!=6){
            fprintf(stderr, "/!\\ un canary a été modifié !!");
            break;
        }
    }
    free(pointeurbis);
}