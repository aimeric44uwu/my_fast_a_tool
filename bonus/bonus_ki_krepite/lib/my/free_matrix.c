/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** free_matrix.c
*/

#include "../../include/my.h"

void free_matrix(int **matrix)
{
    for (int i = 0; matrix[i] != NULL; i++)
        free(matrix[i]);
    free(matrix);
}
