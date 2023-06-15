/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** exec_flags.c
*/

#include "my.h"

int exec_flags(my_fasta_t *fastastruct)
{
    if (fastastruct->args.flag_one == true)
        return flag_one(fastastruct);
    if (fastastruct->args.flag_two == true)
        return flag_two(fastastruct);
    if (fastastruct->args.flag_three == true)
        return flag_three(fastastruct);
    return 84;
}
