/*
** EPITECH PROJECT, 2017
** printf.c
** File description:
** printf
*/

#include "my.h"

int redirect(int arg, va_list print, int count_n)
{
	if (arg == 'd' || arg == 'i')
		decimal(print);
	if (arg == 'x' || arg == 'X')
		hex(print);
	if (arg == 'o')
		octal(print);
	if (arg == 'c')
		carac(print);
	if (arg == 's')
		string(print);
	if (arg == 'p')
		pointeur(print);
	if (arg == 'n')
		count(print, count_n);
	if (arg == 'b')
		binary(print);
}

int decimal(va_list print)
{
	my_put_nbr(va_arg(print, int));
}

int string(va_list print)
{
	my_putstr(va_arg(print, char *));
}
int my_printf(char *str, ...)
{
	int a = 0;
	int arg = 0;
	va_list print;
	int count_n = 0;

	va_start(print, str);
	while (str[a] != '\0') {
		if (str[a] == '%') {
			a++;
			while (str[a] == '%')
				a++;
			arg = str[a];
			redirect(arg, print, count_n);
		}
		if (str[a - 1] != '%') {
			my_putchar(str[a]);
			count_n++;
		}
		a++;
	}
	va_end(print);
}
