/*
** EPITECH PROJECT, 2017
** my_strtol.c
** File description:
** Get the number
*/

#include <stdio.h>
#include "include/my.h"

int number(char **str)
{
	int i = 0;
	int res = 0;

	for (i = 0; (*str)[i] != '\0' && ((*str)[i] == '+' || (*str)[i] == '-'); i++){}
	for (; (*str)[i] != '\0' && (my_chr_isdigit((*str)[i]) == 1); i++) {}
	res = my_getnbr(*str);
	*str = &(*str)[i];
	return res;
}

int my_strtol(char *str, char **endptr)
{
	int i = 0;

	for (i = 0; str[i] != '\0' && (str[i] == '+' || str[i] == '-'); i++){}
	for (;str[i] != '\0' && (my_chr_isdigit(str[i]) == 1); i++) {}
	*endptr = &str[i];
	return my_getnbr(str);
}

/*
int main(int argc, char **argv)
{
	char *str, *endptr;
	int res;
	(void)endptr;
	if (argc != 2)
		return 84;
	str = argv[1];
	res = my_strtol(str, &endptr);
	//printf("GETNBR=%d\n", number(&str));
	if (endptr == str) {
		my_putstr("No digits were found");
		return 84;
	}
	else
		printf("%d\n", res);
	if (*endptr != '\0') {
		my_putstr("Further characters after number: ");
		my_putstr(endptr);
	}
	return 0;
}
*/
