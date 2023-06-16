/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** requirement.c
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int size = 0;

    while (*str) {
        size++;
        *str++;
    }
    return ( size );
}

static char my_chrcapitalize(char chr)
{
    if ( chr >= 97 && chr <= 122 )
        chr = chr - 32;
    return chr;
}

static int my_char_is_alpha(char const chr)
{
    if ( chr >= 49 && chr <= 57 )
        return 1;
    if ( chr >= 65 && chr <= 90 )
        return 1;
    if ( chr >= 97 && chr <= 122 )
        return 1;
    return 0;
}

char *my_strcapitalize_synthesis(char *str)
{
    int size = my_strlen(str);

    if (size == 0)
        return NULL;
    str[0] = my_chrcapitalize(str[0]);
    for (int i = 0; i < size || str[i] != '\0'; i++)
        if (str[i - 1] != '\0' && my_char_is_alpha(str[i - 1]) != 1)
            str[i] = my_chrcapitalize(str[i]);
        else
            str[i] = str[i];
    return str;
}
