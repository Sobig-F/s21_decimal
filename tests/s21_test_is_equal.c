#include "s21_test.h"

void test_is_equal(s21_decimal number1, s21_decimal number2, int expected) {
    int result = s21_is_equal(number1, number2);
    ck_assert_msg(result == expected, "Comparison result is %d, expected %d", result, expected);
}

START_TEST(test_is_equal1) {
        // 79228162514264337593543950335
        s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 79228162514264337593543950335
        s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        int check = S21_COMPARISON_TRUE;

        test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal2) {
    // -7922816251426433759354395034
    s21_decimal number1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
    // -5281877500950955839569596689.0
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal3) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal4) {
    // -79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal5) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // 52818775009509558395695966890
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal6) {
    // 52818775009509558395695966890
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal7) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -52818775009509558395695966890
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal8) {
    // -52818775009509558395695966890
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal9) {
    // -79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // -79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    int check = S21_COMPARISON_TRUE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal10) {
    // -5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    // -5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal11) {
    // 5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    // 5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal12) {
    // -0.0000000000000000000000000001
    s21_decimal number1 = {{0x1, 0x0, 0x0, 0x801C0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal13) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // 5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal14) {
    // 5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal15) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal16) {
    // -5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal17) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0.0000000000000000000000000001
    s21_decimal number2 = {{0x1, 0x0, 0x0, 0x801C0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal18) {
    // 0.0000000000000000000000000001
    s21_decimal number1 = {{0x1, 0x0, 0x0, 0x1C0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal19) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0.0000000000000000000000000001
    s21_decimal number2 = {{0x1, 0x0, 0x0, 0x1C0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal20) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal21) {
    // 0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x0}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal22) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal23) {
    // -0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x80000000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal24) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x800E0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal25) {
    // -0.00000000000000
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x800E0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal26) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0xE0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal27) {
    // 0.00000000000000
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0xE0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal28) {
    // -0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x80000000}};
    // 0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0xE0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal29) {
    // 0.00000000000000
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0xE0000}};
    // 0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0xE0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal30) {
    // -0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x80000000}};
    // 0
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x0}};
    int check = S21_COMPARISON_TRUE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal31) {
    // -0.0000000000000000000000000001
    s21_decimal number1 = {{0x1, 0x0, 0x0, 0x801C0000}};
    // 0
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_equal(number1, number2, check);
}
END_TEST

START_TEST(test_is_equal32) {
  s21_decimal number_1 = {{0b00000000000000000000000000000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal number_2 = {{0b00000000000000000000000000000000, 0, 0, 0b10000000000000000000000000000000}};
  int res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_equal33) {
  s21_decimal number_1 = {{0b00000000000000000000000000000001, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal number_2 = {{0b00000000000000000000000000000000, 0, 0, 0b00000000000000000000000000000000}};
  int res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal34) {
  s21_decimal number_1 = {{0b00000000000000000000000010111011, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal number_2 = {{0b10000000000000110000000000000000, 0, 0, 0b00000000000000000000000000000000}};
 int  res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal35) {
  s21_decimal number_1 = {
      {2147483647, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal number_2 = {
      {2147483647, 0, 0, 0b00000000000000000000000000000000}};
  int res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_equal36) {
  s21_decimal number_1 = {
      {0b10000000000000000000000010111011, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal number_2 = {
      {0b10000000000000000000000010111011, 0, 0, 0b00000000000000000000000000000000}};
  int res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_equal37) {
  s21_decimal number_1 = {
      {0b00000000000000000000000000000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal number_2 = {
      {0b00000000000000000000000000000000, 0, 0, 0b00000000000000000000000000000000}};
  int res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_equal38) {
  s21_decimal number_1 = {
      {0b00000000000000000000000111010000, 0b00000000000000000000000111010000, 0, 0b00000000000000000000000000000000}};
  s21_decimal number_2 = {
      {0b00000000000000000001001000100111, 0, 0b00000000000000000001001000100111, 0b00000000000000000000000000000000}};
  int res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal39) {
  s21_decimal number_1 = {
      {0b00000000000000000001000111010101, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal number_2 = {
      {0b00000000000000000001000111010101, 0, 0, 0b10000000000000000000000000000000}};
  int res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal40) {
  s21_decimal number_1 = {
      {0b00000000000000000000000110000000, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal number_2 = {
      {0b00000000000000000000000110000000, 0, 0, 0b10000000000000000000000000000000}};
  int res = s21_is_equal(number_1, number_2);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *test_suite_s21_is_equal(){
Suite *s = suite_create("s21_is_equal");
TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_is_equal1);
    tcase_add_test(tc_core, test_is_equal2);
    tcase_add_test(tc_core, test_is_equal3);
    tcase_add_test(tc_core, test_is_equal4);
    tcase_add_test(tc_core, test_is_equal5);
    tcase_add_test(tc_core, test_is_equal6);
    tcase_add_test(tc_core, test_is_equal7);
    tcase_add_test(tc_core, test_is_equal8);
    tcase_add_test(tc_core, test_is_equal9);
    tcase_add_test(tc_core, test_is_equal10);
    tcase_add_test(tc_core, test_is_equal11);
    tcase_add_test(tc_core, test_is_equal12);
    tcase_add_test(tc_core, test_is_equal13);
    tcase_add_test(tc_core, test_is_equal14);
    tcase_add_test(tc_core, test_is_equal15);
    tcase_add_test(tc_core, test_is_equal16);
    tcase_add_test(tc_core, test_is_equal17);
    tcase_add_test(tc_core, test_is_equal18);
    tcase_add_test(tc_core, test_is_equal19);
    tcase_add_test(tc_core, test_is_equal20);
    tcase_add_test(tc_core, test_is_equal21);
    tcase_add_test(tc_core, test_is_equal22);
    tcase_add_test(tc_core, test_is_equal23);
    tcase_add_test(tc_core, test_is_equal24);
    tcase_add_test(tc_core, test_is_equal25);
    tcase_add_test(tc_core, test_is_equal26);
    tcase_add_test(tc_core, test_is_equal27);
    tcase_add_test(tc_core, test_is_equal28);
    tcase_add_test(tc_core, test_is_equal29);
    tcase_add_test(tc_core, test_is_equal30);
    tcase_add_test(tc_core, test_is_equal31);
    tcase_add_test(tc_core, test_is_equal32); 
    tcase_add_test(tc_core, test_is_equal33);
    tcase_add_test(tc_core, test_is_equal34);
    tcase_add_test(tc_core, test_is_equal35);
    tcase_add_test(tc_core, test_is_equal36);
    tcase_add_test(tc_core, test_is_equal37);
    tcase_add_test(tc_core, test_is_equal38);
    tcase_add_test(tc_core, test_is_equal39);
    tcase_add_test(tc_core, test_is_equal40);
    
    suite_add_tcase(s, tc_core);

  return s;
}
