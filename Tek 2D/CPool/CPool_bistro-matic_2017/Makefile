##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for test
##

SRC	=	infinit.c	\
		my_strtol.c	\
		bootstrap.c	\
		main.c

FLAGS	=	-Wall -Wextra -Werror

NAME	=	calc

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(FLAGS) -Llib -lmy

clean:
	make -C lib/my clean

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all
	
