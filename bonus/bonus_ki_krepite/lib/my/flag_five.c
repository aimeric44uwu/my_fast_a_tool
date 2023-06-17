/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_five.c
*/

#include "../../include/my.h"

int flag_five(my_fasta_t *fastastruct)
{
    char **content = NULL;
    char **codon = NULL;
    char **revcodon = NULL;
    char **revcontent = NULL;

    if (fastastruct->args.inputfile == NULL)
        return (error_wrong_args());
    content = parse_fasta_content(fastastruct->args.inputfile);
    revcontent = parse_fasta_content(revstr(fastastruct->args.inputfile));

    if (content == NULL || revcontent == NULL)
        return 84;
    codon = get_codon(content);
    revcodon = get_codon(revcontent);
    for (int i = 0; codon[i] != NULL; i++)
        printf("%s\n", codon[i]);
    for (int i = 0; revcodon[i] != NULL; i++)
        printf("%s\n", revcodon[i]);
    return 0;
}
