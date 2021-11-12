# ifndef PAIR_H
# define PAIR_H
# include "tps_unit_test.h"

typedef struct pair_t
{
  void *first;
  void *second;
} pair_t;

/**
  create a pair of elements
*/
pair_t *pair_create(void *first, void *second);

/**
  get the first element of the pair
*/
void *pair_get_first(pair_t *pair);

/**
  get the first element of the pair
*/
void *pair_get_second(pair_t *pair);

/**
  free the pair but not the element
*/
void pair_free(pair_t *pair);

/**
  swap the first and the second elements
*/
void pair_swap(pair_t *pair);


# endif