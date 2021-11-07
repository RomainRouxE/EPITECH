##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

SRC	=	EvalExpr.c

MAIN	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my re
		gcc -o $(NAME) $(MAIN) $(SRC) -L./lib/my -lmy

clean:
	rm -f *.o
	rm -f *~
	rm -f *.a

fclean: clean

re:  all clean
