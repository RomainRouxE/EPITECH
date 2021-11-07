/*
** EPITECH PROJECT, 2017
** lib.c
** File description:
** lib printf
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

int my_strlen(char *str)
{
	int x = 0;

	while (str[x] != '\0') {
		x++;
	}
	return (x);
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

void	my_putnbr_base(unsigned int nb, char *base)
{
	unsigned int	div;
	int	n_base;

	div = 1;
	n_base = my_strlen(base);
	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	}
	while ((nb / div) >= n_base)
		div *= n_base;
	while (div > 0)	{
		my_putchar(base[(nb / div) % n_base]);
		div /= n_base;
	}
}
