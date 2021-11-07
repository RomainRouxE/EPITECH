##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make
##

NAME	= libmy.a

LIB	= -L./lib/my -lmy

RM	= rm -f

SRCS	= lib/my/printf.c    \
	  lib/my/flag.c	\
	  lib/my/flag2.c	\
	  lib/my/lib.c	\

OBJ	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
