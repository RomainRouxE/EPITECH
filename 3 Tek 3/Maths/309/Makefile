##
## EPITECH PROJECT
## Makefile
## File description:
## Makefile
##

CPP		= g++

CPPFLAGS	= -w -Wall -Werror -Wextra -I./include -g

SRC		= main.cpp	\
		  pollution.cpp

OBJ		= $(SRC:.cpp=.o)

NAME		= 309pollution

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) *~

re:
		fclean all
