/*
** EPITECH PROJECT, 2018
** my_str_is_num.c
** File description:
** my_str_is_num.c
*/

#include "philosopher.h"

int is_num(char *str)
{
	int i = -1;

	while (str[++i])
		if (str[i] > '9' || str[i] < '0')
			return (-1);
	return (atoi(str));
}
