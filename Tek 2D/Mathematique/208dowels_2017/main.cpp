//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main.cpp
//

#include <gmpxx.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/timeb.h>

static bool is_num(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
		else
			i++;
	}
	return (true);
}

static void usage(char **av)
{
	std::cout << "USAGE" << std::endl;
	std::cout << "\t   " << av[0] << " O0 O1 O2 O3 04 O5 O6 O7 O8+" << std::endl;
	std::cout << std::endl;
	std::cout << "DESCRIPTION" << std::endl;
	std::cout << "\t   Oi   size of the observed class" << std::endl;
	exit(0);
}

static void error()
{
	std::cerr << "Bad argument" << std::endl;
	exit(84);
}

int main(int ac, char **av)
{
	int x;

	if (av[1] == NULL || ac != 10)
		error();
	if (std::string("-h") == av[1])
		usage(av);
	for (x = 1; x != ac; x++) {
		if (is_num(av[x]) == false)
			error();
	}
}
