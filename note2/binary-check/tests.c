#include <stdio.h>
#include "tps_unit_test.h"
#include "checked-int.h"
#include "checked-int.h" // <- permet de tester si le fichier est protégé contre la double inclusion.

TEST_INIT_GLOBAL

int note;

void test_encode_decode(void){
    
    uint32_t n = 0xff321ea6;
    uint64_t e = ci_encode(n);
    tps_assert(n == ci_decode(e, NULL));

}

void test_encode(void){
    
    uint32_t n = 0x11;
    uint64_t e = ci_encode(n);
    tps_assert(e == 0x1100000011);

    n = 0xff321ea6;
    e = ci_encode(n);
    tps_assert(e == 0xff321ea6ff321ea6);

}

void test_check(void){
    
    uint32_t n = 0xff321ea6;
    uint64_t e = ci_encode(n);
    tps_assert(ci_check(e));
    tps_assert(ci_check(0x1100000011));
    tps_assert(ci_check(0xff321ea6ff321ea6));
    tps_assert(!ci_check(0x1200000011));
    tps_assert(!ci_check(0xfa321ea6ff321ea6));
}

void test_decode_null(void){
    
    tps_assert(ci_decode(0x1200000011, NULL) == 0x11);
    tps_assert(ci_decode(0x1100000012, NULL) == 0x11);
    tps_assert(ci_decode(0xfa321ea6ff321ea6, NULL) == 0xfa321ea6);

}
void test_decode_p(void){
    int ok;
    ci_decode(0x1100000011, &ok);
    tps_assert(ok);
    ci_decode(0xff321ea6ff321ea6, &ok);
    tps_assert(ok);

    ci_decode(0x1200000011, &ok);
    tps_assert(!ok);
    ci_decode(0x1100000012, &ok);
    tps_assert(!ok);
    ci_decode(0xfa321ea6ff321ea6, &ok);
    tps_assert(!ok);

}

int main(void)
{
  TEST(test_encode_decode);
  note = 40;
  TEST(test_encode);
  note = 50;
  TEST(test_check);
  note = 60;
  TEST(test_decode_null);
  note = 70;
  TEST(test_decode_p);
  return 0;
}
