/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** arguments handling
*/

#include "client.h"

int get_nb(const char *optarg, char opt)
{
	int nb = atoi(optarg);

	if (nb <= 0) {
		PRINT_ERR("Option -%c invalid port: %s", opt, optarg);
		exit(FAILURE);
	}
	return nb;
}

opts_t store_opts(int ac, char **av)
{
	opts_t opts = {NULL, 0};

	for (int c = getopt(ac, av, "h:p:") ; c != -1
	 ; c = getopt(ac, av, "h:p:")) {
		switch (c) {
			case 'h': opts.ip = optarg;
				break;
			case 'p': opts.port = get_nb(optarg, c);
				break;

			default: PRINT_ERR("Unknown option");
				exit(FAILURE);
		}
	}
	if (opts.ip == NULL || opts.port == 0) {
		PRINT_ERR("All options weren't set");
		exit(FAILURE);
	}

	return opts;
}

bool prefix(const char *pre, const char *str)
{
	return strncmp(pre, str, strlen(pre)) == 0;
}
