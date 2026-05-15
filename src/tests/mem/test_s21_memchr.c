#include "../../s21_string.h"
#include <check.h>
#include <string.h>

START_TEST(test_memchr) {
  char mass[] = "hello world";
  char ch = '0';

  const void *orig = memchr(mass, ch, strlen(mass));
  const void *s21_result = s21_memchr(mass, ch, strlen(mass));

  ck_assert_ptr_eq(orig, s21_result);
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s = suite_create("Tests");
  TCase *tc = tcase_create("Tests");
  tcase_add_test(tc, test_memchr);
  suite_add_tcase(s, tc);
  return s;
}

int main() { 
    Suite *s = memchr_suite(); 

    SRunner *sr = srunner_create(s); 
    srunner_run_all(sr, CK_NORMAL);
    int num_failed = srunner_ntests_failed(sr); 
    srunner_free(sr);
    return (num_failed == 0) ? 0 : 1;
}
