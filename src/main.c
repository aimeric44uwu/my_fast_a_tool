/*
** EPITECH PROJECT, 2022
** palyndrome
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac == 2)
        if (strcmp(av[1], "-h") == 0)
            return print_help();
    return (0);
}
