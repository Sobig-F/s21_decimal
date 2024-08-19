#include "s21_test.h"

START_TEST(test_add_1) {
        s21_decimal number_1 = {{1245678, 0, 0, 0}};
        s21_decimal number_2 = {{2500, 0, 0, 0b100000000000000000}};
        s21_decimal dst = fill_zeroes();
        s21_decimal anticip = {{124570300, 0, 0, 0b100000000000000000}};
        int res = s21_add(number_1, number_2, &dst);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_2) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, 3, 0, 0}};
    s21_decimal number_2 = {{0, 4, 0, 0}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {{S21_MAX_UNSIGNED, 7, 0, 0}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_3) {
    s21_decimal number_1 = {
            {S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 1, 0b10000000000010000000000000000000}};
    s21_decimal number_2 = {{12500, 0, 0, SIGN_SET}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {{0b00001001110011100101001111111111,
                            0b00000000000000000000000100100011, 2,
                            0b10000000000010000000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_4) {
    s21_decimal number_1 = {{1, 1, 1, 0b10000000000000000000}};
    s21_decimal number_2 = {{1, 1, 1, 0b110000000000000000}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {
            {0b00000000000000011000011010100001, 0b00000000000000011000011010100001,
             0b00000000000000011000011010100001, 0b10000000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_5) {
    s21_decimal number_1 = {{1, 1, 1, 0b10000000000000000000}};
    s21_decimal number_2 = fill_zeroes();
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {{1, 1, 1, 0b10000000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_6) {
    s21_decimal number_1 = fill_zeroes();
    s21_decimal number_2 = {{1, 1, 1, 0b10000000000000000000}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {{1, 1, 1, 0b10000000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_7) {
    s21_decimal number_1 = {{0, 0, 0, SIGN_SET}};
    s21_decimal number_2 = {{1, 1, 1, 0b10000000000000000000}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {{1, 1, 1, 0b10000000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_8) {
    s21_decimal number_1 = {{1, 1, 1, 0b10000000000000000000}};
    s21_decimal number_2 = {{0, 0, 0, SIGN_SET}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {{1, 1, 1, 0b10000000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_9) {
    s21_decimal number_1 = fill_zeroes();
    s21_decimal number_2 = {{0, 0, 0, SIGN_SET}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = fill_zeroes();
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_10) {
    s21_decimal number_1 = {{0b00000011110100111001011000010110,
                             0b00100000011000111010010111000010,
                             0b00000000111101001101011111110001, 0}};
    s21_decimal number_2 = {{0b11111101010101111101001010001101, 12, 0, 0}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {{0b00000001001010110110100010100011,
                            0b00100000011000111010010111001111,
                            0b111101001101011111110001, 0}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);

    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_11) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0}};
    s21_decimal number_2 = {{1, 0, 0, 0}};
    s21_decimal dst = fill_zeroes();
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_add_12) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, SIGN_SET}};
    s21_decimal number_2 = {{1, 0, 0, SIGN_SET}};
    s21_decimal dst = fill_zeroes();
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(test_add_13) {
    s21_decimal number_1 = {{0b01011110011100001011100101111111,
                             0b01010000010111001100100100001100,
                             0b1110011110011011101011, 0b1110000000000000000}};
    s21_decimal number_2 = {{0b00000011100111100110111100010010,
                             0b01011010010111110001111111001110, 5,
                             0b10000000000100110000000000000000}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {
            {0b11101010101000010001101111001100, 0b11101010011100010101100000111001,
             0b11100010001011100000011100110001, 0b10100000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST


START_TEST(test_add_14) {
    s21_decimal number_1 = {{0b00011010000100110000001000001001,
                             0b01111000111001011010000011010011, 0b1000010110111,
                             SIGN_SET}};
    s21_decimal number_2 = {{0b11001001001000010101000011101011,
                             0b01000010110010001000001101001101,
                             0b1001001111101101, 0b11110000000000000000}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {
            {0b01001101001000111100111100111001, 0b11011001001110101010110101000101,
             0b11111111000100111001000001111101, 0b10000000000001100000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_15) {
    s21_decimal number_1 = {
            {0b10010110001101111000000001010010, 0b11010000010000011000000000101110,
             0b101011011101101001110111011011, 0b10000000000000000000}};
    s21_decimal number_2 = {{0b01011001101101100110100111101101,
                             0b1001100010100111010011100111011, 0,
                             0b10000000000010100000000000000000}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {
            {0b01101110111010110110111111100111, 0b11001111011111100001101010101011,
             0b101011011101101001110111011011, 0b10000000000000000000}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

START_TEST(test_add_16) {
    s21_decimal number_1 = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0}};
    s21_decimal number_2 = {
            {0b10000111111111111111111111111111, 0b00011111000100101000000100110000,
             0b10000001001111110011100101111, 0b111000000000000000000}};
    s21_decimal dst = fill_zeroes();
    s21_decimal anticip = {{S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, S21_MAX_UNSIGNED, 0}};
    int res = s21_add(number_1, number_2, &dst);
    ck_assert_int_eq(res, 0);
    for (int i = 0; i < 4; i++) ck_assert_uint_eq(dst.bits[i], anticip.bits[i]);
}
END_TEST

        Suite *test_suite_s21_is_add() {
    Suite *s = suite_create("s21_add");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_add_1);
    tcase_add_test(tc_core, test_add_2);
    tcase_add_test(tc_core, test_add_3);
    tcase_add_test(tc_core, test_add_4);
    tcase_add_test(tc_core, test_add_5);
    tcase_add_test(tc_core, test_add_6);
    tcase_add_test(tc_core, test_add_7);
    tcase_add_test(tc_core, test_add_8);
    tcase_add_test(tc_core, test_add_9);
    tcase_add_test(tc_core, test_add_10);
    tcase_add_test(tc_core, test_add_11);
    tcase_add_test(tc_core, test_add_12);
    tcase_add_test(tc_core, test_add_13);
    tcase_add_test(tc_core, test_add_14);
    tcase_add_test(tc_core, test_add_15);
    tcase_add_test(tc_core, test_add_16);
    suite_add_tcase(s, tc_core);

    return s;
}
