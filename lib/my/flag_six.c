/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_six.c
*/

#include "../../include/my.h"

void complement_two(char *str)
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

char **get_full_file(char **str_input)
{
    int size = my_arrlen(str_input);
    char **full_file = new_double_array(size * 2 + 1);
    int count = 0;

    for (int i = 0; str_input[i] != NULL; i++) {
        if (str_input[i][0] == '>')
            continue;
        full_file[count] = new_array(strlen(str_input[i]));
        strcpy(full_file[count++], str_input[i]);
        full_file[count] = new_array(strlen(str_input[i]));
        full_file[count] = revstr(str_input[i]);
        complement_two(full_file[count]);
        strcpy(full_file[count++], full_file[count]);
    }
    full_file[count] = NULL;
    return full_file;
}

int flag_six(my_fasta_t *fastastruct)
{
    char **content = NULL;
    char **codon = NULL;
    char **amino = NULL;
    char **fullfile = NULL;

    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL)
        return 84;
    fullfile = get_full_file(content);
    codon = get_codon(fullfile);
    amino = get_amino(codon);
    sort_my_array(amino);
    for (int i = 0; amino[i] != NULL; i++)
        printf("%s\n", amino[i]);
    free(content);
    free(codon);
    free(amino);
    return 0;
}
