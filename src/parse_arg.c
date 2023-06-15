/*
** EPITECH PROJECT, 2022
** palyndrome
** File description:
** arg_parser.c
*/

#include "my.h"

int check_for_trashs(my_func_args_t *args)
{
    for (int i = 1; i < args->ac; i++) {
        if (strcmp(args->av[i], "-h") != 0 && strcmp(args->av[i], "1") != 0 &&
            my_str_is_num(args->av[i]) == false)
            return 84;
    }
    return 0;
}

static void av_parser(my_func_args_t *args, int i)
{
    if (strcmp(args->av[i], "-h") == 0) {
        args->flag_h = true;
        print_help();
    }
    if (strcmp(args->av[i], "1") == 0) {
        args->flag_one = true;
    }
}

int parse_arg(int ac, char **av, my_func_args_t *args)
{
    init_everything_to_null(args);
    args->ac = ac;
    args->av = av;
    if (ac < 2)
        return error_wrong_args();
    for (int i = 1; i < ac; i++)
        av_parser(args, i);
    if (check_for_trashs(args) != 0)
        return error_wrong_args();
    return 0;
}
