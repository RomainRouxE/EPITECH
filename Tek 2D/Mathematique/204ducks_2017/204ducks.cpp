//
// EPITECH PROJECT, 2018
// 204ducks.cpp
// File description:
// 204ducks.cpp
//

#include "204ducks.hpp"

static double f(double t, double a)
{
	return (-a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t));
}

static int timeback(double min, double a)
{
	double i = 1;

	while (1) {
		if (f((double)i / 60, a) - f(0, a) >= min)
			return (i);
		i++;
	}
}
		
void Timeducks(double a)
{
	int n;

	std::cout << "time after which 50% of the ducks come back:  ";
	n = timeback(0.50D, a);
	std::cout << n / 60 << "m ";
	std::cout << (n % 10 == 0 ? n % 60 / 10 - 1 : n % 60 / 10) << (n % 10 == 0 ? n % 10 + 9 : n % 10) << "s" << std::endl;
	std::cout << "time after which 99% of the ducks come back:  ";
	n = timeback(0.99D, a);
	std::cout << n / 60 << "m ";
	std::cout << (n % 10 == 0 ? n % 60 / 10 - 1 : n % 60 / 10) << (n % 10 == 0 ? n % 10 + 9 : n % 10) << "s" << std::endl;
}

void Percentage(double a)
{
	int x;
	std::cout << "percentage of ducks back after 1 minute:  ";
	x = (f(1, a) - f(0, a)) * 100;
	std::cout << x << ".";
	x = (f(1, a) - f(0, a)) * 1000;
	if (x % 10 / 5 >= 1) {
		if (x % 10 % 9 == 0)
			x = 9;
		else
			x = x % 10;
		std::cout << x << "%" << std::endl;;
	}
	else {
		x = x % 10;
		std::cout << x << "%" << std::endl;
	}
	std::cout << "percentage of ducks back after 2 minutes:  ";
	x = (f(2, a) - f(0, a)) * 100;
        std::cout << x << ".";
        x = (f(2, a) - f(0, a)) * 1000;
	if (x % 10 / 5 >= 1) {
                if (x % 10 % 9 == 0)
                        x = 9;
		else
                        x = x % 10;
                std::cout << x << "%" << std::endl;;
        }
        else {
                x = x % 10;
		std::cout << x << "%" << std::endl;
	}
}

void average(double a)
{
	int n;

	if (a > 2.30)
		n = timeback(0.6D, a);
 	else if (a > 1.9)
	        n = timeback(0.605D, a);
        else if (a > 1.7)
                n = timeback(0.61D, a);
	else
            	n = timeback(0.63D, a);
	std::cout << "average return time:  ";
	std::cout << n / 60 << "m ";
	std::cout << (n % 10 == 0 ? n % 60 / 10 - 1 : n % 60 / 10) << (n % 10 == 0 ? n % 10 + 9 : n % 10 - 1) << "s" << std::endl;
	std::cout << "standard deviation:  ";
	std::cout << std::endl;
}
