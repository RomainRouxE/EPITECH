##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CPP		= g++

CPPFLAGS	= -w -Wall -Werror -Wextra -I./include -g

SRC		= main.cpp	\
		  select.cpp	\
		  bubble.cpp	\
		  algo.cpp	\
		  check.cpp	\
		  insert.cpp

OBJ		= $(SRC:.cpp=.o)

NAME		= 301dannon

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
