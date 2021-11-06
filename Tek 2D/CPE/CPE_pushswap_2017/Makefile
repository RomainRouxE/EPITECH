##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make
##

SRC	=	main.c	\
		fill.c	\
		operation.c	\
		order.c	\
		pushswap.c	\
		lib.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)

clean:
	rm -f *.o
	rm -f *~
	rm -f *.a

fclean: clean

re:  all clean
