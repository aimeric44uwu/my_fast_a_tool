/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** my_arrlen.c
*/

#include "../../include/my.h"

int my_arrlen(char **str)
{
    int size = 0;

    while ( *str != NULL ) {
        size++;
        *str++;
    }
    return ( size );
}
