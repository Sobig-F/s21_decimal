#include "s21_test.h"

START_TEST(test_truncate1) {
        // 79228162514264337593543950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        s21_decimal result;

        int success = s21_truncate(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_truncate2) {
    // -79228162514264337593543950335
    s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    // -79228162514264337593543950335
    s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_truncate3) {
    s21_decimal number = {{0x9B, 0x0, 0x0, 0x10000}};
    s21_decimal check = {{0xF, 0x0, 0x0, 0x0}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
//    ck_assert_mem_eq(&result, &check, sizeof(s21_decimal));
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_truncate4) {
    // -7922816251426433759354395033.5
    s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
    // -7922816251426433759354395033
    s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST



START_TEST(test_truncate5) {
    // 7922816251426433759354395033,5
    s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
    // 7922816251426433759354395033
    s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_truncate6) {
    // 7922816251426433759354395.0335
    s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
    // 7922816251426433759354395
    s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST


START_TEST(test_truncate7) {
    // -36.336660274741248
    s21_decimal number = {{0x0, 0x811800, 0x0, 0x800F0000}};
    // -36
    s21_decimal check = {{0x24, 0x0, 0x0, 0x80000000}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
//    ck_assert_mem_eq(&result, &check, sizeof(s21_decimal));
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_truncate8) {
    // 792281625142.64337593543950335
    s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
    // 792281625142
    s21_decimal check = {{0x77AA3236, 0xB8, 0x0, 0x0}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_truncate9) {
    // -9808310768275773633671140903
    s21_decimal number = {{0xB3231627, 0x2B3B9762, 0x1FB13E98, 0x80000000}};
    // -9808310768275773633671140903
    s21_decimal check = {{0xB3231627, 0x2B3B9762, 0x1FB13E98, 0x80000000}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_truncate10) {
    // -285.75367348799914688751734686
    s21_decimal number = {{0x8BFA0F9E, 0xF4FEA973, 0x5C54FD67, 0x801A0000}};
    // -285
    s21_decimal check = {{0x11D, 0x0, 0x0, 0x80000000}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

// START_TEST(test_truncate11) {
//     s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//     int success =  s21_truncate(number, NULL);
//     ck_assert_int_eq(success, 1);
// }
// END_TEST

START_TEST(test_truncate12) {
    // -0.00000000
    s21_decimal number = {{0x0, 0x0, 0x0, 0x800E0000}};
    // -0
    s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_truncate13) {
    // 0.0000000000000000000000000001
    s21_decimal number = {{0x1, 0x0, 0x0, 0x1C0000}};
    // 0
    s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
    s21_decimal result;

    int success = s21_truncate(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

        Suite *test_suite_s21_truncate() {
    Suite *s = suite_create("s21_truncate");
    TCase *tc_core = tcase_create("Core");


    tcase_add_test(tc_core, test_truncate1);
    tcase_add_test(tc_core, test_truncate2);
    tcase_add_test(tc_core, test_truncate3);
    tcase_add_test(tc_core, test_truncate4);
    tcase_add_test(tc_core, test_truncate5);
    tcase_add_test(tc_core, test_truncate6);
    tcase_add_test(tc_core, test_truncate7);
    tcase_add_test(tc_core, test_truncate8);
    tcase_add_test(tc_core, test_truncate9);
    tcase_add_test(tc_core, test_truncate10);
    // tcase_add_test(tc_core, test_truncate11);
    tcase_add_test(tc_core, test_truncate12);
    tcase_add_test(tc_core, test_truncate13);

    suite_add_tcase(s, tc_core);

    return s;
}