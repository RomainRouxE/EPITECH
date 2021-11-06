//
// EPITECH PROJECT, 2019
// check.cpp
// File description:
// check.cpp
//

#include "307.hpp"

static bool is_num(char *str)
{
	int i = 0;
	int a = 0;

	while (str[i]) {
		if (str[i] < '0' || str[i] > '9' || str[i] == '.' && a != 0)
			return (false);
		else
			i++;
	}
	return (true);
}

static void errorP()
{
	std::cerr << "trop ou pas assez d arguments." << std::endl;
	exit(84);
}

static void errorN()
{
	std::cerr << "Un des arguments n est pas valide." << std::endl;
        exit(84);
}

static void usage(char **av)
{
	std::cout << "USAGE" << std::endl;
	std::cout << "\t./307multigrains n1 n2 n3 n4 po pw pc pb ps" << std::endl;
	std::cout << std::endl;
	std::cout << "DESCRIPTION" << std::endl;
	std::cout << "\t" << std::endl;
	exit(0);
}

void check(int ac, char **av)
{
	if (ac != 10 || ac == NULL)
		errorP();
	if (std::string("-h") == av[1])
		usage(av);
	for (int x = 1; x != ac; x++) {
		if (is_num(av[x]) == false)
			errorN();
	}
}
