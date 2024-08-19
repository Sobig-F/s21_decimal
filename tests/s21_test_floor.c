#include "s21_test.h"

// START_TEST(test_floor1) {
//         // 792281625.14264337593543950335
//         s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

//         int result = s21_floor(number, NULL);

//         ck_assert_int_eq(result, S21_ERROR);
// }
// END_TEST


START_TEST(test_floor2) {
        // 79228162514264337593543950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor3) {
        // -79228162514264337593543950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
        // -79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor4) {
        // 7922816251426433759354395033.5
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
        // 7922816251426433759354395033
        s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor5) {
        // -7922816251426433759354395033.5
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
        // -7922816251426433759354395034
        s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor6) {
        // 79228162514264337593543.950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
        // 79228162514264337593543
        s21_decimal check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor7) {
        // -79228162514264337593543.950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
        // -79228162514264337593544
        s21_decimal check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor8) {
        // 7.9228162514264337593543950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
        // 7
        s21_decimal check = {{0x7, 0x0, 0x0, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor9) {
        // -7.9228162514264337593543950335
        s21_decimal number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
        // -8
        s21_decimal check = {{0x8, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor10) {
        // 0.99999999999999999999
        s21_decimal number = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor11) {
        // -0.99999999999999999999
        s21_decimal number = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
        // -1
        s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor12) {
        // -0
        s21_decimal number = {{0x0, 0x0, 0x0, 0x80000000}};
        // -0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor13) {
        // 0
        s21_decimal number = {{0x0, 0x0, 0x0, 0x0}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor14) {
        // -0.0
        s21_decimal number = {{0x0, 0x0, 0x0, 0x80010000}};
        // -0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor15) {
        // 0.0
        s21_decimal number = {{0x0, 0x0, 0x0, 0x10000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor16) {
        // -0.00
        s21_decimal number = {{0x0, 0x0, 0x0, 0x80020000}};
        // -0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor17) {
        // 0.00
        s21_decimal number = {{0x0, 0x0, 0x0, 0x20000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor18) {
        // 0.000000000000000000000000000
        s21_decimal number = {{0x0, 0x0, 0x0, 0x1B0000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor19) {
        // -0.0000000000000000000000000000
        s21_decimal number = {{0x0, 0x0, 0x0, 0x801C0000}};
        // -0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor20) {
        // -2822114502781.064017994064325
        s21_decimal number = {{0x32B821C5, 0xBEF38F7A, 0x91E65FD, 0x800F0000}};
        // -2822114502782
        s21_decimal check = {{0x1321E87E, 0x291, 0x0, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor21) {
        // 2822114502781.064017994064325
        s21_decimal number = {{0x32B821C5, 0xBEF38F7A, 0x91E65FD, 0xF0000}};
        // 2822114502781
        s21_decimal check = {{0x1321E87D, 0x291, 0x0, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor22) {
        // -19652085016446477268462.30948
        s21_decimal number = {{0x71A2C1A4, 0x57EFFA09, 0x6599516, 0x80050000}};
        // -19652085016446477268463
        s21_decimal check = {{0xCCE7F5EF, 0x5777413F, 0x429, 0x80000000}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_floor23) {
        // 19652085016446477268462.30948
        s21_decimal number = {{0x71A2C1A4, 0x57EFFA09, 0x6599516, 0x50000}};
        // 19652085016446477268462
        s21_decimal check = {{0xCCE7F5EE, 0x5777413F, 0x429, 0x0}};

        s21_decimal result;
        int success = s21_floor(number, &result);
        ck_assert_int_eq(success, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

Suite *test_suite_s21_floor() {
    Suite *s = suite_create("s21_floor");
    TCase *tc_core = tcase_create("Core");


//     tcase_add_test(tc_core, test_floor1);
    tcase_add_test(tc_core, test_floor2);
    tcase_add_test(tc_core, test_floor3);
    tcase_add_test(tc_core, test_floor4);
    tcase_add_test(tc_core, test_floor5);
    tcase_add_test(tc_core, test_floor6);
    tcase_add_test(tc_core, test_floor7);
    tcase_add_test(tc_core, test_floor8);
    tcase_add_test(tc_core, test_floor9);
    tcase_add_test(tc_core, test_floor10);
    tcase_add_test(tc_core, test_floor11);
    tcase_add_test(tc_core, test_floor12);
    tcase_add_test(tc_core, test_floor13);
    tcase_add_test(tc_core, test_floor14);
    tcase_add_test(tc_core, test_floor15);
    tcase_add_test(tc_core, test_floor16);
    tcase_add_test(tc_core, test_floor17);
    tcase_add_test(tc_core, test_floor18);
    tcase_add_test(tc_core, test_floor19);
    tcase_add_test(tc_core, test_floor20);
    tcase_add_test(tc_core, test_floor21);
    tcase_add_test(tc_core, test_floor22);
    tcase_add_test(tc_core, test_floor23);

    suite_add_tcase(s, tc_core);

    return s;
}