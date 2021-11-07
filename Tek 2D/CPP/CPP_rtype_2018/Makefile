##
## EPITECH PROJECT, 2018
##
## File description:
##
##

# The location where SFML is installed
SFML_DIR=/home/andy/tek3/cpp/CPP_rtype_2018/SFML

# Location where SFML libraries are located
LIBDIR=$(SFML_DIR)/lib

# Arguments to pass to the compiler
CFLAGS=-I$(SFML_DIR)/include

# SFML (and other) libraries that need to be linked with
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME	=	r-type

RM	=	rm -rf

SRC	=	main.cpp\
		src/Entities/Entities.cpp\
		src/Entities/Spaceship.cpp\
		src/Entities/EnemyOne.cpp\
		src/Entities/Explosion.cpp\
		src/Backgrounds/Backgrounds.cpp\
		src/Backgrounds/FirstBack.cpp\
		src/Backgrounds/SecondBack.cpp\
		src/Backgrounds/ThirdBack.cpp\
		src/Backgrounds/FourthBack.cpp\
		src/Entities/Rocket.cpp\
		src/Engine.cpp\
		src/Game.cpp\
		src/Space.cpp

OBJS	= $(SRC:.cpp=.o)

CFLAGS	+=  -I./include -Wall -Wextra -Werror -I./include

GCC	= g++ -std=c++14 -g3

all	: $(NAME)

$(NAME) :
	  $(GCC) $(SRC) $(CFLAGS) -o $(NAME) -L$(LIBDIR) $(LIBS)

clean	:
	  $(RM) $(OBJS)

fclean	:	clean
	  $(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
