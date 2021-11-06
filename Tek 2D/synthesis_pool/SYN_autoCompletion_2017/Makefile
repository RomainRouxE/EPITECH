##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		= autoCompletion

SRC		= main.cpp 

OBJ		= $(SRC:.cpp=.o)

CPP		= g++ -g

RM		= rm -f

CPPFLAGS	= -I ./include -W -Wall -Werror -Wextra -g -O3

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
