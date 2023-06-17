##
## EPITECH PROJECT, 2022
## B-SYN-200-NAN-2-1-sbmlparser-aimeric.rouyer
## File description:
## Makefile
##

SRC		=	flag_four.c \
			flag_two.c \
			print_help.c \
			get_codon_util.c \
			my_str_to_word_array.c \
			my_revstr.c \
			flag_six.c \
			free_matrix.c \
			get_input_file_content.c \
			flag_five.c \
			my_str_is_a_number.c \
			error_occured.c \
			sort_my_array.c \
			flag_five_utils.c \
			remove_duplicate.c \
			my_max.c \
			get_codon_util_two.c \
			my_malloc.c \
			flag_seven.c \
			flag_three.c \
			flag_one.c \
			parse_fasta_content.c \
			print_matrix.c \
			every_amino.c \
			my_arrlen.c \

OBJ		=     	$(SRC:.c=.o)

NAME	=    	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
