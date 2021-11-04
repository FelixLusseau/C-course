#include <stdio.h>
#include <stdlib.h>
#include "tps_unit_test.h"
#include "append.h"

int note;

TEST_INIT_GLOBAL

void test_example_1(void)
{
  __remaining_alloc = -1;
  size_t size = 4;

  int *tab = malloc(size*sizeof(int));
  for(size_t i = 0; i < size; i++) tab[i] = i;

  int ok = append(&tab, &size, 5);
  tps_assert(ok != 0);
  tps_assert(size == 5);
  tps_assert(tab[4] == 5);
  free(tab);
}

void test_example_2(void)
{
  __remaining_alloc = -1;
  size_t size = 0;

  int *tab = NULL;

  int ok = append(&tab, &size, 1);
  tps_assert(ok != 0);
  tps_assert(size == 1);
  tps_assert(tab[0] == 1);
  free(tab);
}

void test_error_malloc(void)
{
  __remaining_alloc = 1;
  size_t size = 4;

  int *tab = malloc(size*sizeof(int));
  for(size_t i = 0; i < size; i++) tab[i] = i;

  int ok = append(&tab, &size, 5);
  tps_assert(ok == 0);
  free(tab);
}

int main(void) {

  TEST(test_example_1);
  note = 20;
  TEST(test_example_2);
  note = 40;
  TEST(test_error_malloc);
  return 0;
}
