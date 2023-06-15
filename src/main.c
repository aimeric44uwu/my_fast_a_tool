/*
** EPITECH PROJECT, 2022
** palyndrome
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    my_fasta_t *fasta = malloc(sizeof(my_fasta_t));

    if (parse_arg(ac, av, &fasta->args) != 0)
        exit(84);
    if (exec_flags(fasta) != 0)
        exit(84);
    return (0);
}
