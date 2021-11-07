##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make
##

CC	=	gcc

NAME	=	my_ls

SRCS	=	my_ls.c	\
		my_ls_tri.c	\
		my_ls_show.c	\
		my_ls_options.c	\
		my_over_nine.c	\
		my_colors.c	\
		my_next_file.c	\
		macroes.c	\
		last.c	\
		functions.c

LIB	=	libmy.a

OBJS	 =	$(SRCS:.c=.o)

all:    $(NAME)

$(NAME):         $(OBJS)
	$(CC) -o $(NAME)  $(OBJS)  $(LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
