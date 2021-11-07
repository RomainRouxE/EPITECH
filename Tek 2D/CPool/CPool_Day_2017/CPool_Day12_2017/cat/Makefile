##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Make
##

SRC	=	*.c

OBJ	=	*.o

NAME	=	cat

all:
	gcc -c $(SRC) -I../include/
	gcc -o $(NAME) $(OBJ) -L../lib -lmy

clean:
	rm -f *.o
	rm -f *~

fclean: clean

re: fclean all
