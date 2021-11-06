SRC		= game.cpp

OBJ		= $(SRC:.cpp=.o)

CC		= g++

NAME		= pbrain-gomoku-ai

CXXFLAGS	= -w -Wall -Werror -Wextra -I./include -g

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
