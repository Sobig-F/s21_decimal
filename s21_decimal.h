#ifndef S21_DECIMAL
#define S21_DECIMAL

#include <stdio.h>
#include <limits.h>
#include <math.h>

#define BORDER 96
#define BIT 32U
#define INT 2147483648U
#define MAX_EXP 96

#define MAX_SIGNIFICANT_DIGITS 7

#define S21_MAX_UNSIGNED 4294967295U


#define MAX_VAL 79228162514264337593543950335.0

/*размер массива bits структуры s21_decimal*/
#define MAXSIZ 4
/*максимальное значение битов отвечающие за численную часть числа decimal*/
#define NUMBITS 95

#define LOW 0
#define HIGH 2
#define SIGNEXP 3

#define BIGHIGH 6
#define BIGES 7

#define S21_INF 1
#define S21_INF_NEG 2
#define EXP_POS 23

#define SIGN_SET 2147483648

typedef enum {
    S21_OK = 0,
    S21_ERROR = 1,
}s21_other_functions_result;

typedef enum {
    S21_COMPARISON_TRUE = 1,
    S21_COMPARISON_FALSE = 0,
}s21_comparison_result;

typedef struct {
    unsigned int bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif