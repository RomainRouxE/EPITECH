//
// EPITECH PROJECT, 2018
// check.cpp
// File description:
// check.cpp
//

#include "301dannon.hpp"

static void error()
{
	std::cerr << "File doesn't exist" << std::endl;
	exit(84);
}

static void usage(char **av)
{
	std::cout << "USAGE" << std::endl;
	std::cout << "\t   " << av[0] << std::endl;
	std::cout << std::endl;
	std::cout << "DESCRIPTION" << std::endl;
	std::cout << "\t   file   file that contains the numbers to be sorted, seperated by spaces" << std::endl;
	exit(0);
}

void check(int ac, char **av)
{
	if (ac != 2 || ac == NULL)
		error();
	if (std::string("-h") == av[1])
		usage(av);
	std::ifstream ifs;
	ifs.open (av[1]);
	if (!ifs)
		error();
	ifs.close();
}
