#include <stdio.h>
#include <stdlib.h>

#ifndef TPS_UNIT_TEST_H
#define TPS_UNIT_TEST_H

extern int note;

extern int __remaining_alloc;
extern char * __current_test_name;

#define TEST_INIT_GLOBAL \
  int __remaining_alloc; \
  char * __current_test_name;
  

#define calloc(a,b) \
  (__remaining_alloc \
    ? __remaining_alloc--, calloc(a,b) \
    : NULL)
#define malloc(a) \
  (__remaining_alloc \
    ? __remaining_alloc--, malloc(a) \
    : NULL)
#define realloc(a,b) \
  (__remaining_alloc \
    ? __remaining_alloc--, realloc(a,b) \
    : NULL)


#define tps_test_error(msg)  fprintf(stderr, "Error %s [ FAILED ]\n", msg)

#define tps_assert(expr) \
  do { \
    if (!(expr)) { \
      fprintf(stderr, "%s\n", __current_test_name); \
      tps_test_error("\nassertion failed: " #expr); \
      printf("%i\n", note); \
      exit(1); \
      return; \
    } \
  } while (0)

#define TEST(func) do \
{ \
  __current_test_name = #func; \
  printf("%i\n", note); fflush(stdout); \
  func(); \
  fprintf(stderr, "%s\n", __current_test_name); \
  fprintf(stderr, "%s\n", "Done"); \
} while(0)


#endif

