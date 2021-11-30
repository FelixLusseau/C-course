#include <stdio.h>
#include "tps_unit_test.h"

#include "bmp-io.h"

TEST_INIT_GLOBAL

void test_1(void)
{
  tps_assert(1);
}
int main(void)
{
  TEST(test_1);
}
