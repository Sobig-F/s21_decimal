#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

#include "s21_decimal.h"

typedef struct big_decimal {
    unsigned int bits[7];
} big_decimal;


void bring(big_decimal *value_1, big_decimal *value_2);
unsigned int get_bit(big_decimal value, unsigned int bit);
unsigned int get_int_bit(unsigned int value, unsigned int bit);
unsigned int get_dec_bit(s21_decimal value, unsigned int bit);
void set_big_bit(big_decimal *value, int bit, int bit_value);
void set_dec_bit(s21_decimal *value, int bit, int bit_value);
void set_int_bit(int *value, int bit, int bit_value);
void shift_right(big_decimal *value);
void multiply_10(big_decimal *value);
int division_10(big_decimal *value);
void up_pow(big_decimal *value);
void down_pow(big_decimal *value);
int max_pow(int first, int second);
int get_pow(big_decimal value);
big_decimal to_big_dec(s21_decimal value_2);
void bank_rounding(big_decimal *value);
int to_dec(s21_decimal *result, big_decimal value);
int bit_count(big_decimal value);
int checking_the_capacity(big_decimal value);
void set_max_dec(big_decimal *value);
unsigned get_slice(big_decimal value, int start_bit, int end_bit);
int get_pow(big_decimal value);
void shift_left(big_decimal *value);
s21_decimal fill_zeroes();
void print_big_dec(big_decimal value);
void print_dec(s21_decimal value);
int is_over(unsigned a, unsigned b, unsigned c);
void conversion(big_decimal *value);
void add_bigdec(big_decimal value_1, big_decimal value_2, big_decimal *result);
int is_zero(big_decimal value);
int is_dec_zero(s21_decimal value);
int is_less_mantiss(big_decimal value_1, big_decimal value_2);
int get_dec_pow(s21_decimal value);
int get_sign(s21_decimal number);


#endif