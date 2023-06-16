/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** test_bonus.c
*/

#include "my_bonus.h"

int main(void)
{
    char *str = strdup("@hey,how are you? 42words forty-two;fifty+one");
    printf("%p %p\n", str, my_strcapitalize_synthesis(str));
    printf("%s\n", my_strcapitalize_synthesis(str));
    return 0;
}
