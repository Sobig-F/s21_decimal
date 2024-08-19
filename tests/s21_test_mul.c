#include "s21_test.h"

START_TEST(test_mul1) {
        // 7.9228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
        // 7.8228162514264337593543950335
        s21_decimal number_2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x1C0000}};
        // 61.978735728724164262422454727
        s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x1B0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul2) {
        // 7.9228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
        // -0.8228162514264337593543950335
        s21_decimal number_2 = {{0x4F63FFFF, 0xBB0D25CF, 0x1A962D2F, 0x801C0000}};
        // -6.5190219687391279469416894926
        s21_decimal check = {{0x23B23CAE, 0xEC60363A, 0xD2A415FA, 0x801C0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST


START_TEST(test_mul3) {
        // -7.000000000000025
        s21_decimal number_1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
        // -0.00000000000005
        s21_decimal number_2 = {{0x5, 0x0, 0x0, 0x800E0000}};
        // 0.0000000000003500000000000012
        s21_decimal check = {{0x40B6C00C, 0xC6F3B, 0x0, 0x1C0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul4) {
        // -7922816251426.4337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
        // 78228162514264.337593543950335
        s21_decimal number_2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xF0000}};
        // -619787357287241642624224547.27
        s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80020000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul5) {
        // -79228162514264.337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
        // 782281625142643.37593543950335
        s21_decimal number_2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xE0000}};
        // -61978735728724164262422454727
        s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul6) {
        // 79228162514264.1
        s21_decimal number_1 = {{0x70D42571, 0x2D093, 0x0, 0x10000}};
        // 78228162514264.5
        s21_decimal number_2 = {{0x22618575, 0x2C77B, 0x0, 0x10000}};
        // 6197873572872410706900970254.4
        s21_decimal check = {{0x7F6C2E90, 0x3FD777DD, 0xC8439BCC, 0x10000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul7) {
        // 79228162514265.1
        s21_decimal number_1 = {{0x70D4257B, 0x2D093, 0x0, 0x10000}};
        // 78228162514264.5
        s21_decimal number_2 = {{0x22618575, 0x2C77B, 0x0, 0x10000}};
        // 6197873572872488935063484519.0
        s21_decimal check = {{0xA1CDB406, 0x3FDA3F58, 0xC8439BCC, 0x10000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul8) {
        // 5.0
        s21_decimal number_1 = {{0x32, 0x0, 0x0, 0x10000}};
        // 4.5
        s21_decimal number_2 = {{0x2D, 0x0, 0x0, 0x10000}};
        // 22.50
        s21_decimal check = {{0x8CA, 0x0, 0x0, 0x20000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul9) {
        // 79228162.5
        s21_decimal number_1 = {{0x2F394219, 0x0, 0x0, 0x10000}};
        // 78228162.5555555555555
        s21_decimal number_2 = {{0xB20798E3, 0x6856A1BC, 0x2A, 0xD0000}};
        // 6197873575027970.8333289317688
        s21_decimal check = {{0x34C52538, 0x6AFC5902, 0xC8439BCD, 0xD0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul10) {
        // -7.000000000000025
        s21_decimal number_1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
        // -2.00000000000005
        s21_decimal number_2 = {{0x20F48005, 0xB5E6, 0x0, 0x800E0000}};
        // 14.000000000000400000000000001
        s21_decimal check = {{0xF1E90001, 0xBD686F20, 0x2D3C8750, 0x1B0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul11) {
        // -7.000000000000025
        s21_decimal number_1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
        // -0.0000000000005
        s21_decimal number_2 = {{0x5, 0x0, 0x0, 0x800D0000}};
        // 0.0000000000035000000000000125
        s21_decimal check = {{0x8723807D, 0x7C5850, 0x0, 0x1C0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul12) {
        // -7.000000000000025
        s21_decimal number_1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
        // -0.000000000000005
        s21_decimal number_2 = {{0x5, 0x0, 0x0, 0x800F0000}};
        // 0.0000000000000350000000000001
        s21_decimal check = {{0xB9ABE001, 0x13E52, 0x0, 0x1C0000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul13) {
        // 7.9228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
        // 0.00000
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x50000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul14) {
        // 7922816251426433759354395032.8
        s21_decimal number_1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
        // 10.000000000000000000000000001
        s21_decimal number_2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1B0000}};
        // overflow
        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);

        ck_assert_int_eq(res, S21_INF);
}
END_TEST

START_TEST(test_mul15) {
        // 7922816251426433759354395032.8
        s21_decimal number_1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
        // -10.000000000000000000000000001
        s21_decimal number_2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
        // overflow
    s21_decimal result = {{0, 0, 0, 0}};
    int res = s21_mul(number_1, number_2, &result);

    ck_assert_int_eq(res, S21_INF_NEG);
}
END_TEST

START_TEST(test_mul16) {
        // -7922816251426433759354395032.7
        s21_decimal number_1 = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
        // 10.000000000000000000000000001
        s21_decimal number_2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1B0000}};
        // -79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul17) {
        // -7922816251426433759354395032.7
        s21_decimal number_1 = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
        // -10.000000000000000000000000001
        s21_decimal number_2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
        // 79228162514264337593543950335
        s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul18) {
        // -0.0000000000000025
        s21_decimal number_1 = {{0x19, 0x0, 0x0, 0x80100000}};
        // -0.0000000000000005
        s21_decimal number_2 = {{0x5, 0x0, 0x0, 0x80100000}};
        // too small
    s21_decimal result = {{0, 0, 0, 0}};
    int res = s21_mul(number_1, number_2, &result);

    ck_assert_int_eq(res, S21_INF_NEG);
}
END_TEST

START_TEST(test_mul19) {
        // 792281625142643.37593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
        // -782281625142643.37593543950335
        s21_decimal number_2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x800E0000}};
        // overflow
    s21_decimal result = {{0, 0, 0, 0}};
    int res = s21_mul(number_1, number_2, &result);

    ck_assert_int_eq(res, S21_INF_NEG);
}
END_TEST

START_TEST(test_mul20) {
        // 792281625142643.37593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
        // 782281625142643.37593543950335
        s21_decimal number_2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xE0000}};
        // overflow
        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);

        ck_assert_int_eq(res, S21_INF);
}
END_TEST


START_TEST(test_mul21) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // 26409387504754779197847983445
        s21_decimal number_2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // overflow
    s21_decimal result = {{0, 0, 0, 0}};
    int res = s21_mul(number_1, number_2, &result);

    ck_assert_int_eq(res, S21_INF);
}
END_TEST

START_TEST(test_mul22) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // 1
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x0}};
        // 26409387504754779197847983445
        s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul23) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // -1
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x80000000}};
        // -26409387504754779197847983445
        s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul24) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // 0.5
        s21_decimal number_2 = {{0x5, 0x0, 0x0, 0x10000}};
        // 13204693752377389598923991722
        s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul25) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // -0.5
        s21_decimal number_2 = {{0x5, 0x0, 0x0, 0x80010000}};
        // -13204693752377389598923991722
        s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul26) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // 0.4999999999999999999999999999
        s21_decimal number_2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
        // 13204693752377389598923991720
        s21_decimal check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul27) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // -0.4999999999999999999999999999
        s21_decimal number_2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
        // -13204693752377389598923991720
        s21_decimal check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul28) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // 0.5000000000000000000000000001
        s21_decimal number_2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
        // 13204693752377389598923991725
        s21_decimal check = {{0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul29) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // -0.5000000000000000000000000001
        s21_decimal number_2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
        // -13204693752377389598923991725
        s21_decimal check = {{0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul30) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // 1.0000000000000000000000000001
        s21_decimal number_2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
        // 26409387504754779197847983448
        s21_decimal check = {{0x55555558, 0x55555555, 0x55555555, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul31) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // -0.0000000000000000000000000000
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x801C0000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_mul32) {
        // 26409387504754779197847983445
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
        // 0.0000000000000000000000000000
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x1C0000}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result = {{0, 0, 0, 0}};
        int res = s21_mul(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);
        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

        Suite *test_suite_s21_is_mul() {
    Suite *s = suite_create("s21_mul");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_mul1);
    tcase_add_test(tc_core, test_mul2);
    tcase_add_test(tc_core, test_mul3);
    tcase_add_test(tc_core, test_mul4);
    tcase_add_test(tc_core, test_mul5);
    tcase_add_test(tc_core, test_mul6);
    tcase_add_test(tc_core, test_mul7);
    tcase_add_test(tc_core, test_mul8);
    tcase_add_test(tc_core, test_mul9);
    tcase_add_test(tc_core, test_mul10);
    tcase_add_test(tc_core, test_mul11);
    tcase_add_test(tc_core, test_mul12);
    tcase_add_test(tc_core, test_mul13);
    tcase_add_test(tc_core, test_mul14);
    tcase_add_test(tc_core, test_mul15);
    tcase_add_test(tc_core, test_mul16);
    tcase_add_test(tc_core, test_mul17);
    tcase_add_test(tc_core, test_mul18);
    tcase_add_test(tc_core, test_mul19);
    tcase_add_test(tc_core, test_mul20);
    tcase_add_test(tc_core, test_mul21);
    tcase_add_test(tc_core, test_mul22);
    tcase_add_test(tc_core, test_mul23);
    tcase_add_test(tc_core, test_mul24);
    tcase_add_test(tc_core, test_mul25);
    tcase_add_test(tc_core, test_mul26);
    tcase_add_test(tc_core, test_mul27);
    tcase_add_test(tc_core, test_mul28);
    tcase_add_test(tc_core, test_mul29);
    tcase_add_test(tc_core, test_mul30);
    tcase_add_test(tc_core, test_mul31);
    tcase_add_test(tc_core, test_mul32);

    suite_add_tcase(s, tc_core);

    return s;
}