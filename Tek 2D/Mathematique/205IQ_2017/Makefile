##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CPP             = g++

CPPFLAGS        = -w -Wall -Werror -Wextra -I./include -g

SRC             = main.cpp      \
		  205IQ.cpp

OBJ             = $(SRC:.cpp=.o)

NAME            = 205IQ

RM              = rm -rf

all:            $(NAME)

$(NAME):        $(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:         clean
		$(RM) $(NAME)

re:
		fclean all

