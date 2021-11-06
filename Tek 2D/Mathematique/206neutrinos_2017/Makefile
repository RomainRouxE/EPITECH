CXX		=	g++
CXXFLAGS=	-W -Wall -Wextra -I./header/ -g
RM		=	rm -rf
NAME	=	206neutrinos
T_NAME	=	unit

SRC		+=	main.cpp
OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
