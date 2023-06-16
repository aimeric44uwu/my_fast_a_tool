/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_one.c
*/

#include "../../include/my.h"

int flag_one(my_fasta_t *fastastruct)
{
    char **content = NULL;

    if (fastastruct->args.inputfile == NULL)
        return (error_wrong_args());
    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL)
        return 84;
    for (int i = 0; content[i] != NULL; i++) {
        printf("%s\n", content[i]);
    }
    return 0;
}
