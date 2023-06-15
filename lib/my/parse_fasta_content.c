/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** parse_fasta_file.c
*/

#include "../../include/my.h"

static void parse_in_result(char *content, char *parsed)
{
    bool back_to_line = true;
    int y = 0;

    for (int i = 0; content[i] != '\0'; i++) {
        if (content[i] != '\n')
            parsed[y++] = content[i];
        if (content[i] == '\n' && content[i + 1] == '>') {
            parsed[y++] = content[i];
            back_to_line = true;
        }
        if (content[i] == '\n' && content[i + 1] != '>' &&
            back_to_line == true) {
            parsed[y++] = content[i];
            back_to_line = false;
        }
    }
}

static bool is_a_good_char(char chr)
{
    if (chr == 'A' || chr == 'T' || chr == 'G' || chr == 'C' || chr == 'a' ||
        chr == 't' || chr == 'g' || chr == 'c' || chr == '\n')
        return true;
    return false;
}

static char my_chrcapitalize(char chr)
{
    if ( chr >= 97 && chr <= 122 )
        chr = chr - 32;
    return chr;
}

static char *remove_useless_char(char *content)
{
    char *result = new_array(strlen(content) + 1);
    int y = 0;
    bool skip = true;

    for (int i = 0; content[i] != '\0'; i++) {
        if (content[i] == '\n')
            skip = false;
        if (content[i] == '>')
            skip = true;
        if (content[i] != ' ' && content[i] != '\t' &&
            is_a_good_char(content[i]) == true && skip == false)
            result[y++] = my_chrcapitalize(content[i]);
        if (skip == true)
            result[y++] = content[i];
    }
    result[y] = '\0';
    return result;
}

char **parse_fasta_content(char *content)
{
    char *parsed = new_array(strlen(content) + 1);
    char **result = NULL;
    int buffsize = 0;

    parse_in_result(content, parsed);
    parsed = remove_useless_char(parsed);
    if (parsed == NULL)
        return NULL;
    result = my_str_to_word_array(parsed, "\n");
    return result;
}
