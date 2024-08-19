#include "s21_decimal.h"
#include "help_functions.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int returner = 0;
    big_decimal local_1 = to_big_dec(value_1);
    big_decimal local_2 = to_big_dec(value_2);
    if (is_zero(local_1) || is_zero(local_2)) {
        result->bits[0] = 0;
        result->bits[1] = 0;
        result->bits[2] = 0;
        result->bits[3] = 0;
    } else {
        big_decimal local_result = {{0, 0, 0, 0, 0, 0, 0}};
        int sign = 0;
        int new_exp = 0;

        if (get_bit(local_1, 224) != get_bit(local_2, 224)) {
            sign = 1;
        }

        if (is_less_mantiss(local_1, local_2)) {
            local_1 = to_big_dec(value_2);
            local_2 = to_big_dec(value_1);
        }

        if (get_bit(local_1, 224)) {
            set_big_bit(&local_1, 224, 0);
        }

        if (get_bit(local_2, 224)) {
            set_big_bit(&local_2, 224, 0);
        }
        
        for (int i = 1; i <= 192; ++i) {
            if (get_bit(local_2, i)) {
                add_bigdec(local_result, local_1, &local_result);
            }
            shift_left(&local_1);
        }

        new_exp = get_pow(local_1) + get_pow(local_2);
        local_result.bits[6] = new_exp << 16;
        set_big_bit(&local_result, 224, sign);
        returner = to_dec(result, local_result);
    }
    
    return returner;
}