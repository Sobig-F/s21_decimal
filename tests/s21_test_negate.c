#include "s21_test.h"

START_TEST(test_negate1) {
        // -79228162514264337593543950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
        // 79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate2) {
        // 79228162514264337593543950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // -79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate3) {
        // 0.0000000000000000000000000001
        s21_decimal number = {{0x1, 0x0, 0x0, 0x1C0000}};
        // -0.0000000000000000000000000001
        s21_decimal check = {{0x1, 0x0, 0x0, 0x801C0000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate4) {
        // -0.0000000000000000000000000001
        s21_decimal number = {{0x1, 0x0, 0x0, 0x801C0000}};
        // 0.0000000000000000000000000001
        s21_decimal check = {{0x1, 0x0, 0x0, 0x1C0000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate5) {
        s21_decimal number = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
        s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate6) {
        s21_decimal number = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
        s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate7) {
        s21_decimal number = {{0x0, 0x0, 0x0, 0x800E0000}};
        s21_decimal check = {{0x0, 0x0, 0x0, 0xE0000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate8) {
        s21_decimal number = {{0x0, 0x0, 0x0, 0xE0000}};
        s21_decimal check = {{0x0, 0x0, 0x0, 0x800E0000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate9) {
        // -5.2818775009509558392832655360
        s21_decimal number = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
        // 5.2818775009509558392832655360
        s21_decimal check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate10) {
        // 5.2818775009509558392832655360
        s21_decimal number = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
        // -5.2818775009509558392832655360
        s21_decimal check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate11) {
        // 2640938750475477.9197847983445
        s21_decimal number = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};
        // -2640938750475477.9197847983445
        s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x800D0000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_negate12) {
        // -2640938750475477.9197847983445
        s21_decimal number = {{0x55555555, 0x55555555, 0x55555555, 0x800D0000}};
        // 2640938750475477.9197847983445
        s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};
        s21_decimal result;

        int success = s21_negate(number,  &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

// START_TEST(test_negate13) {
//         s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

//         int success = s21_negate(number,  NULL);
//         ck_assert_int_eq(success, 1);
// }
// END_TEST

START_TEST(test_negate14) {
  s21_decimal value = {{0b00000000000000000000000000000100, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_negate(value, &result);
  int sign1 = get_dec_bit(value, 128), sign2 = get_dec_bit(result, 128);;;
  for(int i = 0; i < 3; i++)
  ck_assert_int_eq(value.bits[i], result.bits[i]);
  ck_assert_int_eq(sign1, !sign2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_negate15) {
  s21_decimal value = {{2147483647, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_negate(value, &result);
  int sign1 = get_dec_bit(value, 128), sign2 = get_dec_bit(result, 128);;
  for(int i = 0; i < 3; i++)
  ck_assert_int_eq(value.bits[i], result.bits[i]);
  ck_assert_int_eq(sign1, !sign2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_negate16) {
  s21_decimal value = {{0b00000000000000000000000000110000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_negate(value, &result);
  int sign1 = get_dec_bit(value, 128), sign2 = get_dec_bit(result, 128);;
  for(int i = 0; i < 3; i++)
  ck_assert_int_eq(value.bits[i], result.bits[i]);
  ck_assert_int_eq(sign1, !sign2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_negate17) {
  s21_decimal value = {{0b00000000000000000000000000000000, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_negate(value, &result);
  int sign1 = get_dec_bit(value, 128), sign2 = get_dec_bit(result, 128);;
  for(int i = 0; i < 3; i++)
  ck_assert_int_eq(value.bits[i], result.bits[i]);
  ck_assert_int_eq(sign1, !sign2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_negate18) {
  s21_decimal value = {{0b00000000000000000001000111010101, 0, 0, 0b10000000000000100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_negate(value, &result);
  int sign1 = get_dec_bit(value, 128), sign2 = get_dec_bit(result, 128);
  for(int i = 0; i < 3; i++)
  ck_assert_int_eq(value.bits[i], result.bits[i]);
  ck_assert_int_eq(sign1, !sign2);
  ck_assert_int_eq(res, 0);
}
END_TEST

Suite *test_suite_s21_negate(){
Suite *s = suite_create("s21_negate");
TCase *tc_core = tcase_create("Core");


    tcase_add_test(tc_core, test_negate1);
    tcase_add_test(tc_core, test_negate2);
    tcase_add_test(tc_core, test_negate3);
    tcase_add_test(tc_core, test_negate4);
    tcase_add_test(tc_core, test_negate5);
    tcase_add_test(tc_core, test_negate6);
    tcase_add_test(tc_core, test_negate7);
    tcase_add_test(tc_core, test_negate8);
    tcase_add_test(tc_core, test_negate9);
    tcase_add_test(tc_core, test_negate10);
    tcase_add_test(tc_core, test_negate11);
    tcase_add_test(tc_core, test_negate12);
//     tcase_add_test(tc_core, test_negate13);
    tcase_add_test(tc_core, test_negate14);
    tcase_add_test(tc_core, test_negate15);
    tcase_add_test(tc_core, test_negate16);
    tcase_add_test(tc_core, test_negate17);
    tcase_add_test(tc_core, test_negate18);

    suite_add_tcase(s, tc_core);

  return s;
}
