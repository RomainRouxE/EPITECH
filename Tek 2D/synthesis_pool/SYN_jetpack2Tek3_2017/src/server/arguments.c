/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** arguments handling
*/

#include "server.h"

int get_nb(const char *optarg, char opt)
{
	int nb = atoi(optarg);

	if (nb <= 0) {
		PRINT_ERR("Option -%c invalid value: %s", opt, optarg);
		exit(FAILURE);
	}
	return nb;
}

opts_t store_opts(int ac, char **av)
{
	opts_t opts = {0, 0, NULL};

	for (int c = getopt(ac, av, "p:g:m:") ; c != -1 
	; c = getopt(ac, av, "p:g:m:")) {
		switch (c) {
			case 'p': opts.port = get_nb(optarg, c);
				break;
			case 'g': opts.gravity = get_nb(optarg, c);
				break;
			case 'm': opts.map = optarg;
				break;
			default: PRINT_ERR("Unknown option");
				exit(FAILURE);
		}
	}
	if (opts.port == 0 || opts.gravity == 0 || opts.map == NULL) {
		PRINT_ERR("All options weren't set");
		exit(FAILURE);
	}

	return opts;
}
