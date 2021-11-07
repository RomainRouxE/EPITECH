NAME	= menger
GCC	= gcc
RM	= rm -f

SRC	= menger.c \
	    main.c

OBJ     = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
