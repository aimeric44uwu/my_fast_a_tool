/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** get_codon_util.c
*/

#include "../../include/my.h"

static void parse_between(char *codon, char *content, codon_t *codon_struct)
{
    char *buffer = new_array(codon_struct->end - codon_struct->start);
    int count = 0;
    int end = codon_struct->end - ((codon_struct->end - codon_struct->start) % 3);

    for (int i = codon_struct->start; i < end; i++)
        buffer[count++] = content[i];
    buffer[count] = '\0';
    strcpy(codon, buffer);
    free(buffer);
}

static void is_a_start(char *content, codon_t *codon_struct)
{
    int j = codon_struct->j;

    if (content[j] == 'A' && content[j + 1] == 'T' && content[j + 2] == 'G' && strncmp(&content[j + 3], "ATG", 3) != 0) {
        if (codon_struct->start != -1 && strncmp(&content[j + 5], "ATG", 3) != 0 ) {
        codon_struct->start = j;
        codon_struct->j += 2;
        } else {
            codon_struct->start = j;
            codon_struct->j += 5;
        }
    }
}

static void is_an_end(char *content, codon_t *codon_struct)
{    
    int j = codon_struct->j;

    if ((strncmp(&content[j], "TAA", 3) == 0 ||
        strncmp(&content[j], "TAG", 3) == 0 ||
        strncmp(&content[j], "TGA", 3) == 0)) {
        codon_struct->end = j;
    }
}

static void one_found(codon_t *codon_struct, char *content, char **codon)
{
    if (codon_struct->end != -1 && codon_struct->start != -1 && (codon_struct->end - codon_struct->start) > 2 && (codon_struct->end - codon_struct->start) % 3 == 0) {
        codon[codon_struct->count] = new_array(codon_struct->end - codon_struct->start);
        parse_between(codon[codon_struct->count], content, codon_struct);
        codon[codon_struct->count++][codon_struct->end - codon_struct->start] = '\0';
        codon_struct->start = -1;
        codon_struct->end = -1;
    }
}

int get_codon_ptwo_postwo(char *content, char **codon, int count)
{
    codon_t *codon_struct = malloc(sizeof(codon_t));
    codon_struct->found = false;
    codon_struct->start = -1;
    codon_struct->end = -1;
    codon_struct->count = count;
    codon_struct->j = 0;

    for (codon_struct->j; content[codon_struct->j] != '\0'; codon_struct->j++) {
        is_a_start(content, codon_struct);
        is_an_end(content, codon_struct);
        one_found(codon_struct, content, codon);
    }
    return codon_struct->count;
}
