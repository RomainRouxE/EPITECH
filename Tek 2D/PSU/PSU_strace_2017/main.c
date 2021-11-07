/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void error()
{
	printf("Bad argument");
	exit(84);
}

static void usage()
{
	printf("USAGE: ./strace [-s] [-p <pid>|<command>]");
	exit(0);
}

int main(int ac, char **av)
{
	if (ac > 5 || ac < 2)
		error();
	if (strcmp(av[1], "--help") == 0)
		usage();
	else
		error();
}
