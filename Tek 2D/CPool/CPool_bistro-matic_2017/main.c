/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/bistro-matic.h"
#include "include/my.h"

static void check_base(char *b)
{
	if (my_strlen(b) < 2) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_BASE);
	}
}

static void check_expr(char **str, char *ops)
{
	int par_not_close = 0;

	for (int i = 0; (*str)[i] != '\0'; i++) {
		if ((*str)[i] == ops[OP_OPEN_PARENT_IDX])
			par_not_close++;
		else if ((*str)[i] == ops[OP_CLOSE_PARENT_IDX])
			par_not_close--;
		if (par_not_close < 0) {
			//my_putstr("OUPS");
			my_putstr(SYNTAX_ERROR_MSG);
			exit(EXIT_SYNTAX);
		}
	}
	if (par_not_close != 0) {
		//my_put_nbr(par_not_close);
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_SYNTAX);
	}
}

static char *get_expr(unsigned int size)
{
	char *expr;

	if (size <= 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_SIZE_NEG);
	}
	expr = malloc(size + 1);
	if (expr == 0) {
		my_putstr(ERROR_MSG);
		exit (EXIT_MALLOC);
	}
	if (read(0, expr, size) != size) {
		my_putstr(ERROR_MSG);
		exit(EXIT_READ);
	}
	expr[size] = 0;
	return (expr);
}

static void check_ops(char *ops)
{
	if (my_strlen(ops) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_OPS);
	}
}

int	main(int argc, char **argv)
{
	char *expr;
	unsigned int size;

	if(argc != 4) {
		my_putstr("Usage: ");
		my_putstr(argv[0]);
		my_putstr(" base ops \"()+_*/%\" exp_len\n");
		return (EXIT_USAGE);
	}
	check_base(argv[1]);
	check_ops(argv[2]);
	size = my_getnbr(argv[3]);
	expr = get_expr(size);
	check_expr(&expr, argv[2]);
	my_put_nbr(eval_expr(argv[1], argv[2], expr, size));
	return (EXIT_SUCCESS);
}
