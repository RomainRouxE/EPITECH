##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

NAME	= abstractVM

CC	= g++

RM	= rm -rf

SRCS	= src/AbstractVM.cpp	\
	src/Exec.cpp		\
	src/Factory.cpp		\
	src/Operand_type.cpp	\
	src/Parsing.cpp		\
	src/Stream.cpp		\
	src/utils.cpp		\
	src/main.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS	= -Wall -Wextra -Werror

CPPFLAGS	= -Iinclude -g3

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)
clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
