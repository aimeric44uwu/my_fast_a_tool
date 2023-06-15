/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** my_malloc.c
*/

#include "../../include/my.h"

char **new_double_array(int size)
{
    char **result = malloc(sizeof(char *) * (size + 1));

    if (result == NULL) {
        printf("error while malloc new double array\n");
        return NULL;
    }
    result[size] = NULL;
    return result;
}

char *new_array(int size)
{
    char *result = malloc(sizeof(char) * (size + 1));

    if (result == NULL) {
        printf("error while malloc new array\n");
        return NULL;
    }
    result[size] = '\0';
    return result;
}
