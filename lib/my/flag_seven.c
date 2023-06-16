/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** flag_seven.c
*/

#include "../../include/my.h"

int update_needleman_matrix(char *seq1, char *seq2,
needlemanwunsch_t *nw)
{
    if (seq1[nw->i - 1] == seq2[nw->j - 1])
        nw->score = nw->score_param;
    else
        nw->score = nw->mismatch;
    nw->maxscore = nw->matrix[nw->i - 1][nw->j - 1] + nw->score;
    if (nw->maxscore < nw->matrix[nw->i - 1][nw->j] + nw->gap)
        nw->maxscore = nw->matrix[nw->i - 1][nw->j] + nw->gap;
    if (nw->maxscore < nw->matrix[nw->i][nw->j - 1] + nw->gap)
        nw->maxscore = nw->matrix[nw->i][nw->j - 1] + nw->gap;
    return nw->maxscore;
}

int needleman_wunsch(char *seq1, char *seq2, needlemanwunsch_t *nw)
{
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int result = 0;

    nw->matrix = malloc(sizeof(int *) * (len2 + 1));
    for (int i = 0; i <= len2; i++)
        nw->matrix[i] = malloc(sizeof(int) * (len1 + 1));
    for (int i = 0; i <= len1; i++)
        nw->matrix[0][i] = nw->gap * i;
    for (int j = 0; j <= len2; j++)
        nw->matrix[j][0] = nw->gap * j;
    for (nw->i = 1; nw->i <= len2; nw->i++)
        for (nw->j = 1; nw->j <= len1; nw->j++)
            nw->matrix[nw->i][nw->j] =
                update_needleman_matrix(seq1, seq2, nw);
    result = nw->matrix[len2][len1];
    for (int i = 0; i <= len2; i++)
        free(nw->matrix[i]);
    free(nw->matrix);
    return result;
}

void init_nw(needlemanwunsch_t *nw)
{
    nw->gap = -1;
    nw->score_param = 1;
    nw->mismatch = -1;
    nw->score = 0;
    nw->maxscore = 0;
}

int get_dna(char **content, char **dna)
{
    int count = 0;

    for (int i = 0; content[i] != NULL; i++) {
        if (content[i][0] == '>')
            continue;
        dna[count++] = content[i];
        if (count > 2)
            return 84;
    }
    dna[count] = NULL;
    return 0;
}

int flag_seven(my_fasta_t *fastastruct)
{
    char **content = NULL;
    char **dna = new_double_array(3);
    int score = 0;
    needlemanwunsch_t *nw = malloc(sizeof(needlemanwunsch_t));

    content = parse_fasta_content(fastastruct->args.inputfile);
    if (content == NULL || nw == NULL)
        return 84;
    init_nw(nw);
    if (get_dna(content, dna) != 0)
        return 84;
    if (strlen(dna[0]) > strlen(dna[1]))
        score = needleman_wunsch(dna[0], dna[1], nw);
    else
        score = needleman_wunsch(dna[1], dna[0], nw);
    free(nw);
    printf("Alignment score: %d\n", score);
    return 0;
}
