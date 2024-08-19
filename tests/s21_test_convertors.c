#include "s21_test.h"

// START_TEST(s21_from_int_to_decimal1) {
//         int number = -2147483648;
//         int result = s21_from_int_to_decimal(number, NULL);
//         ck_assert_int_eq(result, 1);
// }
// END_TEST

START_TEST(s21_from_int_to_decimal2) {
    s21_decimal decimal_check;
    int number = -2147483648;
    int result = s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal3) {
    s21_decimal decimal_check;
    int number = -2147483647;
    int result = s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal4) {
    s21_decimal decimal_check;
    int number = 2147483647;
    int result = s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal5) {
    s21_decimal decimal_check;
    int number = 0;
    int result = s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal6) {
    int number = -2147483648;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{0x80000000, 0x0, 0x0, 0x80000000}};
    s21_from_int_to_decimal(number, &decimal_check);
    for (int i = 0; i < 4; i++) {
        ck_assert_uint_eq(decimal_check.bits[i], decimal_control.bits[i]);
    }
}
END_TEST

START_TEST(s21_from_int_to_decimal7) {
    int number = 2147483647;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{0x7FFFFFFF, 0x0, 0x0, 0x00000000}};
    s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal8) {
    int number = 0;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{0x00000000, 0x0, 0x0, 0x00000000}};
    s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal9) {
    int number = 1;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{0x00000001, 0x0, 0x0, 0x00000000}};
    s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal10) {
    int number = -1;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{0x00000001, 0x0, 0x0, 0x80000000}};
    s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal11) {
    int number = 1000;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{0x3e8, 0x0, 0x0, 0x00000000}};
    s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal1) {
    float number = -2147483648;
    int result = s21_from_float_to_decimal(number, NULL);
    ck_assert_float_eq(result, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal2) {
    s21_decimal decimal_check;
    float number = -2147483648;
    int result = s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_float_eq(result, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal3) {
    s21_decimal decimal_check;
    float number = 2147483648;
    int result = s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_float_eq(result, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal4) {
    s21_decimal decimal_check;
    float number = 0;
    int result = s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_float_eq(result, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal5) {
    s21_decimal decimal_check;
    float number = 0.00;
    int result = s21_from_int_to_decimal(number, &decimal_check);
    ck_assert_float_eq(result, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal6) {
    float number = 0;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{0x0, 0x0, 0x0, 0x0}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal7) {
    float number = -2147483648;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{0x80000000, 0x0, 0x0, 0x80000000}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal8) {
    float number = 21474836;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{21474836, 0x0, 0x0, 0x0}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal9) {
    float number = 1.515;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{1515, 0x0, 0x0, 0x30000}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal10) {
    float number = -1.515;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{1515, 0x0, 0x0, 0x80030000}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal11) {
    float number = 2.147483;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{2147483, 0x0, 0x0, 393216}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal12) {
    float number = -2.147483;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{2147483, 0x0, 0x0, 2147876864}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal13) {
    float number = 3.402823;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{3402823, 0x0, 0x0, 393216}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal14) {
    float number = -3.402823;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{3402823, 0x0, 0x0, 2147876864}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal15) {
    float number = -1.175494;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{1175494, 0x0, 0x0, 0x80060000}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal16) {
    float number = 1.175494;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{1175494, 0x0, 0x0, 393216}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_float_to_decimal17) {
    float number = 1.1754943123123;
    s21_decimal decimal_check;
    s21_decimal decimal_control = {{11754943, 0x0, 0x0, 458752}};
    s21_from_float_to_decimal(number, &decimal_check);
    ck_assert_int_eq(decimal_check.bits[0], decimal_control.bits[0]);
    ck_assert_int_eq(decimal_check.bits[1], decimal_control.bits[1]);
    ck_assert_int_eq(decimal_check.bits[2], decimal_control.bits[2]);
    ck_assert_int_eq(decimal_check.bits[3], decimal_control.bits[3]);
}
END_TEST

START_TEST(s21_from_decimal_to_int1) {
    int number_dest;
    s21_decimal decimal_source = {{0x64, 0x0, 0x0, 0x0}};
    int number_control = 100;
    s21_from_decimal_to_int(decimal_source, &number_dest);
    ck_assert_int_eq(number_dest, number_control);
}
END_TEST

START_TEST(s21_from_decimal_to_int2) {
    int number_dest;
    s21_decimal decimal_source = {{0x64, 0x0, 0x0, 0x80000000}};
    int number_control = -100;
    s21_from_decimal_to_int(decimal_source, &number_dest);
    ck_assert_int_eq(number_dest, number_control);
}
END_TEST

START_TEST(s21_from_decimal_to_int3) {
    int number_dest;
    s21_decimal decimal_source = {{0x5F7C1F3, 0x0, 0x0, 0x0}};
    int number_control = 100123123;
    s21_from_decimal_to_int(decimal_source, &number_dest);
    ck_assert_int_eq(number_dest, number_control);
}
END_TEST

START_TEST(s21_from_decimal_to_int4) {
    int number_dest;
    s21_decimal decimal_source = {{0x5F7C1F3, 0x0, 0x0, 0x80000000}};
    int number_control = -100123123;
    s21_from_decimal_to_int(decimal_source, &number_dest);
    ck_assert_int_eq(number_dest, number_control);
}
END_TEST

START_TEST(s21_from_decimal_to_int5) {
    int number_dest;
    s21_decimal decimal_source = {{0x0, 0x0, 0x0, 0x0}};
    int number_control = 0;
    s21_from_decimal_to_int(decimal_source, &number_dest);
    ck_assert_int_eq(number_dest, number_control);
}
END_TEST

START_TEST(s21_from_decimal_to_int6) {
    int number_dest;
    s21_decimal decimal_source = {{0x5F7C1F3, 0x0, 0x0, 393216}};
    int number_control = 100;
    s21_from_decimal_to_int(decimal_source, &number_dest);
    ck_assert_int_eq(number_dest, number_control);
}
END_TEST

START_TEST(s21_from_decimal_to_int7) {
    int number_dest;
    s21_decimal decimal_source = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};
    int number_control = -2147483647;
    s21_from_decimal_to_int(decimal_source, &number_dest);
    ck_assert_int_eq(number_dest, number_control);
}
END_TEST

START_TEST(s21_from_decimal_to_int8) {
    int number_dest;
    s21_decimal decimal_source = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
    int number_control = 2147483647;
    s21_from_decimal_to_int(decimal_source, &number_dest);
    ck_assert_int_eq(number_dest, number_control);
}
END_TEST

START_TEST(s21_from_decimal_to_float1) {
    float dst = 0;
    s21_decimal src = {{0b1101001010100101111000, 0, 0, 0b00000000000001010000000000000000}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = 34.512562;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float2) {
    float dst = 0;
    s21_decimal src = {{0b1101110111010101, 0, 0, 0b1000000000000000000}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = 5.6789;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float3) {
    float dst = 0;
    s21_decimal src = {{0b1010011101000001100, 0, 0, 0b10000000000001000000000000000000}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = -34.254002;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float4) {
    float dst = 0;
    s21_decimal src = {{0, 0, 0, 0}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = 0;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float5) {
    float dst = 0;
    s21_decimal src = {{0, 0, 0, SIGN_SET}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = -0;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float6) {
    float dst = 0;
    s21_decimal src = {{0b11111111111111111111111111111111,
                        0b11111111111111111111111111111111,
                        0b11111111111111111111111111111111, 0}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = 79228162514264337593543950336.0;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float7) {
    float dst = 0;
    s21_decimal src = {{0b11111111111111111111111111111111,
                        0b11111111111111111111111111111111,
                        0b11111111111111111111111111111111, SIGN_SET}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = -79228162514264337593543950336.0;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float8) {
    float dst = 0;
    s21_decimal src = {{0, 0, 0b10000000000000000000000000000000, 0}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = 39614081257132168796771975168.0;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float9) {
    float dst = 0;
    s21_decimal src = {{0b10000100001000110000111111001111,
                        0b10101100010001110001101101000111, 0b1010011111000101,
                        0b00000000000100110000000000000000}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = 79228.1625142643375935439;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float10) {
    float dst = 0;
    s21_decimal src = {{0b10000100001000110000111111001111,
                        0b10101100010001110001101101000111, 0b1010011111000101,
                        0b10000000000100110000000000000000}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = -79228.1625142643375935439;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float11) {
    float dst = 0;
    s21_decimal src = {{1, 0, 0, 0b111000000000000000000}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = 0.0000000000000000000000000001;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST

START_TEST(s21_from_decimal_to_float12) {
    float dst = 0;
    s21_decimal src = {{5467, 0, 0, 0b111000000000000000000}};
    int res = s21_from_decimal_to_float(src, &dst);
    float number_control = 0.0000000000000000000000005467;
    ck_assert_int_eq(res, 0);
    ck_assert_float_eq(number_control, dst);
}
END_TEST


        Suite *test_suite_s21_is_convertors() {
    Suite *s = suite_create("s21_convertors");
    TCase *tc_core = tcase_create("Core");
    
// tcase_add_test(tc_core, s21_from_int_to_decimal1);
tcase_add_test(tc_core, s21_from_int_to_decimal2);
tcase_add_test(tc_core, s21_from_int_to_decimal3);
tcase_add_test(tc_core, s21_from_int_to_decimal4);
tcase_add_test(tc_core, s21_from_int_to_decimal5);
tcase_add_test(tc_core, s21_from_int_to_decimal6);
tcase_add_test(tc_core, s21_from_int_to_decimal7);
tcase_add_test(tc_core, s21_from_int_to_decimal8);
tcase_add_test(tc_core, s21_from_int_to_decimal9);
tcase_add_test(tc_core, s21_from_int_to_decimal10);
tcase_add_test(tc_core, s21_from_int_to_decimal11);
tcase_add_test(tc_core, s21_from_float_to_decimal1);
tcase_add_test(tc_core, s21_from_float_to_decimal2);
tcase_add_test(tc_core, s21_from_float_to_decimal3);
tcase_add_test(tc_core, s21_from_float_to_decimal4);
tcase_add_test(tc_core, s21_from_float_to_decimal5);
tcase_add_test(tc_core, s21_from_float_to_decimal6);
tcase_add_test(tc_core, s21_from_float_to_decimal7);
tcase_add_test(tc_core, s21_from_float_to_decimal8);
tcase_add_test(tc_core, s21_from_float_to_decimal9);
tcase_add_test(tc_core, s21_from_float_to_decimal10);
tcase_add_test(tc_core, s21_from_float_to_decimal11);
tcase_add_test(tc_core, s21_from_float_to_decimal12);
tcase_add_test(tc_core, s21_from_float_to_decimal13);
tcase_add_test(tc_core, s21_from_float_to_decimal14);
tcase_add_test(tc_core, s21_from_float_to_decimal15);
tcase_add_test(tc_core, s21_from_float_to_decimal16);
tcase_add_test(tc_core, s21_from_float_to_decimal17);

tcase_add_test(tc_core, s21_from_decimal_to_int1);
tcase_add_test(tc_core, s21_from_decimal_to_int2);
tcase_add_test(tc_core, s21_from_decimal_to_int3);
tcase_add_test(tc_core, s21_from_decimal_to_int4);
tcase_add_test(tc_core, s21_from_decimal_to_int5);
tcase_add_test(tc_core, s21_from_decimal_to_int6);
tcase_add_test(tc_core, s21_from_decimal_to_int7);
tcase_add_test(tc_core, s21_from_decimal_to_int8);

tcase_add_test(tc_core, s21_from_decimal_to_float1);
tcase_add_test(tc_core, s21_from_decimal_to_float2);
tcase_add_test(tc_core, s21_from_decimal_to_float3);
tcase_add_test(tc_core, s21_from_decimal_to_float4);
tcase_add_test(tc_core, s21_from_decimal_to_float5);
tcase_add_test(tc_core, s21_from_decimal_to_float6);
tcase_add_test(tc_core, s21_from_decimal_to_float7);
tcase_add_test(tc_core, s21_from_decimal_to_float8);
tcase_add_test(tc_core, s21_from_decimal_to_float9);
tcase_add_test(tc_core, s21_from_decimal_to_float10);
tcase_add_test(tc_core, s21_from_decimal_to_float11);
tcase_add_test(tc_core, s21_from_decimal_to_float12);



suite_add_tcase(s, tc_core);

    return s;
}
