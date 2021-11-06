GPP		=	g++

RM		=	rm -f

NAME		=	203hotline

SRCS		=	hotline.cpp	\
			main.cpp

OBJS		=	$(SRCS:.cpp=.o)

CPPFLAGS	=	-Wall -Wextra -Werror -lgmpxx -lgmp -I includes

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(GPP) $(SRCS) -o $(NAME) $(CPPFLAGS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
