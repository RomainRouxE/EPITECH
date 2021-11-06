/*
** EPITECH PROJECT, 2017
** lib.c
** File description:
** lib pushswap
*/

#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char const *str)
{
	int x = 0;

	while (str[x] != '\0') {
		my_putchar(str[x]);
		x++;
	}
	return (0);
}

int my_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] && s2[i]) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10) {
		my_put_nbr(nb / 10);
		my_putchar((nb % 10) + '0');
	}
	else
		my_putchar(nb + '0');
	return (0);
}

int my_atoi(const char *str)
{
	int i = 0;
	int new = 0;
	int neg = 0;

	while (str[i] >= 1 && str[i] <= 32)
		i++;
	if (str[i] == 0)
		return (0);
	neg = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i]) {
		if ((char)str[i] < '0' || (char)str[i] > '9')
			break ;
		new *= 10;
		new += str[i] - 48;
		i++;
	}
	if (str[neg] == '-')
		return (-new);
	return (new);
}
