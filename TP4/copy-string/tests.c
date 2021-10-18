#include <stdio.h>
#include "tps_unit_test.h"
#include "copy.h"

TEST_INIT_GLOBAL 

void test_example_1(void)
{
  __remaining_alloc = 0;
  char *str2;
  copy("test1", &str2);
  tps_assert(str2 == NULL);
  free(str2);
}

void test_example_2(void)
{
  __remaining_alloc = 10;
  char str1[] = "test2";
  char *str2;
  copy(str1, &str2);
  tps_assert(strcmp(str1, str2) == 0);
  tps_assert(str1 != str2);
  free(str2);
}

void test_example_3(void)
{
  __remaining_alloc = 10;
  char str1[] = "";
  char *str2;
  copy(str1, &str2);
  tps_assert(strcmp(str1, str2) == 0);
  tps_assert(str1 != str2);
  free(str2);
}

void test_example_4(void)
{
  __remaining_alloc = 10;
  char str1[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  char *str2;
  copy(str1, &str2);
  tps_assert(strcmp(str1, str2) == 0);
  tps_assert(str1 != str2);
  free(str2);
}

int main(void) {

  TEST(test_example_1);
  TEST(test_example_2);
  TEST(test_example_3);
  TEST(test_example_4);
  return 0;
}
