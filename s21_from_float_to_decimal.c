#include "s21_decimal.h"
#include "help_functions.h"


int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    if (dst == NULL) return 1;
    if (isinf(src)) return 1;
    if (fabs(src) > 79228162514264337593543950335.0f) return 1;

    *dst = fill_zeroes();

    if (fabs(src) < 1e-28 && fabs(src) > 0) return 1;

    long int new = (long int)src;
    long int exp = 0;

    while (src - ((float)new / (long int)(pow(10, exp))) != 0) {
        exp++;
        new = src *(long int)(pow(10, exp));
    }

    while (exp > MAX_EXP - MAX_SIGNIFICANT_DIGITS) {
        src /= 10;
        exp--;
    }

    s21_from_int_to_decimal(new, dst);

    dst->bits[3] += exp << 16;

    if (src < 0) {
        set_dec_bit(dst, 128, 1);
    }

    return 0;
}
