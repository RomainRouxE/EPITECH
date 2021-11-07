##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc

NAME	=	philo

CFLAGS	=	-Wall -W -Wextra -I./include

LDFLAG	=	-L ./lib -Wl,-rpath,./lib -lriceferee -lpthread

SRC	=	main.c	\
		thread.c	\
		is_num.c \

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAG)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	: all clean fclean re
