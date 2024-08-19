#include "s21_decimal.h"
#include "help_functions.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    big_decimal local_1 = to_big_dec(value_1);
    big_decimal local_2 = to_big_dec(value_2);
    big_decimal local_result;
    int returner = 0;
    bring(&local_1, &local_2);
    if (get_bit(local_1, 224) == get_bit(local_2, 224)) {
        int overvalue = 0;
        for (int i = 0; i < 6; ++i) {
            local_result.bits[i] = local_1.bits[i] + local_2.bits[i] + overvalue;
            overvalue = is_over(local_1.bits[i], local_2.bits[i], local_result.bits[i]);
        }
        local_result.bits[6] = local_1.bits[6];
        returner = to_dec(result, local_result);
    } else if (get_bit(local_1, 224) < get_bit(local_2, 224)) {
        set_dec_bit(&value_2, 128, 0);
        returner = s21_sub(value_1, value_2, result);
    } else {
        set_dec_bit(&value_1, 128, 0);
        returner = s21_sub(value_2, value_1, result);
    }

    return returner;
}