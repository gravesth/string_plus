#include <stdlib.h>
#include "../../s21_string.h"
START_TEST(test_memset_basic) {
  s21_size_t n = 10;
  char *s21_buf = malloc(n * sizeof(char));
  char *buf = malloc(n * sizeof(char));
  int ch = 'A';
  
  memset(buf, ch, n);
  s21_memset(s21_buf, ch, n);
  ck_assert_mem_eq(s21_buf, buf, n);
  free(s21_buf);
  free(buf);
}
END_TEST

START_TEST(test_memset_zero_n) {
  s21_size_t n = 5;
  char *s21_buf = malloc(n * sizeof(char));
  s21_buf[0] = 'X';
  s21_memset(s21_buf, 'Z', 0);
  ck_assert_int_eq(s21_buf[0], 'X');
  free(s21_buf);
}
END_TEST

START_TEST(test_memset_return) {
  s21_size_t n = 5;
  char *s21_buf = malloc(n * sizeof(char));
  ck_assert_ptr_eq(s21_memset(s21_buf, 'B', n), s21_buf);
  free(s21_buf);
}
END_TEST

Suite *memset_suite(void) {
  Suite *s = suite_create("Memset Module");
  TCase *tc = tcase_create("Basic Tests");
  tcase_add_test(tc, test_memset_basic);
  tcase_add_test(tc, test_memset_zero_n);
  tcase_add_test(tc, test_memset_return);
  suite_add_tcase(s, tc);
  return s;
}
