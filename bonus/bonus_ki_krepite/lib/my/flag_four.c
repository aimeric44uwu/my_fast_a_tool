/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_four.c
*/

#include "../../include/my.h"

static void parse_kmer(char *kmer, char *content, int j, int nb_kmer)
{
    for (int k = 0; content[j + k] != '\0', k < nb_kmer; k++) {
        kmer[k] = content[j + k];
    }
}

static int count_kmer(char **content, int nb_kmer)
{
    int count = 0;
    for (int i = 0; content[i] != NULL; i++) {
        if (strlen(content[i]) < nb_kmer || content[i][0] == '>')
            continue;
        for (int j = 0; content[i][j] != '\0' &&
            content[i][j + nb_kmer - 1] != '\0'; j++) {
            count++;
        }
    }
    return count;
}

char **get_kmer(char **content, int nb_kmer)
{
    char **kmer = new_double_array(count_kmer(content, nb_kmer) + 1);
    int count = 0;

    if (kmer == NULL)
        return NULL;
    for (int i = 0; content[i] != NULL; i++) {
        if (strlen(content[i]) < nb_kmer || content[i][0] == '>')
            continue;
        for (int j = 0; content[i][j] != '\0' &&
            content[i][j + nb_kmer - 1] != '\0'; j++) {
            kmer[count] = new_array(nb_kmer + 1);
            parse_kmer(kmer[count], content[i], j, nb_kmer);
            kmer[count][nb_kmer + 1] = '\0';
            count++;
        }
    }
    free(content);
    return kmer;
}

int flag_four(my_fasta_t *fastastruct)
{
    char **content = NULL;
    char **kmer = NULL;
    char **final = NULL;

    if (fastastruct->args.inputfile == NULL)
        return (error_wrong_args());
    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL)
        return 84;
    kmer = get_kmer(content, fastastruct->args.nb_kmer);
    remove_duplicates(kmer);
    sort_my_array(kmer);
    for (int i = 0; kmer[i] != NULL; i++) {
        printf("%s\n", kmer[i]);
    }
    return 0;
}
