/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** sort_my_array.c
*/

#include "../../include/my.h"

static void sort_my_array_ptwo(char **to_sort, int i, int j)
{
    if (strcmp(to_sort[i], to_sort[j]) > 0) {
        char *tmp = to_sort[i];
        to_sort[i] = to_sort[j];
        to_sort[j] = tmp;
    }
}

void sort_my_array(char **to_sort)
{
    for (int i = 0; i < my_arrlen(to_sort); i++) {
        for (int j = i + 1; j < my_arrlen(to_sort); j++) {
            sort_my_array_ptwo(to_sort, i, j);
        }
    }
}
