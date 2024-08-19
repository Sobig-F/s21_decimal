#include "s21_decimal.h"
#include "help_functions.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    big_decimal local_1 = to_big_dec(value_1);
    big_decimal local_2 = to_big_dec(value_2);
    big_decimal rezerv;
    big_decimal local_result = {{0, 0, 0, 0, 0, 0, 0}};
    int returner, sign = get_dec_bit(value_1, 128);
    bring(&local_1, &local_2);
    set_big_bit(&local_1, 224, 0);
    set_big_bit(&local_2, 224, 0);
    if (is_less_mantiss(local_1, local_2)) {
        rezerv = local_1;
        local_1 = local_2;
        local_2 = rezerv;
        if (get_dec_bit(value_1, 128) == get_dec_bit(value_2, 128)) { 
            sign = sign * (-1) + 1;
        }
    }
    if (get_dec_bit(value_1, 128) == get_dec_bit(value_2, 128)) {
        conversion(&local_2);
        add_bigdec(local_1, local_2, &local_result);
    } else {
        add_bigdec(local_1, local_2, &local_result);
    }

    set_big_bit(&local_result, 224, sign);
    returner = to_dec(result, local_result);
    
    return returner;
}