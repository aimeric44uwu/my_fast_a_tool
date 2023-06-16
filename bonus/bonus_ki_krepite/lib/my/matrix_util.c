/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** matrix_util.c
*/

#include "../../include/my.h"

int my_int_len(int nb)
{
    int i = 0;

    if (nb == 0)
        return -1;
    if (nb < 0) {
        nb = nb * -1;
        i++;
    }
    for (; nb > 0; i++)
        nb = nb / 10;
    return i;
}

void free_matrix(int **matrix)
{
    for (int i = 0; matrix[i] != NULL; i++)
        free(matrix[i]);
    free(matrix);
}
