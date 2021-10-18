
#include "tps_unit_test.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define EPSILON 1e-8

typedef struct vector_2D {
  double x;
  double y;
} vector_2D;

#include "normalise-vect.h"



void test_0(void)
{
  vector_2D vect = {.x = 0, .y = 10};

  norm_vect(&vect);

  tps_assert(fabs(vect.y - 1) < EPSILON);
  tps_assert(fabs(vect.x) < EPSILON);

}

void test_1(void)
{
  vector_2D vect = {.x = 0, .y = -1};

  norm_vect(&vect);

  tps_assert(fabs(vect.y + 1) < EPSILON);
  tps_assert(fabs(vect.x) < EPSILON);

}

void test_2(void)
{
  vector_2D vect = {.x = 0, .y = 0};

  norm_vect(&vect);

  tps_assert(fabs(vect.y) < EPSILON);
  tps_assert(fabs(vect.x) < EPSILON);

}

void test_3(void)
{
  vector_2D vect = {.x = 0.1, .y = 0};

  norm_vect(&vect);

  tps_assert(fabs(vect.y) < EPSILON);
  tps_assert(fabs(vect.x-1) < EPSILON);

}
void test_4(void)
{
  vector_2D vect = {.x = 0.1, .y = 0.1};

  norm_vect(&vect);

  tps_assert(fabs(vect.y-1/sqrt(2)) < EPSILON);
  tps_assert(fabs(vect.x-1/sqrt(2)) < EPSILON);

}
void test_5(void)
{
  vector_2D vect = {.x = 100*cos(1), .y = 100*sin(1)};

  norm_vect(&vect);

  tps_assert(fabs(vect.x-cos(1)) < EPSILON);
  tps_assert(fabs(vect.y-sin(1)) < EPSILON);

}

// Tests avec xy

void test_6(void)
{
  vector_2D vect = {.x = 0, .y = -1};

  norm_vect_xy(&vect.x, &vect.y);

  tps_assert(fabs(vect.y + 1) < EPSILON);
  tps_assert(fabs(vect.x) < EPSILON);

}

void test_7(void)
{
  vector_2D vect = {.x = 0, .y = 0};

  norm_vect_xy(&vect.x, &vect.y);

  tps_assert(fabs(vect.y) < EPSILON);
  tps_assert(fabs(vect.x) < EPSILON);

}

void test_8(void)
{
  vector_2D vect = {.x = 0.1, .y = 0};

  norm_vect_xy(&vect.x, &vect.y);

  tps_assert(fabs(vect.y) < EPSILON);
  tps_assert(fabs(vect.x-1) < EPSILON);

}
void test_9(void)
{
  vector_2D vect = {.x = 0.1, .y = 0.1};

  norm_vect_xy(&vect.x, &vect.y);

  tps_assert(fabs(vect.y-1/sqrt(2)) < EPSILON);
  tps_assert(fabs(vect.x-1/sqrt(2)) < EPSILON);

}
void test_10(void)
{
  vector_2D vect = {.x = 100*cos(1), .y = 100*sin(1)};

  norm_vect_xy(&vect.x, &vect.y);

  tps_assert(fabs(vect.x-cos(1)) < EPSILON);
  tps_assert(fabs(vect.y-sin(1)) < EPSILON);

}

int main(int argc, char ** argv) {

  int test_idx = argc > 1 ? atoi(argv[1]) : -1;

  switch(test_idx){
    default:
    case 10:
    test_10();
    case 9:
    test_9();
    case 8:
    test_8();
    case 7:
    test_7();
    case 6:
    test_6();
    case 5:
    test_5();
    case 4:
    test_4();
    case 3:
    test_3();
    case 2:
    test_2();
    case 1:
    test_1();
    case 0:
    test_0();
  }

  return 0;
}
