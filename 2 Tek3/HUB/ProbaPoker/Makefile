##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPP		= g++

CPPFLAGS	= -w -Wall -Werror -Wextra -I./include -g

SRC		= SRC/main.cpp \
		  SRC/preflopP.cpp \
		  SRC/out.cpp \
		  SRC/getout.cpp \
		  SRC/vs.cpp \
		  SRC/cote.cpp \

OBJ		= $(SRC:.cpp=.o)

NAME		= Poker

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) *~
		$(RM) SRC/*~
		$(RM) INC/*~
		$(RM) TXT/*~

re:
		fclean all
