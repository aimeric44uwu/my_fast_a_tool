/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** requirement.c
*/

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

static void parse_my_input(char const *input, char *output, int i)
{
    if (input[i - 1] != '\0')
        if (input[i - 1] == ' ' || input[i - 1] == '-' || input[i - 1] == '+')
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

    for (int i = 0; i < size || str[i] != '\0'; i++)
        parse_my_input(str, result, i);
    return result;
}
