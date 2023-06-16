/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** every_amino.c
*/

#include "../../include/my.h"

static void every_amino_pfour(char *ln, char *aminolist, int i)
{

    if (strncmp(&ln[i], "TGG", 3) == 0)
        strcat(aminolist, "W");
    if (strncmp(&ln[i], "TAT", 3) == 0 || strncmp(&ln[i], "TAC", 3) == 0)
        strcat(aminolist, "Y");
    if (strstr(&ln[i], "N") != NULL)
        strcat(aminolist, "X");
}

static void every_amino_pthree(char *ln, char *aminolist, int i)
{
    if (strncmp(&ln[i], "CCT", 3) == 0 || strncmp(&ln[i], "CCC", 3) == 0 ||
        strncmp(&ln[i], "CCA", 3) == 0 || strncmp(&ln[i], "CCG", 3) == 0)
        strcat(aminolist, "P");
    if (strncmp(&ln[i], "CAA", 3) == 0 || strncmp(&ln[i], "CAG", 3) == 0)
        strcat(aminolist, "Q");
    if (strncmp(&ln[i], "AGA", 3) == 0 || strncmp(&ln[i], "AGG", 3) == 0 ||
        strncmp(&ln[i], "CGT", 3) == 0 || strncmp(&ln[i], "CGC", 3) == 0 ||
        strncmp(&ln[i], "CGA", 3) == 0 || strncmp(&ln[i], "CGG", 3) == 0)
        strcat(aminolist, "R");
    if (strncmp(&ln[i], "TCT", 3) == 0 || strncmp(&ln[i], "TCC", 3) == 0 ||
        strncmp(&ln[i], "TCA", 3) == 0 || strncmp(&ln[i], "TCG", 3) == 0 ||
        strncmp(&ln[i], "AGT", 3) == 0 || strncmp(&ln[i], "AGC", 3) == 0)
        strcat(aminolist, "S");
    if (strncmp(&ln[i], "ACT" , 3) == 0 || strncmp(&ln[i], "ACC", 3) == 0 ||
        strncmp(&ln[i], "ACA", 3) == 0 || strncmp(&ln[i], "ACG", 3) == 0)
        strcat(aminolist, "T");
    if (strncmp(&ln[i], "GTT", 3) == 0 || strncmp(&ln[i], "GTC", 3) == 0 ||
        strncmp(&ln[i], "GTA", 3) == 0 || strncmp(&ln[i], "GTG", 3) == 0)
        strcat(aminolist, "V");
    every_amino_pfour(ln, aminolist, i);
}

static void every_amino_ptwo(char *ln, char *aminolist, int i)
{
    if (strncmp(&ln[i], "GGT", 3) == 0 || strncmp(&ln[i], "GGC", 3) == 0 ||
        strncmp(&ln[i], "GGA", 3) == 0 || strncmp(&ln[i], "GGG", 3) == 0)
        strcat(aminolist, "G");
    if (strncmp(&ln[i], "CAT", 3) == 0 || strncmp(&ln[i], "CAC", 3) == 0)
        strcat(aminolist, "H");
    if (strncmp(&ln[i], "ATT", 3) == 0 || strncmp(&ln[i], "ATC", 3) == 0 ||
        strncmp(&ln[i], "ATA", 3) == 0)
        strcat(aminolist, "I");
    if (strncmp(&ln[i], "AAA", 3) == 0 || strncmp(&ln[i], "AAG", 3) == 0)
        strcat(aminolist, "K");
    if (strncmp(&ln[i], "TTA", 3) == 0 || strncmp(&ln[i], "TTG", 3) == 0 ||
        strncmp(&ln[i], "CTT", 3) == 0 || strncmp(&ln[i], "CTC", 3) == 0 ||
        strncmp(&ln[i], "CTA", 3) == 0 || strncmp(&ln[i], "CTG", 3) == 0)
        strcat(aminolist, "L");
    if (strncmp(&ln[i], "ATG", 3) == 0)
        strcat(aminolist, "M");
    if (strncmp(&ln[i], "AAT", 3) == 0 || strncmp(&ln[i], "AAC", 3) == 0)
        strcat(aminolist, "N");
    every_amino_pthree(ln, aminolist, i);
}

char *every_amino(char *ln)
{
    char *aminolist = new_array(strlen(ln) + 1);
    strcpy(aminolist, "");
    for (int i = 0; ln[i] != '\0'; i += 3) {
        if (strncmp(&ln[i], "GCT", 3) == 0 || strncmp(&ln[i], "GCC", 3) == 0 ||
            strncmp(&ln[i], "GCA", 3) == 0 || strncmp(&ln[i], "GCG", 3) == 0)
            strcat(aminolist, "A");
        if (strncmp(&ln[i], "TGT", 3) == 0 || strncmp(&ln[i], "TGC", 3) == 0)
            strcat(aminolist, "C");
        if (strncmp(&ln[i], "GAT", 3) == 0 || strncmp(&ln[i], "GAC", 3) == 0)
            strcat(aminolist, "D");
        if (strncmp(&ln[i], "GAA", 3) == 0 || strncmp(&ln[i], "GAG", 3) == 0)
            strcat(aminolist, "E");
        if (strncmp(&ln[i], "TTT", 3) == 0 || strncmp(&ln[i], "TTC", 3) == 0)
            strcat(aminolist, "F");
        every_amino_ptwo(ln, aminolist, i);
    }
    aminolist[strlen(ln)] = '\0';
    return aminolist;
}
