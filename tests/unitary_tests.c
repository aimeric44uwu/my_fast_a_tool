/*
** EPITECH PROJECT, 2022
** test_criterion
** File description:
** test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../include/my.h"


void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(every_amino, test_if_every_amino_MQS)
{
    char *input = strdup("ATGCAGAGT");
    char *output = every_amino(input);
    cr_assert_eq(strcmp(output, "MQS"), 0);
}

Test(every_amino, test_if_every_amino_ML)
{
    char *input = strdup("ATGCTT");
    char *output = every_amino(input);
    cr_assert_eq(strcmp(output, "ML"), 0);
}

Test(every_amino, test_if_every_amino_ME)
{
    char *input = strdup("ATGGAA");
    char *output = every_amino(input);
    cr_assert_eq(strcmp(output, "ME"), 0);
}

Test(every_amino, test_if_every_amino_NEVER)
{
    char *input = strdup("AATGAAGTTGAACGA");
    char *output = every_amino(input);
    cr_assert_eq(strcmp(output, "NEVER"), 0);
}

Test(every_amino, test_if_every_amino_GONNA)
{
    char *input = strdup("GGTCAGAACAATGCA");
    char *output = every_amino(input);
    cr_assert_eq(strcmp(output, "GQNNA"), 0);
}

Test(every_amino, test_if_every_amino_GIVE)
{
    char *input = strdup("GGCATAGTAGAG");
    char *output = every_amino(input);
    cr_assert_eq(strcmp(output, "GIVE"), 0);
}

Test(every_amino, test_if_every_amino_UP)
{
    char *input = strdup("GTGCCC");
    char *output = every_amino(input);
    cr_assert_eq(strcmp(output, "VP"), 0);
}

Test(file_parsing, test_if_parsing_bad_file)
{
    char *input = strdup(">at1200347|szg01\natgatgctccctgatgtataatgccgcntctacttaaaatctcgatgctgccactgtgtctt\ngctatgcggcggctacggggtattanccgatcaaatctgctgatcatctcgctccttnca\n\n>at1102337|szg02\natGATGctccctgatgtgatgcagtNgagtacacttaAAATCTCGATGCtgccacgctgatcgtct\nagctatgcggcggNtacggggtattaCCGATCAAgat\n>at2430958|szg01\n\nATGATGCTCCCTGATGTATAATNCCGC\nTATCTACTTAAAATNTCGATGCTGCCACTGTGTCTTTCT\nAGCTATGCGGCGNCTACGGGGTATTACCGATCAAATCTGCTGATCATCTCGNNCCTTGCTTCA");
    char **output = parse_fasta_content(input);
    int count = 0;

    cr_assert_eq(strcmp(output[count++], ">at1200347|szg01"), 0);
    cr_assert_eq(strcmp(output[count++], "ATGATGCTCCCTGATGTATAATGCCGCNTCTACTTAAAATCTCGATGCTGCCACTGTGTCTTGCTATGCGGCGGCTACGGGGTATTANCCGATCAAATCTGCTGATCATCTCGCTCCTTNCA"), 0);
    cr_assert_eq(strcmp(output[count++], ">at1102337|szg02"), 0);
    cr_assert_eq(strcmp(output[count++], "ATGATGCTCCCTGATGTGATGCAGTNGAGTACACTTAAAATCTCGATGCTGCCACGCTGATCGTCTAGCTATGCGGCGGNTACGGGGTATTACCGATCAAGAT"), 0);
    cr_assert_eq(strcmp(output[count++], ">at2430958|szg01"), 0);
    cr_assert_eq(strcmp(output[count++], "ATGATGCTCCCTGATGTATAATNCCGCTATCTACTTAAAATNTCGATGCTGCCACTGTGTCTTTCTAGCTATGCGGCGNCTACGGGGTATTACCGATCAAATCTGCTGATCATCTCGNNCCTTGCTTCA"), 0);
}

Test(replace_t_by_u, test_if_parsing_bad_file_T_by_U)
{
    char *input = strdup("TTTTTTTTTTT");
    char *output = strdup("UUUUUUUUUUU");
    replace_t_by_u(input);
    cr_assert_eq(strcmp(output, input), 0);
}

Test(replace_t_by_u, test_if_parsing_bad_file_T_by_U_two)
{
    char *input = strdup("TTUUAACCTT");
    char *output = strdup("UUUUAACCUU");
    replace_t_by_u(input);
    cr_assert_eq(strcmp(output, input), 0);
}

Test(sort_array, test_if_sort_my_array_work_easy)
{
    char **input = malloc(sizeof(char *) * 4);
    int count = 0;

    for (int i = 0; i < 3; i++)
        input[i] = malloc(sizeof(char) * 4);
    input[count++] = strdup("ABA");
    input[count++] = strdup("BAB");
    input[count++] = strdup("BAA");
    input[count] = NULL;
    sort_my_array(input);
    cr_assert_eq(strcmp(input[0], "ABA"), 0);
    cr_assert_eq(strcmp(input[1], "BAA"), 0);
    cr_assert_eq(strcmp(input[2], "BAB"), 0);
}

Test(sort_array, test_if_sort_my_array_work_hard)
{
    char **input = malloc(sizeof(char *) * 4);
    int count = 0;

    for (int i = 0; i < 3; i++)
        input[i] = malloc(sizeof(char) * 11);
    input[count++] = strdup("AAAAAAAB");
    input[count++] = strdup("AAAAAAAAB");
    input[count++] = strdup("AAAAAAB");
    input[count++] = strdup("ZAAAAAAAAAA");
    input[count] = NULL;
    sort_my_array(input);
    cr_assert_eq(strcmp(input[0], "AAAAAAAAB"), 0);
    cr_assert_eq(strcmp(input[1], "AAAAAAAB"), 0);
    cr_assert_eq(strcmp(input[2], "AAAAAAB"), 0);
    cr_assert_eq(strcmp(input[3], "ZAAAAAAAAAA"), 0);
}

Test(revstr, test_if_revstr_works_easy)
{
    char *input = strdup("AAAAAAAB");
    char *output = revstr(input);
    cr_assert_eq(strcmp(output, "BAAAAAAA"), 0);
}

Test(revstr, test_if_revstr_works_hard)
{
    char *input = strdup("ABCDEFGH");
    char *output = revstr(input);
    cr_assert_eq(strcmp(output, "HGFEDCBA"), 0);
}

Test(complement, test_if_complement_works_easy)
{
    char *input = strdup("ATATGCAGAGTTAGTN");
    char *output = revstr(input);
    complement(output);
    cr_assert_eq(strcmp(output, "NACTAACTCTGCATAT"), 0);
}

Test(complement, test_if_complement_works_hard)
{
    char *input = strdup("NTGAC");
    char *output = revstr(input);
    complement(output);
    cr_assert_eq(strcmp(output, "GTCAN"), 0);
}
