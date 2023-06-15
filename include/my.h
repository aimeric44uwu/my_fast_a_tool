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
    char *inputfile;
    char **parsed_file;
    int nb_arguments;
    bool flag_h;
    bool flag_one;
    bool flag_two;
    bool flag_three;
    bool flag_four;
    int nb_kmer;
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
int parse_fasta_file(my_func_args_t *args);
int exec_flags(my_fasta_t *fastastruct);
char **parse_fasta_content(char *content);
char **my_str_to_word_array(char const *str, char const *sep);
char *new_array(int size);
char **new_double_array(int size);
int flag_one(my_fasta_t *fastastruct);
int flag_two(my_fasta_t *fastastruct);
int flag_three(my_fasta_t *fastastruct);
char *revstr(char *str1);
int flag_four(my_fasta_t *fastastruct);
int my_arrlen(char **str);
void remove_duplicates(char **to_treat);
void sort_my_array(char **to_sort);
