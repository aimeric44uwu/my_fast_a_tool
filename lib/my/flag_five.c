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
    char **fullfile = NULL;

    if (fastastruct->args.inputfile == NULL)
        return (error_wrong_args());
    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL)
        return 84;
    fullfile = get_full_file(content);
    codon = get_codon(fullfile);
    sort_my_array(codon);
    for (int i = 0; codon[i] != NULL; i++) {
        printf("%s\n", codon[i]);
    }
    return 0;
}
