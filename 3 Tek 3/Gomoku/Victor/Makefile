##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	num_map.cpp	\
		main.cpp	\
		game.cpp	\
		ai.cpp		\

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

NAME	=	pbrain-gomoku-ai

CXXFLAGS	+=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
