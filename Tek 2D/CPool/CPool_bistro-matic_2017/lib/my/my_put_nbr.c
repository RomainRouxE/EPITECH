/*
 ** EPITECH PROJECT, 2017
 ** my_put_nbr.c
 ** File description:
 ** Write a number
 */

void	my_putchar(char c);
int	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		if (nb == -2147483648) {
			my_putchar('2');
			nb =-147483648;
		}
		nb = nb * (-1);
	}

	if (nb < 10)
		my_putchar((nb % 10) + 48);
	else {
		my_put_nbr(nb / 10);
		my_putchar((nb % 10) + 48);
	}
	return (0);
}
