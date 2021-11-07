##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAMEOBJ	=	my_objdump

OBJ	=	objdump

SRCSOBJ	=	$(OBJ)/main.c		\
		$(OBJ)/file.c		\
		$(OBJ)/print_data.c		\
		$(OBJ)/print_header.c

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I includes

CC	=	gcc

RM	=	rm -f

OBJSOBJ	=	$(SRCSOBJ:.c=.o)

all:		objdump

objdump:	$(NAMEOBJ);

$(NAMEOBJ):	$(OBJSOBJ)
		$(CC) $(OBJSOBJ) -o $(NAMEOBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJSOBJ)

fclean:		clean
		$(RM) $(NAMEOBJ)

re: fclean all
