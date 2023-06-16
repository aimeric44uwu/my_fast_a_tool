/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** get_input_file_content.c
*/

#include "../../include/my.h"

static char *get_file_content(FILE *file)
{
    char *buffer = NULL;
    long length;

    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        if (length == -1)
            return NULL;
        fseek(file, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, file);
            buffer[length] = '\0';
        }
    }
    return buffer;
}

int parse_fasta_file(my_func_args_t *args)
{
    args->inputfile = get_file_content(stdin);
    if (args->inputfile != NULL) {
        return 0;
    } else {
        printf("No input found.\n");
        return 84;
    }
    return 84;
}
