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
            my_str_is_num(args->av[i]) == false &&
            strcmp(args->av[i], "2") != 0 && strcmp(args->av[i], "5") != 0 &&
            strcmp(args->av[i], "3") != 0 && strcmp(args->av[i], "6") != 0 &&
            strcmp(args->av[i], "4") != 0 && strcmp(args->av[i], "7") != 0 &&
            strcmp(args->av[i - 1], "4") != 0)
                return 84;
    }
    return 0;
}

static void av_parser_two(my_func_args_t *args, int i)
{
    if (strcmp(args->av[i], "4") == 0) {
        args->flag_four = true;
        if (args->av[i + 1] != NULL)
            args->nb_kmer = atoi(args->av[i + 1]);
    }
    if (strcmp(args->av[i], "5") == 0)
        if (args->av[i - 1] != NULL && strcmp(args->av[i - 1], "4") != 0)
            args->flag_five = true;
    if (strcmp(args->av[i], "6") == 0)
        if (args->av[i - 1] != NULL && strcmp(args->av[i - 1], "4") != 0)
            args->flag_six = true;
    if (strcmp(args->av[i], "7") == 0)
        if (args->av[i - 1] != NULL && strcmp(args->av[i - 1], "4") != 0)
            args->flag_seven = true;
}

static void av_parser(my_func_args_t *args, int i)
{
    if (strcmp(args->av[i], "-h") == 0) {
        args->flag_h = true;
        print_help();
    }
    if (strcmp(args->av[i], "1") == 0)
        if (args->av[i - 1] != NULL && strcmp(args->av[i - 1], "4") != 0)
            args->flag_one = true;
    if (strcmp(args->av[i], "2") == 0)
        if (args->av[i - 1] != NULL && strcmp(args->av[i - 1], "4") != 0)
            args->flag_two = true;
    if (strcmp(args->av[i], "3") == 0)
        if (args->av[i - 1] != NULL && strcmp(args->av[i - 1], "4") != 0)
            args->flag_three = true;
    return av_parser_two(args, i);
}

static int verify_given_flags(my_func_args_t *args)
{
    int count = 0;
    if (args->flag_one == true)
        count++;
    if (args->flag_two == true)
        count++;
    if (args->flag_three == true)
        count++;
    if (args->flag_four == true)
        count++;
    if (args->flag_five == true)
        count++;
    if (args->flag_six == true)
        count++;
    if (args->flag_seven == true)
        count++;
    if (count > 1)
        return 84;
    return 0;
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
    if (args->flag_h == true) {
        return 0;
    } else {
        if (parse_fasta_file(args) != 0)
            return 84;
    }
    if (check_for_trashs(args) != 0)
        return error_wrong_args();
    if (verify_given_flags(args) != 0)
        return error_wrong_args();
    return 0;
}
