/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec.c
** File description:
** 
*/
int my_compute_factorial_rec(int nb)
{
	int x;
	if (nb == 0)
		return (1);
	else if (nb < 0 || nb > 12)
		return (0);
	else if (nb > 0)
		x = my_compute_factorial_rec(nb - 1)*nb;
	return (x);
}
