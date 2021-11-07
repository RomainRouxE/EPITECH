/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "objdump.h"

static int args(int const ac, char const *const *const av, t_elf *const elf)
{
	int i = 0;

	while (++i < ac)
		if (!parse_file(av[i], elf)
		    || !write_header(elf)
		    || !write_data(elf))
			return (0);
	return (1);
}

int main(int const ac, char const *const *const av)
{
	t_elf elf;

	if ((ac < 2 && (!parse_file("a.out", &elf)
		 || !write_header(&elf)
		 || !write_data(&elf)))
	    || !args(ac, av, &elf))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
