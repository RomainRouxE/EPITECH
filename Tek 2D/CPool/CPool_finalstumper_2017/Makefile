##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compiles lib and binary
##

CC	=	gcc

CFLAGS	+=	-g -Wall -Wextra -Werror -Iinclude/

SRC	=	main.c			\
		final_stumper.c		\
		prepare_array_and_test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

LIB	=	libmy

all:	$(LIB)	$(NAME)

$(LIB):
	make -C lib/my/


$(NAME):	$(OBJ)
	gcc -g -o $(NAME) $(OBJ) -Llib/my/ -lmy

clean:
	make fclean -C lib/my/
	rm -f $(OBJ)
	find . \( -name "#*#" -o -name "*~" \) -type f -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
