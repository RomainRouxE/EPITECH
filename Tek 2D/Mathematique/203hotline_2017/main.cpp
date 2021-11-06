//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main.cpp
//

#include "hotline.hpp"

static void usage(char **av)
{
	std::cout << "USAGE" << std::endl;
	std::cout << "\t\t" << av[0] << " [n k | d]" << std::endl;
	std::cout << "DESCRIPTION" << std::endl;
	std::cout << "\tn\tn value for the computation of (n k)" << std::endl;
	std::cout << "\tb\tk value for the computation of (n k)" << std::endl;
	std::cout << "\td\taverage duration of calls (in seconds)" << std::endl;
	exit(0);
}

static bool is_number(char *str)
{
        int i = 0;

        while (str[i]) {
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		else if (str[i] < '0' || str[i] > '9')
			return (false);
		else
			i++;
	}
	return (true);
}

static void error()
{
	std::cerr << "Error: Bad arguments, please run with -h for help" << std::endl;
	exit(84);
}

int main(int ac, char **av)
{
	Hotline line;
	int i = 1;

	while (i < ac) {
		if (std::string("-h") == av[1])
			usage(av);
		if (i > 2 || !is_number(av[i]))
			error();
		i++;
	}
	if (i == 2 && atoi(av[1]) > 0 && atoi(av[1]) <= (3600 * 8)) {
		line.Param(atoi(av[1]), 0);
		line.Binomial();
		line.Poisson();
	}
	else if (i == 3 && atoi(av[1]) > 0 && atoi(av[2]) < atoi(av[1])) {
		line.Param(atoi(av[1]), atoi(av[2]));
		line.Combination();
	}
	else
		error();
}
