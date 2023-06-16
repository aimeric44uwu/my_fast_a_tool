/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_six.c
*/

#include "../../include/my.h"

char **get_amino(char **content)
{
    char **tmp = new_double_array(my_arrlen(content) + 1);
    int count = 0;

    for (int i = 0; content[i] != NULL; i++) {
        if (content[i][0] == '>')
            continue;
        tmp[count++] = every_amino(content[i]);
    }
    tmp[count] = NULL;
    return tmp;
}

int flag_six(my_fasta_t *fastastruct)
{
    char **content = NULL;
    char **codon = NULL;
    char **amino = NULL;

    if (fastastruct->args.inputfile == NULL)
        return (error_wrong_args());
    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL)
        return 84;
    codon = get_codon(content);
    amino = get_amino(codon);
    sort_my_array(amino);
    for (int i = 0; amino[i] != NULL; i++)
        printf("%s\n", amino[i]);
    return 0;
}
