/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_three.c
*/

#include "../../include/my.h"

static void complement(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'A') {
            str[i] = 'T';
            continue;
        }
        if (str[i] == 'T') {
            str[i] = 'A';
            continue;
        }
        if (str[i] == 'C') {
            str[i] = 'G';
            continue;
        }
        if (str[i] == 'G') {
            str[i] = 'C';
            continue;
        }
    }
}

int flag_three(my_fasta_t *fastastruct)
{
    char **content = NULL;

    if (fastastruct->args.inputfile == NULL)
        return (error_wrong_args());
    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL)
        return 84;
    for (int i = 0; content[i] != NULL; i++)
        if (content[i][0] != '>')
            content[i] = revstr(content[i]);
    for (int i = 0; content[i] != NULL; i++)
        if (content[i][0] != '>')
            complement(content[i]);
    for (int i = 0; content[i] != NULL; i++) {
        printf("%s\n", content[i]);
    }
    return 0;
}
