/*
** EPITECH PROJECT, 2022
** palyndrome
** File description:
** my.h
*/

#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct my_func_args_s {
    int ac;
    char **av;
    int nb_arguments;
    bool flag_h;
    bool flag_one;
    bool is_trash;
} my_func_args_t;

typedef struct my_fasta_s {
    my_func_args_t args;
} my_fasta_t;

int print_help(void);
int parse_arg(int ac, char **av, my_func_args_t *args);
bool my_str_is_num(char *str);
void init_everything_to_null(my_func_args_t *args);
int error_wrong_args(void);
