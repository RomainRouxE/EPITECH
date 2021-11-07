/*
** EPITECH PROJECT, 2017
** my_compute_factorial_it.c
** File description:
** 
*/
int my_compute_factorial_it(int nb)
{
	long x = 1;
	int y = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb > 0) {
		x = x*y;
		y++;
		nb--;
	}
	return (x >= 2147483647) ? (0) : ((int)x);
}
