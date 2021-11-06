/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main pushswap
*/

#include "my.h"

static int check_num(char *s)
{
	int i = 0;

	while (s[i]) {
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (1);
}

int main(int ac, char **av)
{
	int x = 1;
	int v = 0;
	t_list *la;
	t_list *lb;

	la = NULL;
	lb = NULL;

	if (ac == 1)
		return (0);
	if (my_strcmp(av[x], "-v") == 0)
		v = 1;
	for (; x < ac; ) {
		if (check_num(av[x]) == 1)
			fill(&la, my_atoi(av[x]));
		x++;
	}
	pushswap(la, lb, v);
	my_putchar('\n');
	return (0);
}
