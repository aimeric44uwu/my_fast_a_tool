/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_five_utils.c
*/

#include "../../include/my.h"

void parse_between(char *codon, char *content, int start, int end)
{
    char *buffer = new_array(end - start);
    int count = 0;

    for (int i = start; i < end; i++) {
        buffer[count++] = content[i];
        }
    buffer[count] = '\0';
    strcpy(codon, buffer);
    free(buffer);
}

int is_a_start(int start, char *content, int j)
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

int is_an_end(int end, char *content, int j)
{
    if ((strncmp(content, "TAA", 3) == 0 ||
        strncmp(content, "TAG", 3) == 0 ||
        strncmp(content, "TGA", 3) == 0)) {
        end = j;
    }
    return end;
}
