# include <stdio.h>
# include <stdlib.h>
# include "append.h"

int append(int ** tab, size_t *size, int value){
    int * tabr = realloc(*tab, (*size+1)*sizeof(int));
    if (tabr == NULL)
        return 0;
    tabr[*size]=value;
    *tab=tabr;
    //printf("%li", *size);
    *size+=1;
    return 2;
}