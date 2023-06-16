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
    if (fastastruct->args.flag_four == true && fastastruct->args.nb_kmer > 0)
        return flag_four(fastastruct);
    if (fastastruct->args.flag_five == true)
        return flag_five(fastastruct);
    if (fastastruct->args.flag_six == true)
        return flag_six(fastastruct);
    if (fastastruct->args.flag_seven == true)
        return flag_seven(fastastruct);
    return 84;
}
