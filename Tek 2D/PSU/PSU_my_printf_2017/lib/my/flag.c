/*
** EPITECH PROJECT, 2017
** flag.c
** File description:
** flag printf
*/

#include "my.h"

int hex(va_list print)
{
	my_putnbr_base(va_arg(print, int), "0123456789ABCDEF");
}

int carac(va_list print)
{
	my_putstr(va_arg(print, char *));
}

int octal(va_list print)
{
	my_putnbr_base(va_arg(print, int), "01234567");
}

int pointeur(va_list print)
{
	my_putstr("Les pointeurs fonctionnent");
	my_putchar('\n');
}

int count(va_list print, int count_n)
{
	my_put_nbr(count_n);
}
