#include "s21_decimal.h"
#include "help_functions.h"
// #include "math.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    long double degree = 1.0;
    long double int_temp = 0.0;
    long double float_temp = 0.0;
    long double exp = 10.0;
    s21_decimal int_src;
    s21_decimal float_src;
    s21_truncate(src, &int_src);
    s21_sub(src, int_src, &float_src);

    for (int i = 1; i < 97; ++i) {
        int_temp += get_dec_bit(int_src, i) * degree;
        degree *= 2.0;
    }
    degree = 1.0;
    for (int i = 1; i < 97; ++i) {
        float_temp += get_dec_bit(float_src, i) * degree;
        degree *= 2.0;
    }

    if (get_dec_pow(src)) {
        for (int i = 1; i < get_dec_pow(src); ++i) {
            exp *= 10.0;
        }
        float_temp /= exp;
    }

    *dst = int_temp + float_temp;

    if (get_dec_bit(src, 128)) {
        *dst *= -1;
    }

    return 0;
}