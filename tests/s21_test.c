#include "s21_test.h"

int main() {
  int numberFailed = 0;
  SRunner *sr = srunner_create(NULL);

  srunner_add_suite(sr,  test_suite_s21_is_add());
  srunner_add_suite(sr,  test_suite_s21_is_sub());
  srunner_add_suite(sr,  test_suite_s21_is_div());
  srunner_add_suite(sr,  test_suite_s21_is_mul());
  srunner_add_suite(sr,  test_suite_s21_is_equal());
  srunner_add_suite(sr,  test_suite_s21_is_greater());
  srunner_add_suite(sr,  test_suite_s21_is_greater_or_equal());
  srunner_add_suite(sr,  test_suite_s21_is_less());
  srunner_add_suite(sr,  test_suite_s21_is_less_or_equal());
  srunner_add_suite(sr,  test_suite_s21_is_not_equal());
  srunner_add_suite(sr,  test_suite_s21_negate());
  srunner_add_suite(sr,  test_suite_s21_truncate());
  srunner_add_suite(sr,  test_suite_s21_round());
  srunner_add_suite(sr,  test_suite_s21_floor());
  srunner_add_suite(sr,  test_suite_s21_is_convertors());



  srunner_run_all(sr, CK_NORMAL);

  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return !numberFailed ? 0 : 1;
}

