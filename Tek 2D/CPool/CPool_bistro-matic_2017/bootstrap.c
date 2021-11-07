/*
** EPITECH PROJECT, 2017
** summands.c
** File description:
** do an operation
*/

#include "include/my.h"
#include <stdlib.h>
#include "include/bistro-matic.h"

char	*int_to_str(int nbr)
{
	int tmp = nbr;
	int len = 0;
	int i = 0;
	char *str;
	int isneg = 0;

	if (nbr < 0) {
		isneg = 1;
		nbr *= (-1);
		tmp *= (-1);
	}
	for (len = 1; (tmp / 10) > 0; len++)
		tmp /= 10;
	str = malloc(sizeof(char) * (len + 2));
	for (; i < len + isneg; i++) {
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if(isneg == 1)
		str[i-1] = '-';
	my_revstr(str);
	return str;
}

int	parse(char **str, char *ops)
{
	int res = 0;
	if((*str)[0] == ' ')
		*str = &(*str)[1];
	if ((*str)[0] == ops[OP_CLOSE_PARENT_IDX]) {
		while ((*str)[0] == ops[OP_CLOSE_PARENT_IDX])
			*str = &(*str)[1];
		return 0;
	}
	while ((*str)[0] == ops[OP_OPEN_PARENT_IDX])
		*str = &(*str)[1];
	if (my_chr_isdigit((*str)[0]) == 1)
		res = number(&(*str));
	if ((*str)[0] == ops[OP_SUB_IDX]){
		*str = &(*str)[1];
		return (infinit_add(int_to_str(res), 
					int_to_str(parse(str, ops) * (-1))));
	}
	else if ((*str)[0] == ops[OP_PLUS_IDX]){
		*str = &(*str)[1];
		return (infinit_add(int_to_str(res), int_to_str(parse(str, ops))));
	}
	else if ((*str)[0] == ops[OP_MULT_IDX]) {
		*str = &(*str)[1];
		return (infinit_mult(int_to_str(res), int_to_str(parse(str, ops))));
	}
	else if ((*str)[0] == ops[OP_DIV_IDX]) {
		*str = &(*str)[1];
		return (infinit_div(int_to_str(res), int_to_str(parse(str, ops))));
	}
	else if ((*str)[0] == ops[OP_MOD_IDX]) {
		*str = &(*str)[1];
		return (infinit_mod(int_to_str(res), int_to_str(parse(str, ops))));
	}
	return res;
}

int	summand(char **str, char *ops)
{
	int res = 0;
	
	while ((*str)[0] != '\0')
		res = infinit_add(int_to_str(res), int_to_str(factors(str, ops)));
	return res;
}

int	factors(char **str, char *ops)
{
	int num1 = 0;
	
	if((*str)[0] == ' ')
		*str = &(*str)[1];
	if((*str)[0] == '\0')
		return num1;
	while ((*str)[0] == ops[OP_CLOSE_PARENT_IDX])
		*str = &(*str)[1];
	if ((*str)[0] == ops[OP_OPEN_PARENT_IDX])
		num1 = (parse(str, ops));
	if ((*str)[0] == ops[OP_SUB_IDX]){
		*str = &(*str)[1];
		if ((*str)[0] == ops[OP_OPEN_PARENT_IDX])
			num1 = (parse(str, ops) * (-1));
			//return (parse(str, ops) * (-1));
		else
			num1 = (number(&(*str)) * (-1));
			//return ((number(&(*str))) * (-1));
	}
	if (my_chr_isdigit((*str)[0]) == 1)
		num1 = number(&(*str));
	if ((*str)[0] == ops[OP_PLUS_IDX]){
		*str = &(*str)[1];
		return num1;
	}
	else if ((*str)[0] == ops[OP_MULT_IDX]) {
		*str = &(*str)[1];
		return (infinit_mult(int_to_str(num1), int_to_str(factors(str, ops))));
	}
	else if ((*str)[0] == ops[OP_DIV_IDX]) {
		*str = &(*str)[1];
		return (infinit_div(int_to_str(num1), int_to_str(factors(str, ops))));
	}
	else if ((*str)[0] == ops[OP_MOD_IDX]) {
		*str = &(*str)[1];
		return (infinit_mod(int_to_str(num1), int_to_str(factors(str, ops))));
	}
	return num1;
}

int	eval_expr(char *base, char *ops, char *expr, int size)
{
	int res = 0;
	(void)base;
	(void)size;

	res = summand(&expr, ops);
	return (res);
}
