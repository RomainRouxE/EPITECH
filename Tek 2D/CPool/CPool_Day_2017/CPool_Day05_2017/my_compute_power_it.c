/*
** EPITECH PROJECT, 2017
** my_computer_power_it.c
** File description:
** 
*/
int my_compute_power_it(int nb, int p)
{
	int x=nb;
	if (p  == 0)
		return (1);
	if (p < 0)
		return (0);
	while (p > 1) {
		x = x*nb;
		p--;
	}
	return (x >= 2147483647) ? (0) : ((int)x);
}
