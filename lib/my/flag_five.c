/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_five.c
*/

#include "../../include/my.h"

static int get_codon_ptwo(char *content, char **codon, int count)
{
    int start = -1;
    int end = -1;
    int oldend = 0;

    for (int j = 0; content[j] != '\0'; j++) {
        oldend = end;
        start = is_a_start(start, &content[j], j);
        end = is_an_end(end, &content[j], j);
        if (end != oldend && end != -1 && start != -1 && (end - start) > 5) {
            codon[count] = new_array(end - start);
            parse_between(codon[count], content, start, end);
            codon[count++][end - start] = '\0';
            start = -1;
            end = -1;
        }
    }
    return count;
}

static char **get_codon(char **content)
{
    int count = 0;
    int size = 0;
    char **codon = new_double_array(100);

    for (int i = 0; content[i] != NULL; i++) {
        if (content[i][0] == '>')
            continue;
        count = get_codon_ptwo(content[i], codon, count);
    }
    codon[count] = NULL;
    return codon;
}

int flag_five(my_fasta_t *fastastruct)
{
    char **content = NULL;
    char **codon = NULL;

    if (fastastruct->args.inputfile == NULL)
        return (error_wrong_args());
    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL)
        return 84;
    codon = get_codon(content);
    for (int i = 0; codon[i] != NULL; i++) {
        printf("%s\n", codon[i]);
    }
    return 0;
}
