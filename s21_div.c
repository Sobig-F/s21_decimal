#include "s21_decimal.h"
#include "help_functions.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    big_decimal local_1 = to_big_dec(value_1);
    big_decimal local_2 = to_big_dec(value_2);
    big_decimal cash;
    big_decimal local_result = {{0, 0, 0, 0, 0, 0, 0}};
    big_decimal local_result_ost = {{0, 0, 0, 0, 0, 0, 0}};
    int sign = 0;
    int left_shift = 1;
    int new_pow = 0;
    int returner = 0;
    int whole = 1;

    if (is_zero(local_2)) {
        returner = 3;
    }

    if (returner != 3) {
        bring(&local_1, &local_2);
    }

    while (returner != 3 && get_pow(local_1)) {
        down_pow(&local_1);
        down_pow(&local_2);
    }

    if (returner != 3 && get_bit(local_1, 224) != get_bit(local_2, 224)) {
        sign = 1;
        if (get_bit(local_1, 224)) {
            set_big_bit(&local_1, 224, 0);
        } else {
            set_big_bit(&local_2, 224, 0);
        }
    }

    while (returner != 3 && !is_zero(local_1) && new_pow < 28) {
        left_shift = 0;
        local_result_ost.bits[0] = 0;
        local_result_ost.bits[1] = 0;
        local_result_ost.bits[2] = 0;
        local_result_ost.bits[3] = 0;
        local_result_ost.bits[4] = 0;
        local_result_ost.bits[5] = 0;
        multiply_10(&local_result);
        while (bit_count(local_2) < bit_count(local_1)) {
            shift_left(&local_2);
            ++left_shift;
        }
        if (left_shift) {
            ++left_shift;
            shift_left(&local_2);
        }
        while (left_shift) {
            shift_right(&local_2);
            --left_shift;
            shift_left(&local_result_ost);
            if (is_less_mantiss(local_1, local_2)) {
                set_big_bit(&local_result_ost, 1, 0);
            } else {
                set_big_bit(&local_result_ost, 1, 1);
                cash = local_2;
                conversion(&cash);
                add_bigdec(local_1, cash, &local_1);
            }
        }
        add_bigdec(local_result, local_result_ost, &local_result);
        multiply_10(&local_1);
        if (whole) {
            whole = 0;
        } else {
            ++new_pow;
        }
    }

    
    if (returner != 3) {
        local_result.bits[6] = new_pow << 16;
        set_big_bit(&local_result, 224, sign);
        returner = to_dec(result, local_result);
    }

    return returner;    
}

// #include "s21_decimal.h"
// #include "help_functions.h"

// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
//     big_decimal local_1 = to_big_dec(value_1);
//     big_decimal local_2 = to_big_dec(value_2);
//     big_decimal cash;
//     big_decimal local_result = {{0, 0, 0, 0, 0, 0, 0}};
//     big_decimal local_result_ost = {{0, 0, 0, 0, 0, 0, 0}};
//     int sign = 0;
//     int right_shift;
//     int new_pow = 0;
//     int returner = 0;

//     if (is_zero(local_2)) {
//         returner = 3;
//     }

//     if (returner != 3) {
//         while (get_pow(local_2) && get_pow(local_1)) {
//             down_pow(&local_1);
//             down_pow(&local_2);
//         }
//         while (get_pow(local_2)) {
//             multiply_10(&local_1);
//             down_pow(&local_1);
//             down_pow(&local_2);
//         }
//     }
//     if (returner != 3 && get_bit(local_1, 224) != get_bit(local_2, 224)) {
//         sign = 1;
//     }
//     if (get_bit(local_1, 224)) {
//         set_big_bit(&local_1, 224, 0);
//     }
//     if (get_bit(local_2, 224)) {
//         set_big_bit(&local_2, 224, 0);
//     }

//     new_pow = 29;
//     while (returner != 3 && !is_zero(local_1) && new_pow) {
//         multiply_10(&local_result);
//         right_shift = 0;
//         local_result_ost.bits[0] = 0;
//         local_result_ost.bits[1] = 0;
//         local_result_ost.bits[2] = 0;
//         local_result_ost.bits[3] = 0;
//         local_result_ost.bits[4] = 0;
//         local_result_ost.bits[5] = 0;

//         while (bit_count(local_2) < bit_count(local_1)) {
//             shift_left(&local_2);
//             ++right_shift;
//         }
//         do {
//             shift_left(&local_result_ost);
//             --right_shift;
//             if (is_less_mantiss(local_1, local_2)) {
//                 set_big_bit(&local_result_ost, 1, 0);
//             } else {
//                 set_big_bit(&local_result_ost, 1, 1);
//                 cash = local_2;
//                 conversion(&cash);
//                 add_bigdec(local_1, cash, &local_1);
//             }
//             shift_right(&local_2);

//         } while (right_shift >= 0);
//         add_bigdec(local_result, local_result_ost, &local_result);
//         if (!is_zero(local_1) && is_less_mantiss(local_1, local_2)) {
//             multiply_10(&local_1);
//         }
//         --new_pow;
//     }
    
//     if (returner != 3) {
//         if (get_dec_pow(value_1) > get_dec_pow(value_2)) {
//             new_pow = get_dec_pow(value_1) - get_dec_pow(value_2);
//         } else {
//             new_pow = get_dec_pow(value_2) - get_dec_pow(value_1);
//         }
//         division_10(&local_result);
//         local_result.bits[6] = new_pow << 16;
//         set_big_bit(&local_result, 224, sign);
//         print_big_dec(local_result);
//         returner = to_dec(result, local_result);
//     }
//     return returner;    
// }