//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main.cpp
//

#include "204ducks.hpp"

static bool is_number(char *str)
{
        int i = 0;
	int a = 0;

        while (str[i]) {
                if (i == 0 && (str[i] == '-' || str[i] == '+'))
                        i++;
		else if (str[i] == '.' && a == 0) {
			a++;
			i++;
		}
		else if (str[i] < '0' || str[i] > '9')
                        return (false);
                else
                    	i++;
        }
        return (true);
}

static void usage(char **av)
{
	std::cout << "USAGE" << std::endl;
	std::cout << "\t\t" << av[0] << " a" << std::endl;
	std::cout << "DESCRIPTION" << std::endl;
	std::cout << "\t\ta\tconstant" << std::endl;
	exit(0);
}

static void error()
{
	std::cerr << "Bad argument" << std::endl;
	exit(84);
}

int main(int ac, char **av)
{
	double x;

	if (ac != 2)
		error();
	x = atof(av[1]);
	if (std::string("-h") == av[1])
		usage(av);
	else if (is_number(av[1]) && x > 0 && x <= 2.5) {
		average(x);
		Timeducks(x);
		Percentage(x);
	}
	else
		error();
}
