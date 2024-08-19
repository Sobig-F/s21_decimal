#include "s21_decimal.h"
#include "help_functions.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
    int result = 1;
    big_decimal local_1 = to_big_dec(value_1);
    big_decimal local_2 = to_big_dec(value_2);
    bring(&local_1, &local_2);
    if (!is_zero(local_1) || !is_zero(local_2)) {
        for (int i = 6; i >= 0 && result; --i) {
            if (local_1.bits[i] != local_2.bits[i]) {
                result = 0;
            }
        }
    }
    return result;
}