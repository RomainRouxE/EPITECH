##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPP		= g++

CPPFLAGS	= -w -Wall -Werror -Wextra -I./include -g

SRC		= game.cpp	\

OBJ		= $(SRC:.cpp=.o)

NAME		= pbrain-gomoku-ai

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:
		fclean all
