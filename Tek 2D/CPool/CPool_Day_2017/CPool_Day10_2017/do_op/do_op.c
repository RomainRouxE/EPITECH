/*
** EPITECH PROJECT, 2017
** do_op.c
** File description:
** do op
*/

#include "../include/my.h"

int choix_op(int x, char sign, int y)
{
	int result = 0;
	
	if(sign == '+')
		result = x + y;
	if(sign == '-')
		result = x - y;
	if(sign == '%')
		result = x % y;
	if(sign == '/')
		result = x / y;
	if(sign == '*')
		result = x * y;
	return (result);
}

int main(int argc, char **argv)
{
	int result = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	char sign [] = {'+', '-', '*', '/', '%'};

	if (argc > 4)
		return (84);
	x = my_getnbr(argv[1]);
	y = my_getnbr(argv[3]);
	while(*argv[2] != sign[z]) {
		z++;
	}
	if(sign[z] == '/' && y == 0) {
		my_putstr("Stop: division by zero\n");
	return (0);
	}
	if(sign[z] == '%' && y == 0) {
		my_putstr("Stop: modulo by zero\n");
	return (0);
	}
	result = choix_op(x, sign[z], y);
	if(result != 0) {
		my_put_nbr(result);
		my_putchar('\n');
	}
	if(result == 0) {
		my_putstr("0\n");
	}
	return (0);
}
