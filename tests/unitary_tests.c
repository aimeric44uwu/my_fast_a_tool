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

Test(every_amino, test_if_every_amino_YOU)
{
    char *input = strdup("TATCAGGTG");
    char *output = every_amino(input);
    cr_assert_eq(strcmp(output, "YQV"), 0);
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

Test(remove_duplicates, test_if_remove_duplicate_work)
{
    char **input = malloc(sizeof(char *) * 4);
    int count = 0;

    for (int i = 0; i < 3; i++)
        input[i] = malloc(sizeof(char) * 11);
    input[count++] = strdup("AA");
    input[count++] = strdup("BB");
    input[count++] = strdup("CC");
    input[count++] = strdup("AA");
    input[count] = NULL;
    remove_duplicates(input);
    cr_assert_eq(strcmp(input[0], "AA"), 0);
    cr_assert_eq(strcmp(input[1], "BB"), 0);
    cr_assert_eq(strcmp(input[2], "CC"), 0);
    cr_assert_eq(input[3], NULL);
}

Test(my_str_to_word_array, tes_if_my_str_to_word_array_works)
{
    char *input = strdup("AA BB CC DD");
    char **output = my_str_to_word_array(input, " ");
    cr_assert_eq(strcmp(output[0], "AA"), 0);
    cr_assert_eq(strcmp(output[1], "BB"), 0);
    cr_assert_eq(strcmp(output[2], "CC"), 0);
    cr_assert_eq(strcmp(output[3], "DD"), 0);
}

Test(my_str_is_num, test_if_my_str_is_num_false)
{
    char *input = strdup("AA BB CC DD");
    int output = my_str_is_num(input);
    cr_assert_eq(output, 0);
}

Test(my_str_is_num, test_if_my_str_is_num_true)
{
    char *input = strdup("1234567890");
    int output = my_str_is_num(input);
    cr_assert_eq(output, 1);
}

Test(my_max, test_if_my_max_works)
{
    int one = 12;
    int two = 13;
    int output = my_max(one, two);
    cr_assert_eq(output, 13);
}

Test(my_arrlen, test_if_my_arr_len_works)
{
    char *input = strdup("AA BB CC DD");
    char **output = my_str_to_word_array(input, " ");
    int len = my_arrlen(output);
    cr_assert_eq(len, 4);
}

Test(get_kmer, test_if_get_kmer_works)
{
    char *input = strdup("AAABBBCCDDDE");
    char **output = my_str_to_word_array(input, " ");
    char **kmer = get_kmer(output, 3);
    cr_assert_eq(strcmp(kmer[0], "AAA"), 0);
    cr_assert_eq(strcmp(kmer[1], "AAB"), 0);
    cr_assert_eq(strcmp(kmer[2], "ABB"), 0);
    cr_assert_eq(strcmp(kmer[3], "BBB"), 0);
    cr_assert_eq(strcmp(kmer[4], "BBC"), 0);
    cr_assert_eq(strcmp(kmer[5], "BCC"), 0);
    cr_assert_eq(strcmp(kmer[6], "CCD"), 0);
    cr_assert_eq(strcmp(kmer[7], "CDD"), 0);
    cr_assert_eq(strcmp(kmer[8], "DDD"), 0);
    cr_assert_eq(strcmp(kmer[9], "DDE"), 0);
    cr_assert_eq(kmer[10], NULL);
}

Test(get_codon, test_if_get_codon_works)
{
    char *input = strdup("ATGTANTATANNGATTAA ATGATGGNNGATTGA TGAATGATGTGGGGTTAG");
    char **output = my_str_to_word_array(input, " ");
    char **codon = get_codon(output);
    cr_assert_eq(strcmp(codon[0], "ATGTANTATANNGAT"), 0);
    cr_assert_eq(strcmp(codon[1], "ATGGNNGAT"), 0);
    cr_assert_eq(strcmp(codon[2], "ATGTGGGGT"), 0);
}

Test(get_amino, test_if_get_amino_works)
{
    char *input = strdup("ATGTAACATATGANNGATTAA ATGTTTTANGATTGA TGAATGATGTGGTACGGTTAG");
    char **output = my_str_to_word_array(input, " ");
    char **codon = get_codon(output);
    char **amino = get_amino(codon);
    cr_assert_eq(strcmp(amino[0], "MXD"), 0);
    cr_assert_eq(strcmp(amino[1], "MFXD"), 0);
    cr_assert_eq(strcmp(amino[2], "MWYG"), 0);

}


