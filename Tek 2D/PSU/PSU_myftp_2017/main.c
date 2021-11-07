/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

static void error()
{
	exit(84);
}

int main(int ac, char **av)
{
	if (ac != 2)
		error();
}
