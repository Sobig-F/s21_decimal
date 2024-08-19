#include "s21_test.h"

void test_is_less(s21_decimal number1, s21_decimal number2, int expected) {
    int result = s21_is_less(number1, number2);
    ck_assert_msg(result == expected, "Comparison result is %d, expected %d", result, expected);
}

START_TEST(test_is_less1) {
        // 79228162514264337593543950335
        s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 79228162514264337593543950335
        s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        int check = S21_COMPARISON_FALSE;

        test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less2) {
    // -7922816251426433759354395034
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // -5281877500950955839569596689.0
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less3) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less4) {
    // -79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less5) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // 52818775009509558395695966890
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less6) {
    // 52818775009509558395695966890
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less7) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -52818775009509558395695966890
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less8) {
    // -52818775009509558395695966890
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less9) {
    // -79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // -79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less10) {
    // -5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    // -5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less11) {
    // 5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    // 5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less12) {
    // -0.0000000000000000000000000001
    s21_decimal number1 = {{0x1, 0x0, 0x0, 0x801C0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less13) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // 5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less14) {
    // 5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less15) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less16) {
    // -5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less17) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0.0000000000000000000000000001
    s21_decimal number2 = {{0x1, 0x0, 0x0, 0x801C0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less18) {
    // 0.0000000000000000000000000001
    s21_decimal number1 = {{0x1, 0x0, 0x0, 0x1C0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less19) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0.0000000000000000000000000001
    s21_decimal number2 = {{0x1, 0x0, 0x0, 0x1C0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less20) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less21) {
    // 0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x0}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less22) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less23) {
    // -0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x80000000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less24) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x800E0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less25) {
    // -0.00000000000000
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x800E0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less26) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0xE0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less27) {
    // 0.00000000000000
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0xE0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less28) {
    // -0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x80000000}};
    // 0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0xE0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less29) {
    // -0
    s21_decimal number1 = {{0x1, 0x0, 0x0, 0x10000}};
    // 0.00000000000000
    s21_decimal number2 = {{0xA, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less30) {
    // -1.2297829382473034409
    s21_decimal number1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
    // -1.2297829382473034410
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less31) {
    // -1.2297829382473034410
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
    // -1.2297829382473034409
    s21_decimal number2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less32) {
    // -79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // -52818775009509558395695966890
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    int check = S21_COMPARISON_TRUE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less33) {
    // -52818775009509558395695966890
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    // -79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_less(number1, number2, check);
}
END_TEST

START_TEST(test_is_less34) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal number_2 = {{S21_MAX_UNSIGNED, 0, 0, 0b10000000000000000000000000000000}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 0);
}
END_TEST


START_TEST(test_is_less35) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal number_2 = {{S21_MAX_UNSIGNED, 0, 0, 0b10000000000000000000000000000000}};
    int res = s21_is_less(number_2, number_1);
    ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less36) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0b00000000000000000000000000000000}};
    s21_decimal number_2 = {{S21_MAX_UNSIGNED, 0, S21_MAX_UNSIGNED, 0b10000000000000000000000000000000}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 0);
}
END_TEST


START_TEST(test_is_less37) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0b00000000000000000000000000000000}};
    s21_decimal number_2 = {{S21_MAX_UNSIGNED, 0, S21_MAX_UNSIGNED, 0b10000000000000000000000000000000}};
    int res = s21_is_less(number_2, number_1);
    ck_assert_int_eq(res, 1);
}
END_TEST


START_TEST(test_is_less38) {
    s21_decimal number_1 = {{12500, 18001, 1, 0b00000000000000000000000000000000}};
    s21_decimal number_2 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0, 0b00000000000000000000000000000000}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less39) {
    s21_decimal number_1 = {{12500, 18001, 1, 0b00000000000000000000000000000000}};
    s21_decimal number_2 = {{999999, 999999, 0, 0b00000000000000000000000000000000}};
    int res = s21_is_less(number_2, number_1);
    ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less40) {
    s21_decimal number_1 = {{0, 0, 1, 0b00000000000000000000000000000000}};
    s21_decimal number_2 = {{999999, 999999, 1, 0b10000000000000000000000000000000}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less41) {
    s21_decimal number1 = {{0, 0, 1, 0b00000000000000000000000000000000}};
    s21_decimal number2 = {{999999, 999999, 1, 0b10000000000000000000000000000000}};
    int res = s21_is_less(number1, number2);
    //printf("Number 1: bits[0]=%d, bits[1]=%d, bits[2]=%d, bits[3]=%d\n", number1.bits[0], number1.bits[1], number1.bits[2], number1.bits[3]);
    //printf("Number 2: bits[0]=%d, bits[1]=%d, bits[2]=%d, bits[3]=%d\n", number2.bits[0], number2.bits[1], number2.bits[2], number2.bits[3]);

    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less42) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0b00000000000111000000000000000000}};
    s21_decimal number_2 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0b00000000000000000000000000000000}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less43) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0b00000000000111000000000000000000}};
    s21_decimal number_2 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0b00000000000111000000000000000000}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less44) {
    s21_decimal number_1 = {{0, 0, 0, 0}};
    s21_decimal number_2 = {{0, 0, 0, 0}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less45) {
    s21_decimal number_1 = {{0, 0, 0, 0b10000000000000000000000000000000}};
    s21_decimal number_2 = {{0, 0, 0, 0}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less46) {
    s21_decimal number_1 = {{0, 0, 1, 0b10000000000000000000000000000000}};
    s21_decimal number_2 = {{1, 0, 0, 0}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less47) {
    s21_decimal number_1 = {{1100, 12900, 5000, 0b10000000000011000000000000000000}};
    s21_decimal number_2 = {{1100, 12900, 5000, 0b10000000000010010000000000000000}};
    int res = s21_is_less(number_2, number_1);
    ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less48) {
    s21_decimal number_1 = {{1100, 12900, 5000, 0b00000000000011000000000000000000}};
    s21_decimal number_2 = {{1100, 12900, 5000, 0b00000000000010010000000000000000}};
    int res = s21_is_less(number_1, number_2);
    ck_assert_int_eq(res, 1);
}
END_TEST

Suite *test_suite_s21_is_less(){
Suite *s = suite_create("s21_is_less");
TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_is_less1);
  tcase_add_test(tc_core, test_is_less2);
  tcase_add_test(tc_core, test_is_less3);
  tcase_add_test(tc_core, test_is_less4);
  tcase_add_test(tc_core, test_is_less5);
  tcase_add_test(tc_core, test_is_less6);
  tcase_add_test(tc_core, test_is_less7);
  tcase_add_test(tc_core, test_is_less8);
  tcase_add_test(tc_core, test_is_less9);
  tcase_add_test(tc_core, test_is_less10);
  tcase_add_test(tc_core, test_is_less11);
  tcase_add_test(tc_core, test_is_less12);
  tcase_add_test(tc_core, test_is_less13);
  tcase_add_test(tc_core, test_is_less14);
  tcase_add_test(tc_core, test_is_less15);
  tcase_add_test(tc_core, test_is_less16);
  tcase_add_test(tc_core, test_is_less17);
  tcase_add_test(tc_core, test_is_less18);
  tcase_add_test(tc_core, test_is_less19);
  tcase_add_test(tc_core, test_is_less20);
  tcase_add_test(tc_core, test_is_less21);
  tcase_add_test(tc_core, test_is_less22);
  tcase_add_test(tc_core, test_is_less23);
  tcase_add_test(tc_core, test_is_less24);
  tcase_add_test(tc_core, test_is_less25);
  tcase_add_test(tc_core, test_is_less26);
  tcase_add_test(tc_core, test_is_less27);
  tcase_add_test(tc_core, test_is_less28);
  tcase_add_test(tc_core, test_is_less29);
  tcase_add_test(tc_core, test_is_less30);
  tcase_add_test(tc_core, test_is_less31);
  tcase_add_test(tc_core, test_is_less32);
  tcase_add_test(tc_core, test_is_less33);
  tcase_add_test(tc_core, test_is_less34);
  tcase_add_test(tc_core, test_is_less35);
  tcase_add_test(tc_core, test_is_less36);
  tcase_add_test(tc_core, test_is_less37);
  tcase_add_test(tc_core, test_is_less38);
  tcase_add_test(tc_core, test_is_less39);
  tcase_add_test(tc_core, test_is_less40);
  tcase_add_test(tc_core, test_is_less41);
  tcase_add_test(tc_core, test_is_less42);
  tcase_add_test(tc_core, test_is_less43);
  tcase_add_test(tc_core, test_is_less44);
  tcase_add_test(tc_core, test_is_less45);
  tcase_add_test(tc_core, test_is_less46);
  tcase_add_test(tc_core, test_is_less47);
  tcase_add_test(tc_core, test_is_less48);
  suite_add_tcase(s, tc_core);

  return s;
}