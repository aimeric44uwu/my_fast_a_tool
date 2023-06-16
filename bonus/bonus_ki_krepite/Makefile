##
## EPITECH PROJECT, 2022
## palyndrome
## File description:
## Makefile
##

MAINFILE	=	src/main.c			\
				src/init.c 			\
				src/parse_arg.c   	\
				src/exec_flags.c	\

BINNAME		=	FASTAtools_bonus

LIBNAME		=	lib/my/libmy.a

OBJ			=	$(MAINFILE:.c=.o)

LIB			=	-L./lib/my -lmy

INCF		=	include/

FLAGS		=	-I./$(INCF) $(LIB) -W -Wall -Wextra

all: $(BINNAME)

$(INCF):
	mkdir -p $(INCF)

$(LIBNAME):
	@make -C lib/my/ -w

$(BINNAME):	$(INCF)	$(LIBNAME)
	gcc -o $(BINNAME) $(MAINFILE) $(FLAGS)
	@if [ -f $(BINNAME) ]; then \
		echo -e "\033[92m\nFile succesfully compiled\n\033[0m" ; \
	fi

clean:
	@rm -f $(OBJ)
	@rm -f $(LIBNAME)
	@make -C lib/my/ clean
	@if [ -z "$(find . -name "*.o")" ] && [ ! -f $(LIBNAME) ]; then \
		echo -e "\033[92m\nClean succesfully done\n\033[0m" ; \
	fi

fclean: clean
	rm -f $(BINNAME)
	@if [ ! -f $(BINNAME) ]; then \
		echo -e "\033[92m\nFclean succesfully done\n\033[0m" ; \
	fi

bonus_to_test:
	./$(BINNAME) 7 < tests/example_two.fasta

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(BINNAME)

ftests:
	./tests/tester.sh

re: fclean all
