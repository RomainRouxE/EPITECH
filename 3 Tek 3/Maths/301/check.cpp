//
// EPITECH PROJECT,
// check.cpp
// File description:
// check.cpp
//

#include "301dannon.hpp"

static void error()
{
	cerr << "File doesn't exist" << endl;
	exit(84);
}

static void usage(char **av)
{
	cout << "USAGE" << endl;
	cout << "\t   " << av[0] << endl;
	cout << endl;
	cout << "DESCRIPTION" << endl;
	cout << "\t   file   file that contains the numbers to be sorted, seperated by spaces" << endl;
	exit(0);
}

void check(int ac, char **av)
{
	if (ac != 2 || ac == NULL)
		error();
	if (string("-h") == av[1])
		usage(av);
	ifstream ifs;
	ifs.open (av[1]);
	if (!ifs)
		error();
	ifs.close();
}
