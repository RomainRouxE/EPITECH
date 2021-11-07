/*
** EPITECH PROJECT, 2017
** flag2.c
** File description:
** flag 2 printf
*/

#include "my.h"

int binary(va_list print)
{
	my_putnbr_base(va_arg(print, int), "01");
}
