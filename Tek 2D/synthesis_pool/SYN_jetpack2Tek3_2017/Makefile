##
## EPITECH PROJECT, 2018
## zappy
## File description:
## Makefile
##

SE_NAME	=	serverJ2T3

CL_NAME	=	clientJ2T3

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -Og -g3 -D_FORTIFY_SOURCE=2
CFLAGS	+=	-I./include -I./include/server -I./include/client

## Global Rules

all: client server

clean:
	$(RM) $(SE_OBJ) $(CL_OBJ)

fclean: clean
	$(RM) $(SE_NAME) $(CL_NAME)

re: fclean all

.PHONY: all clean fclean re

## serverJ2T3

SE_DIR	=	./src/server

SE_SRC	=	$(wildcard $(SE_DIR)/*.c)

SE_OBJ	=	$(SE_SRC:.c=.o)

SE_FLAG	=	$(CFLAGS) -I./include/server

server: $(SE_OBJ)
	$(CC) -o $(SE_NAME) $(SE_OBJ) $(SE_FLAG)
	@printf "\033[0;32m\n********** $(SE_NAME) compilation completed **********\n\n\e[0m"

## clientJ2T3

# LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network
LDFLAGS	=	-lc_graph_prog
LDFLAGS	+=	-lpthread

CL_DIR	=	./src/client

CL_SRC	=	$(wildcard $(CL_DIR)/*.c)

CL_OBJ	=	$(CL_SRC:.c=.o)

CL_FLAG	=	$(CFLAGS) -I./include/client

client: $(CL_OBJ)
	$(CC) -o $(CL_NAME) $(CL_OBJ) $(CL_FLAG) $(LDFLAGS)
	@printf "\033[0;32m\n********** $(CL_NAME) compilation completed **********\n\n\e[0m"
