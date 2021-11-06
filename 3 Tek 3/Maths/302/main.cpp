//
// EPITECH PROJECT,
// main.cpp
// File description:
// main.cpp
//

#include "302separation.hpp"

static void error()
{
	cerr << "File doesn't exist / error" << endl;
	exit(84);
}

static void usage(char **av)
{
	cout << "USAGE" << endl;
	cout << "\t   ./302separation file [n | p1 p2]"<< endl;
	cout << "DESCRIPTION" << endl;
	cout << "\t   file    file that contains the list of Facebook connections" << endl;
	cout << "\t   n       maximum length of the paths" << endl;
	cout << "\t   pi      name of someone in the file" << endl;
	exit(0);
}

bool is_num(string nb)
{
	for (int x = 0; x < nb.size(); x++)
		if (!(nb[x] >= '0' && nb[x] <= '9'))
			return (false);
	return (true);
}

int main(int ac, char **av)
{
	if (ac == NULL)
		error();
	if (ac == 2 && string("-h") == av[1])
		usage(av);

	ifstream ifs;
	ifs.open (av[1]);
	if (!ifs)
		error();
	ifs.close();

	if(ac == 3 && is_num(av[2])) {
		matrix(av);
	}
	else if (ac == 4) {
		sseparation(av);
	}
	else
		error();
}
