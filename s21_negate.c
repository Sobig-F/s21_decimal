#include "s21_decimal.h"
#include "help_functions.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
    if (get_dec_bit(value, 128)) {
        set_dec_bit(&value, 128, 0);
    } else {
        set_dec_bit(&value, 128, 1);
    }
    for (int i = 0; i < 4; ++i) {
        result->bits[i] = value.bits[i];
    }
    return 0;
}