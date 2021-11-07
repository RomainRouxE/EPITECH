/*
** EPITECH PROJECT, 2017
** my_compute_square_root.c
** File description:
** return the square root
*/

int	square_root(int nb, int i)
{
	if (i * i > nb)
		return (0);
	else if ((i * i) == nb)
		return (i);
	else
		return square_root(nb, i + 1);
}

int	my_compute_square_root(int nb)
{
	return (square_root(nb, 0));
}
