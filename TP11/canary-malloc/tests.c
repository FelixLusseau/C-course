#include "tps_unit_test.h"
#include "ca_malloc.h"

TEST_INIT_GLOBAL

void test_ok()
{
  int * tab = ca_malloc(3*sizeof(int));
  tps_assert(tab != NULL);
  tab[0] = 1;
  tab[1] = 1;
  tab[2] = 1;
  ca_free(tab);
  fprintf(stderr, "\n");
}
void test_erreur()
{
  int * tab = ca_malloc(3*sizeof(int));
  tps_assert(tab != NULL);
  tab[0] = 1;
  tab[1] = 1;
  tab[2] = 1;
  tab[3] = 1;
  ca_free(tab);
  fprintf(stderr, "\n");
}

int main(void)
{
  TEST(test_ok);
  TEST(test_erreur);
}
