//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main.cpp
//

#include "bollinger.hpp"

static bool is_num(char *str)
{
	int i = 0;
	int a = 0;

	while (str[i]) {
		if (i != 0 && a == 0 && str[i] == '.') {
			i++;
			a++;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (false);
		else
			i++;
	}
	return (true);
}

void help()
{
	cout << "Bollinger Bands" << endl << endl;
	cout << "USAGE" << endl;
	cout << "\tperiod\t\tnumberof indexes for the moving average" << endl;
	cout << "\tstandard_dev\tstandard deviation coefficient to apply" << endl;
	cout << "\tindexes_file\tfile containing daily indexes" << endl;
	cout << "\tindex_number\tindex number to compute moving average and Bollinger bands" << endl << endl;
	cout << "OPTIONS" << endl;
	cout << "\t-h\t\tprint the usage and quit." << endl;
	exit(0);
}

static void error()
{
	std::cerr << "error" << std::endl;
	exit(84);
}

int main(int ac, char **av)
{
	int x;

	if (ac == 2 && (string(av[1]) == "-h" || string(av[1]) == "--help"))
		help();
	if (av[1] == NULL || ac != 5)
		error();
	for (x = 1; x != ac && x != 3; x++) {
		if (is_num(av[x]) == false)
			error();
	}
	string a = av[3];
	ifstream file(a);
	if(file) {
		Bollinger bollinger(atoi(av[1]), stod(av[2]), av[3], atoi(av[4]));
		bollinger.print();
		file.close();
		exit(0);
	}
	else
		error();
}
