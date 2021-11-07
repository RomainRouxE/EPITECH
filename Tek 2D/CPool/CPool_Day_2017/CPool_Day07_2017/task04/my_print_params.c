/*
** EPITECH PROJECT, 2017
** my_print_params.c
** File description:
** 
*/
#include <unistd.h>
int	main(int ac, char *av[])
{
	int	x = 0;
	int	y = 0;
	while(x < ac) {
		while(av[x][y] != '\0') {
			write(1, &av[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		y = 0;
		x++;
	}
	return (0);
}
