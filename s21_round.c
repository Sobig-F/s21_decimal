#include "s21_decimal.h"
#include "help_functions.h"

int s21_round(s21_decimal value, s21_decimal *result) {
    int remains = 0;
    int returner = 0;
    s21_decimal one = {{1, 0, 0, 0}};
    big_decimal local_value = to_big_dec(value);
    while (get_pow(local_value) > 0) {
        remains = division_10(&local_value);
    }

    returner = to_dec(&value, local_value);

    if (get_dec_bit(value, 128) && remains >= 5) {
        returner = s21_sub(value, one, result);
    } else if (!get_dec_bit(value, 128) && remains >= 5) {
        returner = s21_add(value, one, result);
    } else {
        for (int i = 0; i < 4; ++i) {
            result->bits[i] = value.bits[i];
        }
    }

    return returner;
}