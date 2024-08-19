#include "s21_test.h"

START_TEST(test_div1) {
        // 1.2640938749860586450804312205
        s21_decimal number_1 = {{0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000}};
        // 2
        s21_decimal number_2 = {{0x2, 0x0, 0x0, 0x0}};
        // 0.6320469374930293225402156102
        s21_decimal check = {{0x8C444446, 0x5F128130, 0x146C2B73, 0x1C0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div2) {
        // 1431655765
        s21_decimal number_1 = {{0x55555555, 0x0, 0x0, 0x0}};
        // 12.640938749860586450805
        s21_decimal number_2 = {{0x2EB3EF75, 0x4444026F, 0x2AD, 0x150000}};
        // 113255494.17884722765619814067
        s21_decimal check = {{0x6D7C5EB3, 0x2C521AF0, 0x24984660, 0x140000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div3) {
        // 1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x0}};
        // 500
        s21_decimal number_2 = {{0x1F4, 0x0, 0x0, 0x0}};
        // 0.002
        s21_decimal check = {{0x2, 0x0, 0x0, 0x30000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div4) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 7.9228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
        // 10000000000000000000000000000
        s21_decimal check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div5) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // -26409387504754779197847983445
        s21_decimal number_2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
        // -3
        s21_decimal check = {{0x3, 0x0, 0x0, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div6) {
        // -26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
        // 156064767525876035022225408
        s21_decimal number_2 = {{0x0, 0x0, 0x811800, 0x0}};
        // -169.22068909868474138626644073
        s21_decimal check = {{0x8C085869, 0xC05E68BD, 0x36AD9B79, 0x801A0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div7) {
        // -26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
        // -429496729.5
        s21_decimal number_2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
        // 61489146926681729710
        s21_decimal check = {{0xAAAAAAAE, 0x55555558, 0x3, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div8) {
        // -79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
        // 1.0000000000000000000000000001
        s21_decimal number_2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
        // -79228162514264337593543950327
        s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div9) {
        // 3.6336660283201536
        s21_decimal number_1 = {{0x811800, 0x811800, 0x0, 0x100000}};
        // 0.0000000000000000000000000001
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x1C0000}};
        // 36336660283201536000000000000
        s21_decimal check = {{0x89800000, 0xFEE8FB1C, 0x7568FB1C, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div10) {
        // 7.9228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
        // 0.0000000000000000000000000001
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x1C0000}};
        // 79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div11) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // -0
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x80000000}};
        s21_decimal result = {{0, 0, 0, 0}};
        // division by zero
        int res = s21_div(number_1, number_2, &result);

        ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(test_div12) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 0.0000000000000000000000000001
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x1C0000}};
        // overflow
        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);

        ck_assert_int_eq(res, S21_INF);
}
END_TEST

START_TEST(test_div13) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 7922816251426433759354395033.5
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
        // 10
        s21_decimal check = {{0xA, 0x0, 0x0, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div14) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // -7922816251426433759354395033.5
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
        // -10
        s21_decimal check = {{0xA, 0x0, 0x0, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div15) {
        // 42.94967296
        s21_decimal number_1 = {{0x0, 0x1, 0x0, 0x80000}};
        // 0.9999
        s21_decimal number_2 = {{0x270F, 0x0, 0x0, 0x40000}};
        // 42.953968356835683568356835684
        s21_decimal check = {{0x199A4164, 0x77BE0268, 0x8ACAB09A, 0x1B0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div16) {
        // 42.94967296
        s21_decimal number_1 = {{0x0, 0x1, 0x0, 0x80000}};
        // -0.9999
        s21_decimal number_2 = {{0x270F, 0x0, 0x0, 0x80040000}};
        // -42.953968356835683568356835684
        s21_decimal check = {{0x199A4164, 0x77BE0268, 0x8ACAB09A, 0x801B0000}};

                s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div17) {
        // 42.94967296
        s21_decimal number_1 = {{0x0, 0x1, 0x0, 0x80000}};
        // 1.431655765
        s21_decimal number_2 = {{0x55555555, 0x0, 0x0, 0x90000}};
        // 30.000000006984919311242392126
        s21_decimal check = {{0x4B5E723E, 0x1B5E723E, 0x60EF6B1B, 0x1B0000}};

                s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div18) {
        // 42.94967296
        s21_decimal number_1 = {{0x0, 0x1, 0x0, 0x80000}};
        // -1.431655765
        s21_decimal number_2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
        // -30.000000006984919311242392126
        s21_decimal check = {{0x4B5E723E, 0x1B5E723E, 0x60EF6B1B, 0x801B0000}};

                s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div19) {
        // 8.000
        s21_decimal number_1 = {{0x1F40, 0x0, 0x0, 0x30000}};
        // 0.0000000000000000000000000001
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x1C0000}};
        // overflow
        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, S21_INF);
}
END_TEST

START_TEST(test_div20) {
        // 8.000
        s21_decimal number_1 = {{0x1F40, 0x0, 0x0, 0x30000}};
        // -0.0000000000000000000000000001
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x801C0000}};
        // overflow
        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, S21_INF_NEG);
}
END_TEST

START_TEST(test_div21) {
        // 8.000
        s21_decimal number_1 = {{0x1F40, 0x0, 0x0, 0x30000}};
        // 0.0000000000000000000000000010
        s21_decimal number_2 = {{0xA, 0x0, 0x0, 0x1C0000}};
        // 8000000000000000000000000000
        s21_decimal check = {{0x40000000, 0xFE8401E7, 0x19D971E4, 0x0}};

                s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div22) {
        // 8.000
        s21_decimal number_1 = {{0x1F40, 0x0, 0x0, 0x30000}};
        // -0.0000000000000000000000000010
        s21_decimal number_2 = {{0xA, 0x0, 0x0, 0x801C0000}};
        // -8000000000000000000000000000
        s21_decimal check = {{0x40000000, 0xFE8401E7, 0x19D971E4, 0x80000000}};

                s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_div23) {
        // -0
        s21_decimal number_1 = {{0x0, 0x0, 0x0, 0x80000000}};
        // 0
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x0}};
        // division by zero
        s21_decimal result = {{0, 0, 0, 0}};

        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(test_div24) {
        // -0
        s21_decimal number_1 = {{0x0, 0x0, 0x0, 0x80000000}};
        // -0.0000000000000000000000000000
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x801C0000}};
        // division by zero
        s21_decimal result = {{0, 0, 0, 0}};
        
        int res = s21_div(number_1, number_2, &result);
        ck_assert_int_eq(res, 3);
}
END_TEST


        Suite *test_suite_s21_is_div() {
    Suite *s = suite_create("s21_div");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_div1);
    tcase_add_test(tc_core, test_div2);
    tcase_add_test(tc_core, test_div3);
    tcase_add_test(tc_core, test_div4);
    tcase_add_test(tc_core, test_div5);
    tcase_add_test(tc_core, test_div6);
    tcase_add_test(tc_core, test_div7);
    tcase_add_test(tc_core, test_div8);
    tcase_add_test(tc_core, test_div9);
    tcase_add_test(tc_core, test_div10);
    tcase_add_test(tc_core, test_div11);
    tcase_add_test(tc_core, test_div12);
    tcase_add_test(tc_core, test_div13);
    tcase_add_test(tc_core, test_div14);
    tcase_add_test(tc_core, test_div15);
    tcase_add_test(tc_core, test_div16);
    tcase_add_test(tc_core, test_div17);
    tcase_add_test(tc_core, test_div18);
    tcase_add_test(tc_core, test_div19);
    tcase_add_test(tc_core, test_div20);
    tcase_add_test(tc_core, test_div21);
    tcase_add_test(tc_core, test_div22);
    tcase_add_test(tc_core, test_div23);
    tcase_add_test(tc_core, test_div24);
    suite_add_tcase(s, tc_core);

    return s;
}
