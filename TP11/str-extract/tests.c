#include "tps_unit_test.h"
#include "str-extract.h"
#include <stdio.h>
#include <string.h>

TEST_INIT_GLOBAL


void test_1()
{
  FILE * in = fopen("test-0/in", "r");
  tps_assert(in != NULL);

  char buffer[1000];
  strExtract(in, " ", buffer, 1000);
  tps_assert(strcmp(buffer, "abcd") == 0);
  tps_assert(fgetc(in) == ' ');
  fclose(in);
}
void test_2()
{
  FILE * in = fopen("test-0/in", "r");
  tps_assert(in != NULL);

  char buffer[1000];
  strExtract(in, "k", buffer, 1000);
  tps_assert(strcmp(buffer, "abcd efgh\nij") == 0);
  tps_assert(fgetc(in) == 'k');
  fclose(in);
}
void test_3()
{
  FILE * in = fopen("test-0/in", "r");
  tps_assert(in != NULL);

  char buffer[1000];
  strExtract(in, "Z", buffer, 1000);
  tps_assert(strcmp(buffer, "abcd efgh\nijkl mnop") == 0);
  tps_assert(feof(in));
  fclose(in);
}

void test_4()
{
  FILE * in = fopen("test-0/in", "r");
  tps_assert(in != NULL);

  char buffer[1000];
  strExtract(in, "fgh", buffer, 1000);
  tps_assert(strcmp(buffer, "abcd e") == 0);
  tps_assert(fgetc(in) == 'f');
  fclose(in);
}


int main(void)
{
  TEST(test_1);
  TEST(test_2);
  TEST(test_3);
  TEST(test_4);
}
