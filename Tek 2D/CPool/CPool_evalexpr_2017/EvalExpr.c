/*
** EPITECH PROJECT, 2017
** EvalExpr.c
** File description:
** eval expr
*/

#include "include/my.h"

int my_strtol(char *str, char **endptr)
{
	int nbr = 0;
	int neg_or_pos = 1;
	char *ptr = str;

	while (*ptr == ' ')
		ptr++;
	if (*ptr == '-') {
		neg_or_pos = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9') {
		nbr = nbr * 10 + (*ptr - '0');
		ptr++;
	}
	while (*ptr == ' ')
		ptr++;
	*endptr = ptr;
	return (nbr * neg_or_pos);
}

int action3(char **expr)
{
	char *reste;
	char *ptr2 = my_strdup(*expr);
	int result = my_strtol(ptr2, &reste);

	ptr2 = reste;
	while (*ptr2) {
		if (*ptr2 == '*') {
			ptr2++;
			result = result * my_strtol(ptr2, &reste);
		}
		else if (*ptr2 == '/') {
			ptr2++;
			result = result / my_strtol(ptr2, &reste);
		}
		else if (*ptr2 == '%') {
			ptr2++;
			result = result % my_strtol(ptr2, &reste);
		}
		else
			break;
		ptr2 = reste;
	}
	*expr = ptr2;
	return (result);
}

int action2(char **expr)
{
	int result = 0;
	char *ptr = my_strdup(*expr);

	while (*ptr) {
		if (*ptr == '+') {
			ptr++;
			result = result + action3(&ptr);
		}
		else if (*ptr == '-') {
			ptr++;
			result = result - action3(&ptr);
		}
		else
			result = result + action3(&ptr);
	}
	return (result);
}

int eval_expr(char *expr)
{
	int result;
	char *tmp = expr;

	result = (action2(&tmp));
	return (result);
}
