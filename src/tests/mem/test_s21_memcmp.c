#include "../../s21_string.h"

START_TEST(test_memcmp_basic) {
  char mass1[] = "hello world1";
  char mass2[] = "hello world2";

  int orig = memcmp(mass1, mass2, 12);
  int s21_result = s21_memcmp(mass1, mass2, 12);

  ck_assert_int_eq(orig, s21_result);
}
END_TEST

START_TEST(test_memcmp_equal) {
  char mass1[] = "same string";
  char mass2[] = "same string";

  int orig = memcmp(mass1, mass2, 11);
  int s21_result = s21_memcmp(mass1, mass2, 11);

  ck_assert_int_eq(orig, s21_result);
  ck_assert_int_eq(s21_result, 0);
}
END_TEST

START_TEST(test_memcmp_zero_n) {
  char mass1[] = "abc";
  char mass2[] = "xyz";

  int orig = memcmp(mass1, mass2, 0);
  int s21_result = s21_memcmp(mass1, mass2, 0);

  ck_assert_int_eq(orig, s21_result);
  ck_assert_int_eq(s21_result, 0);
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s = suite_create("Tests");
  TCase *tc = tcase_create("Tests");
  tcase_add_test(tc, test_memcmp_basic);
  tcase_add_test(tc, test_memcmp_equal);
  tcase_add_test(tc, test_memcmp_zero_n);
  suite_add_tcase(s, tc);
  return s;
}
