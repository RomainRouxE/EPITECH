##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

RM		= rm -f

CC		= gcc

NAME		= libmy_malloc.so

CFLAGS		+= -fPIC

SRCS		= malloc.c

OBJS		= $(SRCS:.c=.o)

all:            $(NAME)

$(NAME):	$(OBJS)
		$(CC) -shared -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)
		$(RM) *~

fclean:         clean
		$(RM) $(NAME)

re: fclean all
