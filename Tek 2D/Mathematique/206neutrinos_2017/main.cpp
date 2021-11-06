//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main.cpp
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <math.h>
#include <string.h>

static void error()
{
        std::cerr << "Bad argument" << std::endl;
        exit(84);
}

void usage(char **argv)
{
        std::cout << "USAGE" << std::endl;
        std::cout << "\t   " << argv[0] << " n a h sd" << std::endl;
        std::cout << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\t   n\tnumber of values" << std::endl;
        std::cout << "\t   a\tarithmetic mean" << std::endl;
        std::cout << "\t   h\tharmonic mean" << std::endl;
        std::cout << "\t   sd\tstandard deviation" << std::endl;
        exit(0);
}

bool is_num(const std::string& str)
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

double stringToNumber(const std::string &value)
{
	std::stringstream stream(value);
	double number(0);

	stream >> number;
	return (number);
}

int main(int argc, char **argv)
{
	char line[512];
	int x;

	if (argv[1] == NULL)
		error();
	if (std::string("-h") == argv[1])
		usage(argv);
	for (x = 1; x != argc; x++) {
		if (is_number(argv[x]) == false)
			error();
	if (argc == 5) {
		double antal(stringToNumber(argv[1]));
		double aritmetisk(stringToNumber(argv[2]));
		double kvadratisk(0);
		double harmonisk(stringToNumber(argv[3]));
		double standar(stringToNumber(argv[4]));

		while (strcmp(line, "ENDE")) {
			std::cout << "indtast din vaerdi : ";
			std::cin.getline(line, 511);
			if (strcmp(line, "ENDE") == false)
				exit(0);
			std::string indtast(line);
			if (indtast.empty() || is_num(line) == false)
				error();
			else {
				double malinder(stringToNumber(indtast));
				double x(aritmetisk * antal);
				double y((pow(standar, 2) + pow(aritmetisk, 2)) * antal);

				antal++;
				aritmetisk = (x + malinder) / antal;
				standar = sqrt(((y + pow(malinder, 2)) / antal) - pow(aritmetisk, 2));
				kvadratisk = sqrt((y + pow(malinder, 2)) / antal);
				harmonisk = antal / ((1 / malinder) + ((antal - 1) / harmonisk));
				std::cout << std::setprecision(0) << std::fixed;
				std::cout << "\tantal mãlinder :\t" << antal << std::endl;
				std::cout << std::setprecision(2) << std::fixed;
				std::cout << "\tstandardafvilgelse :\t" << standar << std::endl;
				std::cout << "\taritmetisk gennemsnit :\t" << aritmetisk << std::endl;
				std::cout << "\tkvadratisk gennemsnit :\t" << kvadratisk << std::endl;
				std::cout << "\tharmonisk gennemsnit :\t" << harmonisk << std::endl;
				std::cout << std::endl;
			}
		}
		return 0;
	}
	else
		error();
	}
}
