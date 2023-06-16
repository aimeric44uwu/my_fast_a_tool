##
## EPITECH PROJECT, 2022
## palyndrome
## File description:
## Makefile
##

MAINFILE	=	test_bonus.c	\
				requirement_bonus.c	\

BINNAME		=	Bonus_crunchy

OBJ			=	$(MAINFILE:.c=.o)

INCF		=	include/

FLAGS		=	-I./$(INCF) -W -Wall -Wextra

all: $(BINNAME)

$(INCF):
	mkdir -p $(INCF)

$(BINNAME):	$(INCF)
	gcc -o $(BINNAME) $(MAINFILE) $(FLAGS)
	@if [ -f $(BINNAME) ]; then \
		echo -e "\033[92m\nFile succesfully compiled\n\033[0m" ; \
	fi

clean:
	@rm -f $(OBJ)
	@if [ -z "$(find . -name "*.o")" ]; then \
		echo -e "\033[92m\nClean succesfully done\n\033[0m" ; \
	fi

fclean: clean
	rm -f $(BINNAME)
	@if [ ! -f $(BINNAME) ]; then \
		echo -e "\033[92m\nFclean succesfully done\n\033[0m" ; \
	fi

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(BINNAME)

re: fclean all
