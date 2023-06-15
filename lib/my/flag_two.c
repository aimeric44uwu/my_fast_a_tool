/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_two.c
*/

#include "../../include/my.h"

static void replace_t_by_u(char *content)
{
    for (int i = 0; content[i] != '\0'; i++) {
        if (content[i] == '>')
            break;
        if (content[i] == 'T')
            content[i] = 'U';
    }
}

int flag_two(my_fasta_t *fastastruct)
{
    char **content = NULL;

    if (fastastruct->args.inputfile == NULL)
        return (error_wrong_args());
    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL)
        return 84;
    for (int i = 0; content[i] != NULL; i++)
        replace_t_by_u(content[i]);
    for (int i = 0; content[i] != NULL; i++)
        printf("%s\n", content[i]);
    return 0;
}
