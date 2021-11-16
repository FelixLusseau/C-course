#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tps_unit_test.h"
#include "list.h"

TEST_INIT_GLOBAL

int note;

void test_create(void)
{
  ll_list* l = ll_create();
  tps_assert(l != NULL);
  ll_free(l);
}

void test_append(void)
{
    ll_list* l = ll_create();
    int a = 1;
    ll_append(l, &a);
    int b = 2;
    ll_append(l, &b);
    int c = 3;
    ll_append(l, &c);
    
    tps_assert(*(int*)ll_get(l,2) == 3);
    tps_assert(*(int*)ll_get(l,1) == 2);
    tps_assert(*(int*)ll_get(l,0) == 1);

    ll_free(l);
}

void test_pop_first(void)
{
    ll_list* l = ll_create();
    int a = 1;
    ll_append(l, &a);
    int b = 2;
    ll_append(l, &b);
    int c = 3;
    ll_append(l, &c);

    ll_pop_first(l);

    tps_assert(*(int*)ll_get(l,1) == 3);
    tps_assert(*(int*)ll_get(l,0) == 2);

    ll_free(l);
}


int match5(void* el) {
  return !('a'+*(char*)el-102);
}
void test_find(void)
{
    ll_list* l = ll_create();
    int a = 1;
    ll_append(l, &a);
    int b = 2;
    ll_append(l, &b);
    int c = 3;
    ll_append(l, &c);
    int d = 4;
    ll_append(l, &d);

    tps_assert(ll_find(l, match5) == NULL);

    int e = 5;
    ll_append(l, &e);
    int f = 6;
    ll_append(l, &f);

    tps_assert(ll_find(l, match5) != NULL);
    tps_assert(*(int*)ll_find(l, match5) == 5);

    ll_free(l);
}

void test_find_positive(void)
{
    ll_list* l = ll_create();
    int a = -2;
    ll_append(l, &a);
    int b = -1;
    ll_append(l, &b);
    int c = 0;
    ll_append(l, &c);
    
    tps_assert(ll_find(l, ll_match_positive_int) == NULL);

    int e = 10;
    ll_append(l, &e);
    int f = 20;
    ll_append(l, &f);

    tps_assert(ll_find(l, ll_match_positive_int) != NULL);
    tps_assert(*(int*)ll_find(l, ll_match_positive_int) == 10);

    ll_free(l);
}



int matchP(void *el, void *data) {
  return el == data; // à ne pâs reproduire à la maison
}
void test_find_data(void)
{
    ll_list* l = ll_create();
    int a = 1;
    ll_append(l, &a);
    int b = 2;
    ll_append(l, &b);
    int c = 3;
    ll_append(l, &c);
    int d = 4;
    ll_append(l, &d);

    tps_assert(ll_find_data(l, matchP, &d + 1) == NULL);

    int e = 5;
    ll_append(l, &e);
    int f = 6;
    ll_append(l, &f);

    tps_assert(ll_find_data(l, matchP, &e) != NULL);
    tps_assert(*(int*)ll_find_data(l, matchP, &e) == 5);

    ll_free(l);
}
void test_find_data_equals(void)
{
    ll_list* l = ll_create();
    int a = 1;
    ll_append(l, &a);
    int b = 2;
    ll_append(l, &b);
    int c = 3;
    ll_append(l, &c);
    int d = 4;
    ll_append(l, &d);

    int *elementToFound = malloc(sizeof(int));
    *elementToFound = 5;

    tps_assert(ll_find_data(l, ll_match_int_equals, elementToFound) == NULL);

    int e = 5;
    ll_append(l, &e);
    int f = 6;
    ll_append(l, &f);

    tps_assert(ll_find_data(l, ll_match_int_equals, elementToFound) != NULL);
    tps_assert(*(int*)ll_find_data(l, ll_match_int_equals, elementToFound) == 5);

    ll_free(l);
    free(elementToFound);
}

void test_find_data_students(void)
{
    ll_list* l = ll_create();
    student_t a = {.id = 1, .birthYear=2001, .name="Bob"};
    ll_append(l, &a);
    student_t b = {.id = 2, .birthYear=2002, .name="Bob 2"};
    ll_append(l, &b);
    student_t c = {.id = 3, .birthYear=2003, .name="Bob 3"};
    ll_append(l, &c);
    student_t d = {.id = 4, .birthYear=2004, .name="Bob 4"};
    ll_append(l, &d);

    unsigned long long *elementToFound = malloc(sizeof(unsigned long long));
    *elementToFound = 5;

    tps_assert(ll_find_data(l, ll_match_student, elementToFound) == NULL);

    srand(time(NULL));
    student_t e = {.id = 5, .birthYear=rand(), .name="Bob 5"};
    ll_append(l, &e);
    student_t f = {.id = 6, .birthYear=2006, .name="Bob 6"};
    ll_append(l, &f);

    student_t *found = (student_t*)ll_find_data(l, ll_match_student, elementToFound);
    tps_assert(found != NULL);
    tps_assert(found->id == 5);
    tps_assert(found->birthYear == e.birthYear);
    tps_assert(!strcmp(found->name, e.name));

    ll_free(l);
    free(elementToFound);
}


int main(void)
{
  note = 30;
  TEST(test_create);
  TEST(test_append);
  TEST(test_pop_first);

  TEST(test_find);
  note = 50;

  TEST(test_find_positive);
  note = 60;

  TEST(test_find_data);
  note = 70;

  TEST(test_find_data_equals);
  note = 80;

  TEST(test_find_data_students);

  return 0;
}
