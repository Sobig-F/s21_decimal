#include "help_functions.h"

//привидение к равным степеням десятичной части
void bring(big_decimal *value_1, big_decimal *value_2) {
    if (get_pow(*value_1) > get_pow(*value_2)) {
        while (get_pow(*value_1) > get_pow(*value_2)) {
            multiply_10(value_2);
        }
    } else if (get_pow(*value_1) < get_pow(*value_2)) {
        while (get_pow(*value_1) < get_pow(*value_2)) {
            multiply_10(value_1);
        }
    }
}

//получение бита с позиции [bit]
unsigned get_bit(big_decimal value, unsigned int bit) {
    --bit;
    return (value.bits[bit / BIT] & 1 << (bit % BIT)) >> (bit % BIT);
}

unsigned get_dec_bit(s21_decimal value, unsigned int bit) {
    --bit;
    return (value.bits[bit / BIT] & 1 << (bit % BIT)) >> (bit % BIT);
}

unsigned get_int_bit(unsigned int value, unsigned int bit) {
    --bit;
    return (value & (1 << bit)) >> bit;
}

//установка [bit_value] в позицию [bit]
void set_big_bit(big_decimal *value, int bit, int bit_value) {
    --bit;
    if (bit_value) {
        value->bits[bit / BIT] = value->bits[bit / BIT] | (1 << (bit % BIT));
    } else {
        value->bits[bit / BIT] = value->bits[bit / BIT] & ~(1 << (bit % BIT));
    }
}


void set_dec_bit(s21_decimal *value, int bit, int bit_value) {
    --bit;
    if (bit_value) {
        value->bits[bit / BIT] = value->bits[bit / BIT] | (1 << (bit % BIT));
    } else {
        value->bits[bit / BIT] = value->bits[bit / BIT] & ~(1 << (bit % BIT));
    }
}


void set_int_bit(int *value, int bit, int bit_value) {
    --bit;
    if (bit_value) {
        *value = *value | (1 << bit);
    } else {
        *value = *value & ~(1 << bit);
    }
}

//сдвиг мантиссы вправо
void shift_right(big_decimal *value) {
    int first_bit = get_bit(*value, BIT + 1);
    for (int i = 0; i < 6; ++i) {
        first_bit = get_bit(*value, BIT * (i + 1) + 1);
        value->bits[i] = value->bits[i] >> 1;
        if (i != 5) {
            set_big_bit(value, BIT * (i + 1), first_bit);
        }
    }
}


//сдвиг мантиссы влево
void shift_left(big_decimal *value) {
    int last_bit;
    value->bits[5] = value->bits[5] << 1;
    for (int i = 4; i >= 0; --i) {
        last_bit = get_bit(*value, BIT * (i + 1));
        value->bits[i] = value->bits[i] << 1;
        set_big_bit(value, BIT * (i + 1) + 1, last_bit);
    }
}

int is_over(unsigned a, unsigned b, unsigned c) {
    return ((c <= a && b != 0) || (c <= b && a != 0));
}


//умножение числа на 10
void multiply_10(big_decimal *value) {
    big_decimal local_2 = *value;
    big_decimal local_8 = *value;
    shift_left(&local_2);
    shift_left(&local_8);
    shift_left(&local_8);
    shift_left(&local_8);

    unsigned int overvalue = 0;
    for (int i = 0; i < 6; ++i) {
        value->bits[i] = local_2.bits[i] + local_8.bits[i] + overvalue;
        overvalue = is_over(local_2.bits[i], local_8.bits[i], value->bits[i]);
    }
    up_pow(value);
}

//повышение степени
void up_pow(big_decimal *value) {
    int first_bit = get_bit(*value, 224);
    value->bits[6] = ((value->bits[6] >> 16) + 1) << 16;
    set_big_bit(value, 224, first_bit);
}

//понимжение степени
void down_pow(big_decimal *value) {
    if (get_pow(*value)) {
        int first_bit = get_bit(*value, 224);
        value->bits[6] = ((value->bits[6] >> 16) - 1) << 16;
        set_big_bit(value, 224, first_bit);
    }
}

//большая степень
int max_pow(int first, int second) {
    if (first >> 8 > second >> 8) {
        return 1;
    } else if (first >> 8 < second >> 8) {
        return -1;
    }
    return 0;
}

//получение экспоненты
int get_pow(big_decimal value) {
    return value.bits[6] << 1 >> 17;
}

int get_dec_pow(s21_decimal value) {
    return value.bits[3] << 1 >> 17;
}

//получение отрезка из big_decimal
unsigned get_slice(big_decimal value, int start_bit, int end_bit) {
    int result = 0;
    for (int i = start_bit; i >= end_bit; --i) {
        result = result << 1;
        set_int_bit(&result, 1, get_bit(value, i));
    }
    return result;
}


//деление на 10
int division_10(big_decimal *value) {
    big_decimal result = {{0, 0, 0, 0}};
    int cash_result = 0;
    int returned_result = 0;
    for (int i = 192; i >= 4; --i) {
        if (i == 192 && get_slice(*value, i, i - 3) < 10) {
            shift_left(&result);
            set_big_bit(&result, 1, 0);
        } else if (i < 192 && (get_slice(*value, i + 1, i - 3) < 10) && (get_slice(*value, i, i - 3) < 10)) {
            shift_left(&result);
            set_big_bit(&result, 1, 0);
        } else if (get_slice(*value, i, i - 3) >= 10) {
            shift_left(&result);
            set_big_bit(&result, 1, 1);
            cash_result = get_slice(*value, i, i - 3) - 10;
            for (int j = i - 3; j <= i; ++j) {
                set_big_bit(value, j, get_int_bit(cash_result, j - i + 4));
            }
        } else if (get_slice(*value, i + 1, i - 3) > 10) {
            shift_left(&result);
            set_big_bit(&result, 1, 1);
            cash_result = get_slice(*value, i + 1, i - 3) - 10;
            for (int j = i - 3; j <= i + 1; ++j) {
                set_big_bit(value, j, get_int_bit(cash_result, j - i + 4));
            }
        }
    }

    returned_result = value->bits[0];

    for (int i = 0; i < 6; ++i) {
        value->bits[i] = result.bits[i];
    }

    down_pow(value);

    return returned_result;
}

//перевод s21_decimal в big_decimal
big_decimal to_big_dec(s21_decimal value_2) {
    big_decimal value_1;
    value_1.bits[0] = value_2.bits[0];
    value_1.bits[1] = value_2.bits[1];
    value_1.bits[2] = value_2.bits[2];
    value_1.bits[3] = 0U;
    value_1.bits[4] = 0U;
    value_1.bits[5] = 0U;
    value_1.bits[6] = value_2.bits[3];
    return value_1;
}

//установка максимального s21_decimal
void set_max_dec(big_decimal *value) {
    for (int i = 0; i < 3; ++i) {
        value->bits[i] = 0;
        value->bits[i] = ~value->bits[i];
    }
    for (int i = 3; i < 7; ++i) {
        value->bits[i] = 0;
    }
}

//проверка вместимости целой части
int checking_the_capacity(big_decimal value) {
    big_decimal check_dec;
    set_max_dec(&check_dec);
    bring(&value, &check_dec);
    for (int i = 192; i > 0; --i) {
        if (get_bit(check_dec, i)) {
            return 1;
        } else if (get_bit(value, i)) {
            return 0;
        }
    }
    return 0;
}

//кол-во занятых битов
int bit_count(big_decimal value) {
    for (int i = 192; i > 0; --i) {
        if (get_bit(value, i)) {
            return i;
        }
    }
    return 0;
}

//перевод big_decimal в s21_decimal
int to_dec(s21_decimal *result, big_decimal value) {
    int zero = is_zero(value);
    bank_rounding(&value);
    if (zero != is_zero(value)) {
        return 2;
    } else if (!checking_the_capacity(value)) {
        if (!get_bit(value, 224)) {
            return 1;
        } else {
            return 2;
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            result->bits[i] = value.bits[i];
        }
        result->bits[3] = value.bits[6];
    }
    return 0;
}

//банковское округление
void bank_rounding(big_decimal *value) {
    int remains = 0;
    int sum = 0;
    big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
    while (get_pow(*value) && (value->bits[5] != 0 || value->bits[4] != 0 || value->bits[3] != 0 || get_pow(*value) > 28)) {
        remains = division_10(value);
        sum += remains; 
    }
    if ((remains >= 5 && sum > 5) || (remains == 5 && sum == 5 && get_bit(*value, 1))) {
        add_bigdec(*value, one, value);
    }
}

//заполняет децимал нулями (для ошибок)
s21_decimal fill_zeroes() {
    s21_decimal temp = {{0, 0, 0, 0}};
    return temp;
}

void print_big_dec(big_decimal value) {
    for (int i = 224; i > 0; --i) {
        if (i % 32 == 0 && i > 0) {
            printf(" | ");
        } else if (i % 8 == 0 && i > 0) {
            printf(" ");
        }
        printf("%d", get_bit(value, i));
    }
    printf("\n");
}


void print_dec(s21_decimal value) {
    for (int i = 128; i > 0; --i) {
        if (i % 32 == 0 && i > 0) {
            printf(" | ");
        } else if (i % 8 == 0 && i > 0) {
            printf(" ");
        }
        printf("%d", get_dec_bit(value, i));
    }
    printf("\n");
}


//преобразование числа из sub для add (инверсия + 1)
void conversion(big_decimal *value) {
    int cash = 0;
    unsigned int overvalue = 1;
    for (int i = 0; i < 6; ++i) {
        value->bits[i] = ~value->bits[i];
        cash = value->bits[i];
        value->bits[i] += overvalue;
        overvalue = is_over(cash, overvalue, value->bits[i]);
    }
}

void add_bigdec(big_decimal value_1, big_decimal value_2, big_decimal *result) {
    int overvalue = 0;
    for (int i = 0; i < 6; ++i) {
        result->bits[i] = value_1.bits[i] + value_2.bits[i] + overvalue;
        overvalue = is_over(value_1.bits[i], value_2.bits[i], result->bits[i]);
    }
    result->bits[6] = value_1.bits[6];
    // print_big_dec(*result);
}

int is_zero(big_decimal value) {
    return value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0 && value.bits[3] == 0 && value.bits[4] == 0 && value.bits[5] == 0;
}

int is_dec_zero(s21_decimal value) {
    return value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0;
}

int is_less_mantiss(big_decimal value_1, big_decimal value_2) {
    int result = 0;
    for (int i = 5; i >= 0 && !result && value_1.bits[i] <= value_2.bits[i]; --i) {
        if (value_1.bits[i] < value_2.bits[i]) {
            result = 1;
        }
    }
    return result;
}

int get_sign(s21_decimal number) {
    return number.bits[3] >> 31;
}
