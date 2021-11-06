//
// EPITECH PROJECT, 2018
// hotline.cpp
// File description:
// hotline.cpp
//

#include "hotline.hpp"

Hotline::Hotline()
{}

Hotline::~Hotline()
{
}

int Hotline::Combination()
{
	mpz_class n(param1);
	mpz_class k(param2);
	mpz_class ret(1);

	for (int i = 0; i < k; i++) {
		ret = ret * (n - i) / (i + 1);
	}
	std::cout << k << "-combination of a " << n << " set:" << std::endl;
	std::cout << ret;
	std::cout << std::endl;
	return (0);
}

int Hotline::Param(int p1, int p2)
{
	param1 = p1;
	param2 = p2;
	return (1);
}

double calc_combi(int k, int n)
{
	double ret = 1;

	for (int i = 1; i <= k; i++) {
		ret = ret * n;
		ret = ret / i;
		n--;
	}
	return (ret);
}

int Hotline::Binomial()
{
	double proba_appel = (param1 / (8.0 * 3600.0));
	double proba_binom;
	double sum = 0;
	int time = 0;

	std::cout << "Binomial distribution:" << std::endl << std::setprecision(3);
	for (int i = 0; i <= 50; i++) {
		proba_binom = calc_combi(i, 3500) * std::pow(proba_appel, i) * std::pow((1 - proba_appel), 3500 - i);
		if (i <= 25)
			sum += proba_binom;
		std::cout << i << " -> " << std::fixed << proba_binom;
		std::cout << (i % 6 == 5 || i == 50 ? "\n" : "\t");
	}
	time = clock();
	std::cout << "overload:  " << std::setprecision(1) << 100.0 * (1 - sum) << "%" << std::endl;
	std::cout << "computation time:  " << std::fixed << time << " ms\n" << std::endl;
	return (0);
}

int Hotline::Poisson()
{
	double lambda;
	double proba_poisson;
	double sum = 0;
	int time;

	std::cout << "Poisson distribution:" << std::endl << std::setprecision(3);
	for (int i = 0; i <= 50; i++) {
		lambda = (3500 / (8.0 * 3600.0)) * (double)param1;
		proba_poisson = std::exp(-lambda) * std::pow(lambda, i);
		for (int j = 1; j <= i; j++)
			proba_poisson /= j;
		if (i <= 25)
			sum += proba_poisson;
		std::cout << i << " -> " << std::fixed << proba_poisson;
		std::cout << (i % 6 == 5 || i == 50 ? "\n" : "\t");
	}
	time = clock();
	std::cout << "overload:  " << std::setprecision(1) << 100.0 * (1 - sum) << "%" << std::endl;
	std::cout << "computation time:  " << std::fixed << time << std::setprecision(2) << " ms" << std \
::endl;
	return (0);
}
