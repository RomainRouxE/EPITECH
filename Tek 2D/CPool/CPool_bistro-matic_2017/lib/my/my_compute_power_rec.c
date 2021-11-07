/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** Return the power (recursive)
*/

int	my_compute_power_rec(int nb, int p)
{
	int res = nb;

	if (p < 0)
		return (0);
	else if(p == 0)
		return (1);
	return (res * my_compute_power_rec(nb, p - 1));
}
