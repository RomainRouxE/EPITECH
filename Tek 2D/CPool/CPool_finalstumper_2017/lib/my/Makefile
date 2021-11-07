##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compiles lib
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find . \( -name "#*#" -o -name "*~" \) -type f -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
