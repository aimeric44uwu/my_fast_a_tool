/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** print_matrix.c
*/

#include "../../include/my.h"

static void print_i_colored(int matrix, int min, int max)
{
    if (matrix > 0 ) {
        printf("\033[0m|\033[32m %d\t\033[0m",matrix);
        return;
    }
    if (matrix < 0 && matrix < ( min / 2 )) {
        printf("\033[0m|\033[31m %d\t\033[0m",matrix);
        return;
    }
    if (matrix < 0 && matrix >= ( min / 2 )) {
        printf("\033[0m|\033[33m %d\t\033[0m",matrix);
        return;
    }
    printf("\033[0m| %d\t",matrix);
}

static void print_header(int len2, char *seq2)
{
    printf("\t|\t");
    for (int j = 0; j <= len2; j++)
        printf("|   %c  \t", seq2[j]);
    printf("\n");
    for (int j = 0; j <= (len2 * 10) - 10; j++)
        printf("-");
    printf("\n\t");
}

static void print_bottom(int len2)
{
    printf("\n");
    for (int j = 0; j <= (len2 * 10) - 10; j++)
        printf("-");
    printf("\n");
}

void print_matrix(int **matrix, char *seq1, char *seq2)
{
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int min = 0;
    int max = 0;

    print_header(len2, seq2);
    for (int i = 0; i < len1 + 1 ; i++)
        for (int j = 0; j < len2 + 1; j++) {
            max = my_max(matrix[j][i], max);
            min = my_min(matrix[j][i], min);
        }
    for (int i = 0; i < len1 + 1 ; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            print_i_colored(matrix[j][i], min, max);
        }
        printf("|\n  %c\t", seq1[i]);
    }
    print_bottom(len2);
}
