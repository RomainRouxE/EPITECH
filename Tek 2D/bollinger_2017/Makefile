##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	main.cpp	\
			bollinger.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Werror -Iinclude

NAME		=	bollinger

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
