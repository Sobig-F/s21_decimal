#include "s21_decimal.h"
#include "help_functions.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
    int returner = 0;
    big_decimal local_value = to_big_dec(value);
    while (get_pow(local_value) > 0) {
        division_10(&local_value);
    }
    
    returner = to_dec(result, local_value);

    return returner;
}