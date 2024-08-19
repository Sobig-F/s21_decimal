#include "s21_test.h"

// START_TEST(test_round1) {
//         // 792281625.14264337593543950335
//         s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

//         int result = s21_round(number, NULL);

//         ck_assert_int_eq(result, S21_ERROR);
// }
// END_TEST

START_TEST(test_round2) {
    // 79228162514264337593543950335
    s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // 79228162514264337593543950335
    s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

    s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round3) {
        // -79228162514264337593543950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
        // -79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round4) {
        // 7922816251426433759354395033.5
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
        // 7922816251426433759354395034
        s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

        s21_decimal result;
    int success = s21_round(number, &result);
    //printf("Number 1: bits[0]=%d, bits[1]=%d, bits[2]=%d, bits[3]=%d\n", result.bits[0], result.bits[1], result.bits[2], result.bits[3]);
    //printf("Number 2: bits[0]=%d, bits[1]=%d, bits[2]=%d, bits[3]=%d\n", check.bits[0], check.bits[1], check.bits[2], check.bits[3]);
    //printf("Должно быть!!!\n");
    //print_dec(check);
    //printf("\n\n");
    ck_assert_int_eq(success, 0);

    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);

}
END_TEST

START_TEST(test_round5) {
        // -7922816251426433759354395033.5
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
        // -7922816251426433759354395034
        s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

        s21_decimal result;
    int success = s21_round(number, &result);
    //printf("Должно быть!!!\n");
    //print_dec(check);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round6) {
        // 1560647675258760.35030685696
        s21_decimal number = {{0x811800, 0x0, 0x811800, 0xB0000}};
        // 1560647675258760
        s21_decimal check = {{0x9A4DA788, 0x58B66, 0x0, 0x0}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round7) {
        // -1560647675258760.35030685696
        s21_decimal number = {{0x811800, 0x0, 0x811800, 0x800B0000}};
        // -1560647675258760
        s21_decimal check = {{0x9A4DA788, 0x58B66, 0x0, 0x80000000}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round8) {
        // 1.56064767525876035030685696
        s21_decimal number = {{0x811800, 0x0, 0x811800, 0x1A0000}};
        // 2
        s21_decimal check = {{0x2, 0x0, 0x0, 0x0}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round9) {
        // -1.56064767525876035030685696
        s21_decimal number = {{0x811800, 0x0, 0x811800, 0x801A0000}};
        // -2
        s21_decimal check = {{0x2, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round10) {
        // 15606476.7525876035022225408
        s21_decimal number = {{0x0, 0x0, 0x811800, 0x130000}};
        // 15606477
        s21_decimal check = {{0xEE22CD, 0x0, 0x0, 0x0}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round11) {
        // 3.6336660274741248
        s21_decimal number = {{0x0, 0x811800, 0x0, 0x100000}};
        // 4
        s21_decimal check = {{0x4, 0x0, 0x0, 0x0}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round12) {
        // -84602.88
        s21_decimal number = {{0x811800, 0x0, 0x0, 0x80020000}};
        // -84603
        s21_decimal check = {{0x14A7B, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round13) {
        // 132.34064752933837659118932036
        s21_decimal number = {{0x8D6A9044, 0xCC179DE7, 0x2AC2F637, 0x1A0000}};
        // 132
        s21_decimal check = {{0x84, 0x0, 0x0, 0x0}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round14) {
        // -132.34064752933837659118932036
        s21_decimal number = {{0x8D6A9044, 0xCC179DE7, 0x2AC2F637, 0x801A0000}};
        // -132
        s21_decimal check = {{0x84, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round15) {
        // -0.0000000000001
        s21_decimal number = {{0x1, 0x0, 0x0, 0x800D0000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_round16) {
        // 0.00000000000001
        s21_decimal number = {{0x1, 0x0, 0x0, 0xE0000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result;
    int success = s21_round(number, &result);
    ck_assert_int_eq(success, 0);
    for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST


        Suite *test_suite_s21_round() {
    Suite *s = suite_create("s21_round");
    TCase *tc_core = tcase_create("Core");


    // tcase_add_test(tc_core, test_round1);
    tcase_add_test(tc_core, test_round2);
    tcase_add_test(tc_core, test_round3);
    tcase_add_test(tc_core, test_round4);
    tcase_add_test(tc_core, test_round5);
    tcase_add_test(tc_core, test_round6);
    tcase_add_test(tc_core, test_round7);
    tcase_add_test(tc_core, test_round8);
    tcase_add_test(tc_core, test_round9);
    tcase_add_test(tc_core, test_round10);
    tcase_add_test(tc_core, test_round11);
    tcase_add_test(tc_core, test_round12);
    tcase_add_test(tc_core, test_round13);
    tcase_add_test(tc_core, test_round14);
    tcase_add_test(tc_core, test_round15);
    tcase_add_test(tc_core, test_round16);

    suite_add_tcase(s, tc_core);

    return s;
}