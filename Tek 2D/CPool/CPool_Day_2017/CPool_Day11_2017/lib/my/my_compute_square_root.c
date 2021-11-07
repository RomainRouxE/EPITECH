/*
** EPITECH PROJECT, 2017
** my_compute_square_root.c
** File description:
** compute square root
*/

int my_compute_square_root(int nb)
{
	int x=1;
	while ((x*x) < nb) {
		x++;
	}
	if ((x*x) == nb)
		return (x);
	return (0);
}
