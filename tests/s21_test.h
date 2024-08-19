#ifndef S21_TEST_H
#define S21_TEST_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../s21_decimal.h"
#include "../help_functions.h"

#include <check.h>


Suite *test_suite_s21_is_add();
Suite *test_suite_s21_is_sub();
Suite *test_suite_s21_is_div();
Suite *test_suite_s21_is_mul();
Suite *test_suite_s21_is_equal();
Suite *test_suite_s21_is_greater();
Suite *test_suite_s21_is_greater_or_equal();
Suite *test_suite_s21_is_less();
Suite *test_suite_s21_is_less_or_equal();
Suite *test_suite_s21_is_not_equal();
Suite *test_suite_s21_negate();
Suite *test_suite_s21_truncate();
Suite *test_suite_s21_round();
Suite *test_suite_s21_floor();
Suite *test_suite_s21_is_convertors();

#endif