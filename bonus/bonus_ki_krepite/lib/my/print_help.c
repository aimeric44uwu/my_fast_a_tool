/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** print_help.c
*/

#include "../../include/my.h"

int print_help(void)
{
    printf("USAGE\n\t./FASTAtools option [k]\n\nDESCRIPTION");
    printf("\n\toption 1: read FASTA from the standard input, write the DNA ");
    printf("sequences to the\n\t\tstandard output\n\toption 2: read FASTA ");
    printf("from the standard input, write the RNA sequences to the\n\t\t");
    printf("standard output\n\toption 3: read FASTA from the standard input, ");
    printf("write the reverse complement\n\t\tto the standard output\n\t");
    printf("option 4: read FASTA from the standard input, write the ");
    printf("k-mer list to the\n\t\tstandard output\n\toption 5: read FASTA ");
    printf("from the standard input, write the coding sequences\n\t\t");
    printf("list to the standard output\n\toption 6: read FASTA from the ");
    printf("standard input, write the amino acids list to\n\t\tthe ");
    printf("standard output\n\toption 7: read FASTA from the standard input ");
    printf("containing exactly 2 squences,\n\t\talign them and write the ");
    printf("result to the standard output\n\tk: size of the k-mers");
    printf("for option 4\n");
    return (0);
}
