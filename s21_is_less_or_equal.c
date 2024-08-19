#include "s21_decimal.h"
#include "help_functions.h"

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
    int result = 1;
    big_decimal local_1 = to_big_dec(value_1);
    big_decimal local_2 = to_big_dec(value_2);
    bring(&local_1, &local_2);
    if (s21_is_equal(value_1, value_2)) {
        result = 1;
    } else if (get_dec_bit(value_1, 128) == get_dec_bit(value_2, 128)) {
        if (get_dec_bit(value_1, 128)) {
            for (int i = 5; i >= 0 && local_1.bits[i] <= local_2.bits[i] && result; --i) {
                if (local_1.bits[i] < local_2.bits[i]) {
                    result = 0;
                }
            }
        } else {
            for (int i = 5; i >= 0 && local_1.bits[i] >= local_2.bits[i] && result; --i) {
                if (local_1.bits[i] > local_2.bits[i]) {
                    result = 0;
                }
            }
        }
    } else if (get_dec_bit(value_2, 128)) {
        result = 0;
    }
    return result;
}