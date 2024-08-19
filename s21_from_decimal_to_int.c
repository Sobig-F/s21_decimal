#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int returner = 0;
    s21_truncate(src, &src);
    if (src.bits[1] > 0 || src.bits[2] > 0) {
        returner = 1;
    } else {
        *dst = src.bits[0];
        if (src.bits[3] >> 31) {
            *dst *= -1;
        }
    }

    return returner;
}