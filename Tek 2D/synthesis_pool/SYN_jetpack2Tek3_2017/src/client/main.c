/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** client main
*/

#include "client.h"

int main(int ac, char **av)
{
	opts_t opts = store_opts(ac, av);

	sem_init(&mutex, 0, 1);
	run_connection(opts);
	sem_destroy(&mutex);
	return SUCCESS;
}
