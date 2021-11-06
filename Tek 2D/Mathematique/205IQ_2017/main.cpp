//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main.cpp
//

#include "205IQ.hpp"

static bool is_number(char *str)
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
	std::cout << "\t   " << av[0] << " u o [IQ1] [IQ2]" << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\t   u\tpredetermined mean" << std::endl;
	std::cout << "\t   o\tpredetermined standard deviation" << std::endl;
	std::cout << "\t   IQ1\tminimum IQ" << std::endl;
	std::cout << "\t   IQ2\tmaximum IQ" << std::endl;
	exit(0);
}

static void error()
{
	std::cerr << "Bad argument" << std::endl;
	exit(84);
}


int main(int ac, char **av)
{
	double a;
	double b;
	double c;
	double d;
	int x;

	if (av[1] == NULL)
		error();
	if (std::string("-h") == av[1])
		usage(av);
	for (x = 1; x != ac; x++) {
		if (is_number(av[x]) == false)
			error();
	}
	if (x == 4) {
		a = atoi(av[1]);
		b = atoi(av[2]);
		c = atoi(av[3]);
		if (a > 200 || b > 200 || c > 200)
			error();
		option1(a, b, c);
	}
	else if (x == 5) {
		a = atoi(av[1]);
		b = atoi(av[2]);
		c = atoi(av[3]);
		d = atoi(av[4]);
		if (a > 200 || b > 200 || c > 200 || d > 200 || c >= d)
			error();
		option2(a, b, c, d);
	}
	else
		error();
}
