#include "s21_test.h"

void test_is_greater(s21_decimal number1, s21_decimal number2, int expected) {
    int result = s21_is_greater(number1, number2);
    ck_assert_msg(result == expected, "Comparison result is %d, expected %d", result, expected);
}

START_TEST(test_is_greater1) {
        // 79228162514264337593543950335
        s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 79228162514264337593543950335
        s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        int check = S21_COMPARISON_FALSE;

        test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater2) {
    // -7922816251426433759354395034
    s21_decimal number1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
    // -5281877500950955839569596689.0
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater3) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater4) {
    // -79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater5) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // 52818775009509558395695966890
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater6) {
    // 52818775009509558395695966890
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater7) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -52818775009509558395695966890
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST( test_is_greater8) {
    // -52818775009509558395695966890
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater9) {
    // -79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // -79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater10) {
    // -5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    // -5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater11) {
    // 5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    // 5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater12) {
    // -0.0000000000000000000000000001
    s21_decimal number1 = {{0x1, 0x0, 0x0, 0x801C0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater13) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // 5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater14) {
    // 5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater15) {
    // 79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // -5.281877500950955839569596690
    s21_decimal number2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater16) {
    // -5.281877500950955839569596690
    s21_decimal number1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
    // 79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater17) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0.0000000000000000000000000001
    s21_decimal number2 = {{0x1, 0x0, 0x0, 0x801C0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater18) {
    // 0.0000000000000000000000000001
    s21_decimal number1 = {{0x1, 0x0, 0x0, 0x1C0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater19) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0.0000000000000000000000000001
    s21_decimal number2 = {{0x1, 0x0, 0x0, 0x1C0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater20) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x0}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater21) {
    // 0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x0}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater22) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x80000000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater23) {
    // -0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x80000000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater24) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // -0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0x800E0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater25) {
    // -0.00000000000000
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x800E0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater26) {
    // 1.22
    s21_decimal number1 = {{0x7A, 0x0, 0x0, 0x20000}};
    // 0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0xE0000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater27) {
    // 0.00000000000000
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0xE0000}};
    // 1.22
    s21_decimal number2 = {{0x7A, 0x0, 0x0, 0x20000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater28) {
    // -0
    s21_decimal number1 = {{0x0, 0x0, 0x0, 0x80000000}};
    // 0.00000000000000
    s21_decimal number2 = {{0x0, 0x0, 0x0, 0xE0000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater29) {
    // -79228162514264337593543950335
    s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // -52818775009509558395695966890
    s21_decimal number2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    int check = S21_COMPARISON_FALSE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater30) {
    // -52818775009509558395695966890
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
    // -79228162514264337593543950335
    s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

START_TEST(test_is_greater31) {
    // -5281877500950955839569596689.0
    s21_decimal number1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
    // -7922816251426433759354395034
    s21_decimal number2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
    int check = S21_COMPARISON_TRUE;

    test_is_greater(number1, number2, check);
}
END_TEST

Suite *test_suite_s21_is_greater(){
    Suite *s = suite_create("s21_is_greater");
    TCase *tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_is_greater1);
    tcase_add_test(tc_core, test_is_greater2);
    tcase_add_test(tc_core, test_is_greater3);
  tcase_add_test(tc_core, test_is_greater4);
  tcase_add_test(tc_core, test_is_greater5);
  tcase_add_test(tc_core, test_is_greater6);
  tcase_add_test(tc_core, test_is_greater7);
  tcase_add_test(tc_core, test_is_greater8);
  tcase_add_test(tc_core, test_is_greater9);
  tcase_add_test(tc_core, test_is_greater10);
  tcase_add_test(tc_core, test_is_greater11);
  tcase_add_test(tc_core, test_is_greater12);
  tcase_add_test(tc_core, test_is_greater13);
  tcase_add_test(tc_core, test_is_greater14);
  tcase_add_test(tc_core, test_is_greater15);
  tcase_add_test(tc_core, test_is_greater16);
  tcase_add_test(tc_core, test_is_greater17);
  tcase_add_test(tc_core, test_is_greater18);
  tcase_add_test(tc_core, test_is_greater19);
  tcase_add_test(tc_core, test_is_greater20);
  tcase_add_test(tc_core, test_is_greater21);
  tcase_add_test(tc_core, test_is_greater22);
  tcase_add_test(tc_core, test_is_greater23);
  tcase_add_test(tc_core, test_is_greater24);
  tcase_add_test(tc_core, test_is_greater25);
  tcase_add_test(tc_core, test_is_greater26);
  tcase_add_test(tc_core, test_is_greater27);
  tcase_add_test(tc_core, test_is_greater28);
  tcase_add_test(tc_core, test_is_greater29);
  tcase_add_test(tc_core, test_is_greater30);
  tcase_add_test(tc_core, test_is_greater31);
    
    suite_add_tcase(s, tc_core);

    return s;
}