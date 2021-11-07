/*
** EPITECH PROJECT, 2017
** my_is_prime.c
** File description:
** Show is the number is prime
*/

int	prime(int nb, int i)
{
	if (i > nb / 2)
		return (1);
	if ((nb % i) == 0)
		return (0);
	return (prime(nb, i + 1));
}

int	my_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	return (prime(nb, 2));
}
