##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile minishell1
##

SRC	= main.c	\
	  fork.c	\
	  lib.c	\
	  lib2.c	\
	  lib3.c	\
	  built.c

OBJS	= $(SRC:.c=.o)

NAME	= mysh

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
