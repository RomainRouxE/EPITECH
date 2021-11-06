//
// EPITECH PROJECT, 2018
// 205IQ.cpp
// File description:
// 205IQ.cpp
//

#include "205IQ.hpp"

double gauss(double u, double o, double x)
{
	return ((1 / (o * sqrt(2 * M_PI)) * exp(-(pow((x - u), 2) / (2 * pow(o, 2))))));
}

void option1(double u, double o, double IQ1)
{
	double x;
	double res = 0;
	int a;

	for (x = 0; x < IQ1; x += 0.01) {
		res = res + gauss(u, o, x);
	}
	a = res;
	if ((a + 1) % 100 == 0 || a % 100 == 0 && a != 1 && a != 0)
                std::cout << "100.0% of people have an IQ inferior to " << IQ1 << std::endl;
	else if ((a - 1) == 0 || a == 0)
		std::cout << "0.0% of people have an IQ inferior to " << IQ1 << std::endl;
	else {
		std::cout << std::setprecision(3) << res;
		std::cout << "% of people have an IQ inferior to " << IQ1 << std::endl;
	}
}

void option2(double u, double o, double IQ1, double IQ2)
{
	double x;
	double res = 0;
	int a;

	for (x = IQ1; x < IQ2; x += 0.01) {
                res = res + gauss(u, o, x);
        }
	a = res;
        if ((a + 1) % 100 == 0 || a % 100 == 0 && a != 1 && a != 0)
		std::cout << "100.0% of people have an IQ between " << IQ1 << "and " << IQ2 << std::endl;
        else if ((a - 1) == 0 || a == 0)
                std::cout << "0.0% of people have an IQ betweeno " << IQ1 << " and " << IQ2 << std::endl;
        else {
		a = res;
		if (a < 10)
			std::cout << std::setprecision(2) << res;
		else
			std::cout << std::setprecision(3) << res;
		std::cout << std::setprecision(3) << "% of people have an IQ between " << IQ1 << " and " << IQ2 << std::endl;
	}
}
