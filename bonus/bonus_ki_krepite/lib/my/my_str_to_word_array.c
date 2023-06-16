/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** my_str_to_word_array.c
*/

#include "../../include/my.h"

static void alloc_size_of_element(char const *str, char const *sep,
char **my_tab_to_alloc)
{
    int j = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (strncmp(&str[i], sep, strlen(sep)) == 0) {
            my_tab_to_alloc[j] = new_array(k + 1);
            j++;
            k = 0;
        } else {
            k++;
        }
    }
    my_tab_to_alloc[j] = new_array(k + 1);
}

char **my_str_to_word_array(char const *str, char const *sep)
{
    char **tab = NULL;
    int j = 0;
    int k = 0;

    tab = new_double_array(strlen(str) + 1);
    alloc_size_of_element(str, sep, tab);
    for (int i = 0; str[i] != '\0'; i++) {
        if (strncmp(&str[i], sep, strlen(sep)) == 0) {
            tab[j][k] = '\0';
            j++;
            k = 0;
        } else {
            tab[j][k] = str[i];
            k++;
        }
    }
    tab[j][k] = '\0';
    tab[j + 1] = NULL;
    return (tab);
}
