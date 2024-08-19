#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    if (src < 0) {
        dst->bits[0] = -src;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 1 << 31;
    } else {
        dst->bits[0] = src;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 0;
    }

    return 0;
}