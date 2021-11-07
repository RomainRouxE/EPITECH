##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

SRC	=	infin_add.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my re
		gcc -o $(NAME) $(SRC) -L./lib/my -lmy

clean:
	rm -f *.o
	rm -f *~
	rm -f *.a

fclean: clean

re:  all clean
