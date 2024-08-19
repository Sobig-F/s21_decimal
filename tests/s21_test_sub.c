#include "s21_test.h"

START_TEST(test_sub1) {
        // 7.922816251426433759354395034
        s21_decimal number_1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};
        // 3.9614081257132168796771975168
        s21_decimal number_2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
        // 3.9614081257132168796771975172
        s21_decimal check = {{0x4, 0x0, 0x80000000, 0x1C0000}};
        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub2) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 79228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 0
        s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub3) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // -79228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
        // overflow
        s21_decimal result = (s21_decimal) {0};

        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, S21_INF);
}
END_TEST

START_TEST(test_sub4) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 79228162514264337593543950334
        s21_decimal number_2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 1
        s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub5) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 7922816251426433759354395033.5
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
        // 71305346262837903834189555302
        s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub6) {
        // 79228162514264337593543950335
        s21_decimal number_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // 7922816251426433759354395034
        s21_decimal number_2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
        // 71305346262837903834189555301
        s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub7) {
        // -1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x80000000}};
        // 7922816251426433759354395035
        s21_decimal number_2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
        // -7922816251426433759354395036
        s21_decimal check = {{0x9999999C, 0x99999999, 0x19999999, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub8) {
        // -1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x80000000}};
        // 1
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x0}};
        // -2
        s21_decimal check = {{0x2, 0x0, 0x0, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub9) {
        // -1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x80000000}};
        // -1.9999999999999999999999999000
        s21_decimal number_2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
        // 0.9999999999999999999999999000
        s21_decimal check = {{0xFFFFC18, 0x3E250261, 0x204FCE5E, 0x1C0000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub10) {
        // -1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x80000000}};
        // -0.0000000000000000000000000000
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x801C0000}};
        // -1.0000000000000000000000000000
        s21_decimal check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub11) {
        // -1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x80000000}};
        // -3.6336660283201536
        s21_decimal number_2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
        // 2.6336660283201536
        s21_decimal check = {{0x90C01800, 0x5D910D, 0x0, 0x100000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub12) {
        // -1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x80000000}};
        // 0.0000000000000000000000000000
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x1C0000}};
        // -1.0000000000000000000000000000
        s21_decimal check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub13) {
        // -1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x80000000}};
        // 0.0000000000000000000000000001
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x1C0000}};
        // -1.0000000000000000000000000001
        s21_decimal check = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub14) {
        // 0.5
        s21_decimal number_1 = {{0x5, 0x0, 0x0, 0x10000}};
        // 79228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // -79228162514264337593543950334
        s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub15) {
        // 0.5
        s21_decimal number_1 = {{0x5, 0x0, 0x0, 0x10000}};
        // -79228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
        // overflow
        s21_decimal result = (s21_decimal) {0};

        int res = s21_sub(number_1, number_2, &result);
        // print_dec(result);
        ck_assert_int_eq(res, S21_INF);
}
END_TEST

START_TEST(test_sub16) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // -0.0000000000000000000000000000
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x801C0000}};
        // -26409387498605864508043122005
        s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub17) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // 0.0000000000000000000000000000
        s21_decimal number_2 = {{0x0, 0x0, 0x0, 0x1C0000}};
        // -26409387498605864508043122005
        s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub18) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // 0.0000000000000000000000000001
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x1C0000}};
        // -26409387498605864508043122005
        s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub19) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // -0.0000000000000000000000000001
        s21_decimal number_2 = {{0x1, 0x0, 0x0, 0x801C0000}};
        // -26409387498605864508043122005
        s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub20) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // 0.0000000000000000000000000010
        s21_decimal number_2 = {{0xA, 0x0, 0x0, 0x1C0000}};
        // -26409387498605864508043122005
        s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub21) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // -0.0000000000000000000000000010
        s21_decimal number_2 = {{0xA, 0x0, 0x0, 0x801C0000}};
        // -26409387498605864508043122005
        s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub22) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // 646.33673839575124685661598885
        s21_decimal number_2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
        // -26409387498605864508043122651
        s21_decimal check = {{0x555557DB, 0x0, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub23) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // -646.33673839575124685661598885
        s21_decimal number_2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
        // -26409387498605864508043121359
        s21_decimal check = {{0x555552CF, 0x0, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub24) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // -24246937143470783.81744120110
        s21_decimal number_2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
        // -26409387498581617570899651221
        s21_decimal check = {{0x5A016A95, 0xFFA9DB8A, 0x55555554, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub25) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // 24246937143470783.81744120110
        s21_decimal number_2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
        // -26409387498630111445186592789
        s21_decimal check = {{0x50A94015, 0x562476, 0x55555555, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub26) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // 60233732531769558296976156804
        s21_decimal number_2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
        // overflow
        s21_decimal result = (s21_decimal) {0};
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, S21_INF_NEG);
}
END_TEST

START_TEST(test_sub27) {
        // -26409387498605864508043122005
        s21_decimal number_1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
        // -60233732531769558296976156804
        s21_decimal number_2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
        // 33824345033163693788933034799
        s21_decimal check = {{0xF6CE932F, 0x648C702B, 0x6D4AD7AA, 0x0}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub28) {
        // 6148914691236517205
        s21_decimal number_1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
        // 79228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // -79228162508115422902307433130
        s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);
}
END_TEST

START_TEST(test_sub29) {
        // 6148914691236517205
        s21_decimal number_1 = {{ 0x55555555, 0x55555555, 0x0, 0x0 }};
        // -79228162514264337593543950335
        s21_decimal number_2 = {{ 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000 }};
        // overflow
        s21_decimal result = (s21_decimal) {0};
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, S21_INF);

}
END_TEST

START_TEST(test_sub30) {
        // 0.0000000000000000000000000000
        s21_decimal number_1 = {{ 0x0, 0x0, 0x0, 0x1C0000 }};
        // 0
        s21_decimal number_2 = {{ 0x0, 0x0, 0x0, 0x0 }};
        // 0.0000000000000000000000000000
        s21_decimal check = {{ 0x0, 0x0, 0x0, 0x1C0000 }};

        s21_decimal result = (s21_decimal) {0};
        
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, 0);

        for (int i = 0; i < 4; i++)
        ck_assert_uint_eq(result.bits[i], check.bits[i]);

}
END_TEST

START_TEST(test_sub31) {
        // -1
        s21_decimal number_1 = {{0x1, 0x0, 0x0, 0x80000000}};
        // 79228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // overflow
        s21_decimal result = (s21_decimal) {0};
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, S21_INF_NEG);
}
END_TEST

START_TEST(test_sub32) {
        // -0.5000000000000000000000000001
        s21_decimal number_1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
        // 79228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // overflow
        s21_decimal result = (s21_decimal) {0};
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, S21_INF_NEG);
        
}
END_TEST

START_TEST(test_sub33) {
        // -1.9999999999999999999999999000
        s21_decimal number_1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
        // 79228162514264337593543950335
        s21_decimal number_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
        // overflow
        s21_decimal result = (s21_decimal) {0};
        int res = s21_sub(number_1, number_2, &result);
        ck_assert_int_eq(res, S21_INF_NEG);
}
END_TEST

Suite *test_suite_s21_is_sub(){
    Suite *s = suite_create("s21_sub");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_sub1);
    tcase_add_test(tc_core, test_sub2);
    tcase_add_test(tc_core, test_sub3);
    tcase_add_test(tc_core, test_sub4);
    tcase_add_test(tc_core, test_sub5);
    tcase_add_test(tc_core, test_sub6);
    tcase_add_test(tc_core, test_sub7);
    tcase_add_test(tc_core, test_sub8);
    tcase_add_test(tc_core, test_sub9);
    tcase_add_test(tc_core, test_sub10);
    tcase_add_test(tc_core, test_sub11);
    tcase_add_test(tc_core, test_sub12);
    tcase_add_test(tc_core, test_sub13);
    tcase_add_test(tc_core, test_sub14);
    tcase_add_test(tc_core, test_sub15);
    tcase_add_test(tc_core, test_sub16);
    tcase_add_test(tc_core, test_sub17);
    tcase_add_test(tc_core, test_sub18);
    tcase_add_test(tc_core, test_sub19);
    tcase_add_test(tc_core, test_sub20);
    tcase_add_test(tc_core, test_sub21);
    tcase_add_test(tc_core, test_sub22);
    tcase_add_test(tc_core, test_sub23);
    tcase_add_test(tc_core, test_sub24);
    tcase_add_test(tc_core, test_sub25);
    tcase_add_test(tc_core, test_sub26);
    tcase_add_test(tc_core, test_sub27);
    tcase_add_test(tc_core, test_sub28);
    tcase_add_test(tc_core, test_sub29);
    tcase_add_test(tc_core, test_sub30);
    tcase_add_test(tc_core, test_sub31);
    tcase_add_test(tc_core, test_sub32);
    tcase_add_test(tc_core, test_sub33);

    suite_add_tcase(s, tc_core);

    return s;
}
