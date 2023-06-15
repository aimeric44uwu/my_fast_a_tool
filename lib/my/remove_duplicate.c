/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** remove_duplicate.c
*/

#include "../../include/my.h"

static bool is_a_duplicate(char *chr, char **tmp, int count)
{
    for (int i = 0; tmp[i] != NULL; i++) {
        if (strcmp(tmp[i], chr) == 0) {
            return true;
        }
    }
    return false;
}

void remove_duplicates(char **to_treat)
{
    char **tmp = new_double_array(my_arrlen(to_treat));
    bool is_duplicate = false;
    int count = 0;

    for (int i = 0; to_treat[i] != NULL; i++)
        if (is_a_duplicate(to_treat[i], tmp, count) == false)
            tmp[count++] = to_treat[i];
    tmp[count] = NULL;
    for (int i = 0; i < count; i++)
        to_treat[i] = tmp[i];
    to_treat[count] = NULL;
    free(tmp);
}
