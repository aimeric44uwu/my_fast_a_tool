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

static void parse_my_input(char const *input, char *output, int i)
{
    if (input[i - 1] != '\0')
        if (my_char_is_alpha(input[i - 1]) != 1 )
            output[i] = my_chrcapitalize(input[i]);
        else
            output[i] = input[i];
    else
        output[i] = my_chrcapitalize(input[i]);
}

char *my_strcapitalize_synthesis(char *str)
{
    int size = my_strlen(str);
    char *result = malloc(sizeof(char) * (size + 1));

    if (result == NULL || str == NULL || size == 0)
        return NULL;
    for (int i = 0; i < size || str[i] != '\0'; i++)
        parse_my_input(str, result, i);
    result[size] = '\0';
    return result;
}
