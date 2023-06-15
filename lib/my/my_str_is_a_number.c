/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** my_str_is_a_number.c
*/

#include "../../include/my.h"

bool my_str_is_num(char *str)
{
    long long int i = 0;

    if (str == NULL)
        return false;
    if (str[0] == '-')
        i++;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}
