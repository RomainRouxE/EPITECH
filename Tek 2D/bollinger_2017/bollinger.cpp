//
// EPITECH PROJECT, 2018
// bollinger.cpp
// File description:
// bollinger.cpp
//

#include "bollinger.hpp"

Bollinger::Bollinger(size_t period, double SDCoef, string filename, size_t index
) : period(period), SDCoef(SDCoef), filename(filename), index(index), defIndex(index)
{
	Values(filename);
	Mean();
	StandardDeviation();
	Bands();
}

void Bollinger::Values(string filename)
{
	ifstream file(filename);
	string content;

	while (getline(file, content))
		values.push_back(stod(content));
	maxIndex = values.size() - 1;
	file.close();
}

bool Bollinger::changeIndex(size_t index)
{
	if (index > maxIndex)
		return false;
	index = index;
	Mean();
	StandardDeviation();
	Bands();
	return true;
}

void Bollinger::Mean()
{
	double sum = 0.0;
	int start = index - period + 1;

	if (start < 0)
		start = 0;
	for (size_t idx = (size_t)start; idx <= index; idx++)
		sum += values[idx];
	mean = sum / (double)(index - (size_t)start + 1);
}

void Bollinger::StandardDeviation()
{
	double sum = 0.0;
	int start = index - period + 1;

	if (start < 0)
		start = 0;
	for (size_t idx = (size_t)start; idx <= index; idx++)
		sum += pow(values[idx] - mean, 2);
	SD = sqrt(sum / (double)(index - (size_t)start + 1));
}

void Bollinger::Bands()
{
	upperBand = mean + (SD * SDCoef);
	lowerBand = mean - (SD * SDCoef);
}

const vector<double> &Bollinger::Values() const
{
	return (values);
}

const size_t &Bollinger::Index() const
{
	return (index);
}

const size_t &Bollinger::MaxIndex() const
{
	return (maxIndex);
}

const size_t &Bollinger::DefaultIndex() const
{
	return (defIndex);
}

const size_t &Bollinger::Period() const
{
	return (period);
}

const double &Bollinger::setSDCoef() const
{
	return (SDCoef);
}

const double &Bollinger::Mean() const
{
	return (mean);
}

const double &Bollinger::setSD() const
{
	return (SD);
}

const double &Bollinger::UpperBand() const
{
	return (upperBand);
}

const double &Bollinger::LowerBand() const
{
	return (lowerBand);
}

void Bollinger::print()
{
	cout << "INPUT" << endl;
	cout << "Index: " << index << endl;
	cout << "Period: " << period << endl;
	cout << "SD_coef: " << fixed << setprecision(2) << SDCoef << endl << endl;
	cout << "OUTPUT" << endl;
	cout << "MA: " << fixed << setprecision(2) << mean << endl;
	cout << "SD: " << fixed << setprecision(2) << SD << endl;
	cout << "B+: " << fixed << setprecision(2) << upperBand << endl;
	cout << "B-: " << fixed << setprecision(2) << lowerBand << endl;
}
