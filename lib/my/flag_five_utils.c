/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_five_utils.c
*/

#include "../../include/my.h"

char **get_codon(char **content)
{
    int count = 0;
    int size = 0;
    char **codon = new_double_array(1000);

    for (int i = 0; content[i] != NULL; i++) {
        if (content[i][0] == '>' || content[i][strlen(content[i]) - 1] == '>')
            continue;
        count = get_codon_ptwo_postwo(content[i], codon, count);
    }
    codon[count] = NULL;
    return codon;
}
