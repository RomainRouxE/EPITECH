/*
** EPITECH PROJECT, 2017
** my_find_prime_sup.c
** File description:
** Show the next prime number
*/

int	next_prime(int nb, int i)
{
	if (i > nb / 2)
		return (nb);
	if ((nb % i) == 0)
		return (next_prime(nb + 1, 2));
	return (next_prime(nb, i + 1));
}

int	my_find_prime_sup(int nb)
{
	if (nb <= 1)
		return (2);
	return (next_prime(nb, 2));
}
