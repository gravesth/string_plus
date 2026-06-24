#include <stdlib.h>

#include "../../s21_string.h"

START_TEST(test_memcpy_basic) {
  char src[] = "hello";
  s21_size_t n = 6;
  char *s21_dest = malloc(n * sizeof(char));
  char *dest = malloc(n * sizeof(char));

  memcpy(dest, src, n);
  s21_memcpy(s21_dest, src, n);

  ck_assert_mem_eq(s21_dest, dest, n);

  free(s21_dest);
  free(dest);
}
END_TEST

START_TEST(test_memcpy_zero_n) {
  char src[] = "hello";
  s21_size_t n = 6;
  char *s21_dest = malloc(n * sizeof(char));
  s21_dest[0] = 'X';

  s21_memcpy(s21_dest, src, 0);

  ck_assert_int_eq(s21_dest[0], 'X');

  free(s21_dest);
}
END_TEST

START_TEST(test_memcpy_return) {
  char src[] = "abcd";
  s21_size_t n = 5;
  char *s21_dest = malloc(n * sizeof(char));

  ck_assert_ptr_eq(s21_memcpy(s21_dest, src, n), s21_dest);

  free(s21_dest);
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s = suite_create("Memcpy Module");
  TCase *tc = tcase_create("Basic Tests");
  tcase_add_test(tc, test_memcpy_basic);
  tcase_add_test(tc, test_memcpy_zero_n);
  tcase_add_test(tc, test_memcpy_return);
  suite_add_tcase(s, tc);
  return s;
}
