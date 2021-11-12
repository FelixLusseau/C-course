# include <stdio.h>
# include <stdlib.h>
# include "pair.h"

/**
  create a pair of elements
*/
pair_t *pair_create(void *first, void *second){
    pair_t * pair = malloc(sizeof(pair_t));
    if (pair == NULL)
        return NULL;
    pair->first=first;
    pair->second=second;
    return pair;
}

/**
  get the first element of the pair
*/
void *pair_get_first(pair_t *pair){
    return pair->first;
}

/**
  get the first element of the pair
*/
void *pair_get_second(pair_t *pair){
    return pair->second;
}

/**
  free the pair but not the elements
*/
void pair_free(pair_t *pair){
    if (pair != NULL)
        free(pair);
}

/**
  swap the first and the second elements
*/
void pair_swap(pair_t *pair){
    void * tmp=pair->first;
    pair->first=pair->second;
    pair->second=tmp;
}