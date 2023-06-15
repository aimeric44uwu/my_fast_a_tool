/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** my_revstr.c
*/

#include "../../include/my.h"

char *revstr(char *str1)
{
    int i;
    int len = strlen(str1);
    char temp = 0;
    char *result = new_array(sizeof(char) * len + 1);

    if (result == NULL || str1 == NULL)
        return NULL;
    strcpy(result, str1);
    for (i = 0; i < len / 2; i++) {
        temp = result[i];
        result[i] = result[len - i - 1];
        result[len - i - 1] = temp;
    }
    result[len] = '\0';
    free(str1);
    return result;
}
