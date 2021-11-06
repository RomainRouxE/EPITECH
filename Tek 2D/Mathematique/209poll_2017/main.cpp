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
	int a = 0;

	while (str[i]) {
		if (i != 0 && a == 0 && str[i] == '.') {
			i++;
			a++;
		}
		else if (str[i] < '0' || str[i] > '9' || str[i] == '.' && a != 0)
			return (false);
		else
			i++;
	}
	return (true);
}

static void usage(char **av)
{
	std::cout << "USAGE" << std::endl;
	std::cout << "\t   " << av[0] << " pSize sSize p" << std::endl;
	std::cout << std::endl;
	std::cout << "DESCRIPTION" << std::endl;
	std::cout << "\t   ppSize  size of the population" << std::endl;
	std::cout << "\t   sSize   size of the sample (supposed to be representative)" << std::endl;
	std::cout << "\t   p       percentage of voting intentions for a specific candidate" << std::endl;
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
	double pop;
	double sam;
	double inte;
	double var;
	double p;
	double ci1;
	double ci2;
	double c1;
	double c2;
	double c3;
	double c4;

	if (av[1] == NULL || ac != 4)
		error();
	if (std::string("-h") == av[1])
		usage(av);
	for (x = 1; x != ac; x++) {
		if (is_num(av[x]) == false)
			error();
	}
	if (atof(av[2]) > atof(av[1]) || atof(av[3]) < 0 || atof(av[3]) > 100)
		error();

	pop = atof(av[1]);
	sam = atof(av[2]);
	inte = atof(av[3]);

	p = inte / 100;
	var = ((p * (1 - p)) / sam) * ((pop - sam) / (pop - 1));
	ci1 = (2 * 1.96 * sqrt(var)) / 2 * 100;
	ci2 = (2 * 2.58 * sqrt(var)) / 2 * 100;
	c1 = inte - ci1;
	if (c1 < 0)
		c1 = 0;
	c2 = inte + ci1;
	if (c2 > 100)
		c2 = 100;
	c3 = inte - ci2;
	if (c3 < 0)
		c3 = 0;
	c4 = inte + ci2;
	if (c4 > 100)
		c4 = 100;

	std::cout << "population size:           " << pop << std::endl;
	std::cout << "sample size:               " << sam << std::endl;
	std::cout << "voting intentions:         " << inte << "%" << std::endl;

	std::cout << std::setprecision(6) << std::fixed;

	std::cout << "variance:                  " << var << std::endl;

	std::cout << std::setprecision(2) << std::fixed;

	std::cout << "95% confidence interval:   [" << c1 << "% ; " << c2 << "%]" << std::endl;
	std::cout << "99% confidence interval:   [" << c3 << "% ; " << c4 << "%]" << std::endl;
}
