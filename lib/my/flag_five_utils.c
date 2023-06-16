/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_five_utils.c
*/

#include "../../include/my.h"

static void parse_between(char *codon, char *content, int start, int end)
{
    char *buffer = new_array(end - start);
    int count = 0;

    for (int i = start; i < end; i++)
        buffer[count++] = content[i];
    buffer[count] = '\0';
    strcpy(codon, buffer);
    free(buffer);
}

static int is_a_start(int start, char *content, int j)
{
    if (strncmp(content, "ATG", 3) == 0 &&
        (strncmp(&content[1], "TAA", 3) != 0 &&
        strncmp(&content[1], "TAG", 3) != 0 &&
        strncmp(&content[1], "TGA", 3) != 0) &&
        (strncmp(&content[2], "TAA", 3) != 0 &&
        strncmp(&content[2], "TAG", 3) != 0 &&
        strncmp(&content[2], "TGA", 3) != 0)) {
            start = j;
    }
    return start;
}

static int is_an_end(int end, char *content, int j)
{
    if ((strncmp(content, "TAA", 3) == 0 ||
        strncmp(content, "TAG", 3) == 0 ||
        strncmp(content, "TGA", 3) == 0)) {
        end = j;
    }
    return end;
}

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

char **get_codon(char **content)
{
    int count = 0;
    int size = 0;
    char **codon = new_double_array(1000);

    for (int i = 0; content[i] != NULL; i++) {
        if (content[i][0] == '>')
            continue;
        count = get_codon_ptwo(content[i], codon, count);
    }
    codon[count] = NULL;
    return codon;
}
