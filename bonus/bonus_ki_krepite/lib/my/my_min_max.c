/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** my_min_max.c
*/

#include "../../include/my.h"

int my_max(int i , int j)
{
    if (i > j)
        return i;
    return j;
}

int my_min(int i , int j)
{
    if (i < j)
        return i;
    return j;
}
