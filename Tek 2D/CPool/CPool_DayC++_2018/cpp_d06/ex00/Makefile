##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	= main.cpp

OBJ	= $(SRC:.cpp=.o)

NAME	= my_cat

all	: $(NAME)

$(NAME)	: $(OBJ)
	  g++ -o $(NAME) $(OBJ)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all
