//
// EPITECH PROJECT, 2018
// bollinger.hpp
// File description:
// bollinger.hpp
//

#ifndef	BOLLINGER_HPP_
#define BOLLINGER_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <exception>
#include <iomanip>
#include <cmath>

using namespace std;

class Bollinger {
public:
	Bollinger(size_t, double, string, size_t);
	void print();
	bool changeIndex(size_t);
	const vector<double> &Values() const;
	const size_t &Index() const;
	const size_t &MaxIndex() const;
	const size_t &DefaultIndex() const;
	const size_t &Period() const;
	const double &setSDCoef() const;
	const double &Mean() const;
	const double &setSD() const;
	const double &UpperBand() const;
	const double &LowerBand() const;

private:
	void Values(string);
	void Mean();
	void StandardDeviation();
	void Bands();
	size_t period;
	double SDCoef;
	string filename;
	size_t index;
	size_t maxIndex;
	size_t defIndex;
	vector<double> values;
	double mean;
	double SD;
	double upperBand;
	double lowerBand;
};

#endif
