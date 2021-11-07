##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task00
##

SRC	=	btree_create_node.c	\
		btree_apply_prefix.c	\
		btree_apply_infix.c	\
		btree_apply_suffix.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libbtree.a

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC)
		ar rc libbtree.a $(OBJ)

clean:
	rm -f *.o
	rm -f *~
	rm -f *.a
fclean: clean
