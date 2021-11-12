#include <stdio.h>
#include "tps_unit_test.h"
#include "pair.h"
#include "pair.h" // <- permet de tester si le fichier est protégé contre la double inclusion.

TEST_INIT_GLOBAL

void test_create(void)
{
  __remaining_alloc = -1; // Pas de problème d'allocation

  int a = 1, b = 2;
  pair_t *pair = pair_create(&a, &b);

  int *pfirst = (int*)pair_get_first(pair);
  int first = *pfirst;

  tps_assert(first == 1);
  pair_free(pair);
}

void test_get_second(void)
{
  __remaining_alloc = -1; // Pas de problème d'allocation

  int a = 1, b = 2;
  pair_t *pair = pair_create(&a, &b);

  int *psecond = (int*)pair_get_second(pair);
  int second = *psecond;

  tps_assert(second == 2);
  pair_free(pair);
}

void test_swap(void)
{
  __remaining_alloc = -1; // Pas de problème d'allocation

  int a = 1, b = 2;
  pair_t *pair = pair_create(&a, &b);

  pair_swap(pair);

  int *psecond = (int*)pair_get_second(pair);
  int second = *psecond;
  tps_assert(second == 1);

  int *pfirst = (int*)pair_get_first(pair);
  int first = *pfirst;
  tps_assert(first == 2);

  pair_free(pair);
}

void test_error_malloc(void)
{
  __remaining_alloc = 0; // problème d'allocation

  int a = 1, b = 2;
  pair_t *pair = pair_create(&a, &b);

  tps_assert(pair == NULL);

  pair_free(pair); // ne doit rien faire
}

void test_hidden_struct(void)
{
  pair_t pair; // permet de tester si la structure est bien définie dans le .h
  (void)pair;
}

int main(void)
{
  TEST(test_create);
  TEST(test_get_second);
  TEST(test_swap);
  TEST(test_error_malloc);
  TEST(test_hidden_struct);
}
