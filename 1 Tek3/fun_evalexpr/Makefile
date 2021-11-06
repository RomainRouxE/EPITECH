NAME	=	funEvalExpr

PACK	=	funEvalExpr

STK	=	stack

DIR	=	$(shell $(STK) path --local-install-root )/bin

all: $(NAME)

$(NAME):
	$(STK) build
	cp $(DIR)/$(PACK) ./$(NAME)

clean:
	rm -rf *.his

fclean:
	rm -rf *.his
	rm -rf funEvalExpr

re:	fclean all
