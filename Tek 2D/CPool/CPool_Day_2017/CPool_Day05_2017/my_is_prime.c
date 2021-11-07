/*
** EPITECH PROJECT, 2017
** my_is_prime.c
** File description:
** 
*/
int my_is_prime(int nb) {
	int y = 3;
	if (nb == 2)
		return (1);
	if (nb %2 == 0 || nb < 0 || nb == 1)
		return (0);
	while (nb >= y) {
		if ((nb %y) == 0)
			return (y == nb) ? (1) : (0);
		y = y + 2;
	}
}
