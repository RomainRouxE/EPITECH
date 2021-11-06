//
// EPITECH PROJECT, 2018
// 207demographie.hpp
// File description:
// 207demographie.hpp
//

#ifndef CORE_HPP_
#define CORE_HPP_

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;

class Core {
	fstream _file;
	char **_env;
	ostringstream _stream;
	
	list<string> _args;
	list<string> _names;
	
	vector<int> _years;
	vector<double> _values;
	
	double _a1;
	double _b1;
	
	double _a2;
	double _b2;
	
	double _e1;
	double _e2;
	
public:
	Core() {};
	~Core() {};
	
	void init(int argc, char **argv, char **envp)
	{
		this->_env = envp;
		
		this->_years.resize(51);
		this->_years.assign(51, 0);

		this->_values.resize(51);
		this->_values.assign(51, 0);

		for (int i = 1; i < argc; i++) {
			string toArg(argv[i]);
			std::transform(toArg.begin(), toArg.end(), toArg.begin(), ::toupper);
			this->_args.push_back(toArg);
		}
	}
	
	void run(void)
	{
		int x = 0;
		this->fill();

		cout << setprecision(2) << fixed;
		cout << "country:  " ;
		for (list<string>::iterator it = this->_names.begin(); it != this->_names.end(); it++) {
			if (x != 0)
				cout << ", ";
			cout << *it;
			x++;
		}
		cout << endl;

		cout << "fit 1" << endl;
		this->ajust(this->_years, this->_values, &this->_a1, &this->_b1);
		this->firstCovariance();
		cout << "\tY = " << (this->_a1 / 1000000) << "X";
		cout << ((this->_b1 > 0) ? " + " : " - ");
		cout << (abs(this->_b1) / 1000000) << endl;
		cout << "\tstandard deviation:  " << (this->_e1 / 1000000) << endl;
		cout << "\tpopulation in 2050:  " << ((this->_a1 / 1000000) * 2050 + (this->_b1 / 1000000)) << endl;

		cout << "fit 2" << endl;
		this->_stream << (this->_a1 / 1000000) << " " << (this->_b1 / 1000000);
		this->ajust(this->_values, this->_years, &this->_a2, &this->_b2);
		this->secondCovariance();
		cout << "\tY = " << (this->_a2 * 1000000) << "Y";
		cout << ((this->_b2 > 0) ? " + " : " - ");
		cout << abs(this->_b2) << endl;
		cout << "\tstandard deviation:  " << (this->_e2 / 1000000) << endl;
		cout << "\tpopulation in 2050:  " << (((-(this->_b2) + 2050) / this->_a2) / 1000000) << endl;
	}

	void fill(void)
	{
		for (int i = 0; i <= 50; i++) {
			this->_years[i] = 1961 + i;
		}
		
		for (list<string>::iterator it = this->_args.begin(); it != this->_args.end(); it++) {
			string line;
			char name[512];
			char code[512];
			char token[512];

			this->open();
			while (getline(this->_file, line)) {
				istringstream cell(line);
				
				cell.getline(name, 512, ';');
				cell.getline(code, 512, ';');
				
				if (*it == code) {
					this->_names.push_back(name);
					
					int i(0);
					while (cell.getline(token, 512, ';') and i < 51) {
						this->_values[i] += stringToNumber(token);
						i++;
					}
					break;
				}
			}
			this->close();
		}
	}
	
	template <typename T, typename U>
	void ajust(T x, U y, double *a, double *b)
	{
		double xsomme(0);
		double ysomme(0);
		double xysomme(0);
		double xxsomme(0);
		int n(51);
		
		for (int i = 0; i < n; i++) {
			xsomme += x[i];
			ysomme += y[i];
			xxsomme += pow(x[i], 2);
			xysomme += x[i] * y[i];
		}
		*a = (n * xysomme - xsomme * ysomme) / (n * xxsomme - pow(xsomme, 2));
		*b = (ysomme * xxsomme - xsomme * xysomme) / (n * xxsomme - pow(xsomme, 2));
	}
	
	void firstCovariance(void)
	{
		double ecart(0);
		int n(51);
		
		for (int i = 0; i < n; i++) {
			ecart += pow(this->_values[i] - (this->_a1 * this->_years[i] + this->_b1), 2);
		}
		
		this->_e1 = sqrt(ecart / n);
	}
	
	void secondCovariance(void)
	{
		double ecart(0);
		int n(51);
		
		for (int i = 0; i < n; i++) {
			ecart += pow(this->_values[i] - ((-(this->_b2) + this->_years[i]) / this->_a2), 2);
		}
		
		this->_e2 = sqrt(ecart / n);
	}

	double stringToNumber(const string &value)
	{
		stringstream stream(value);
		double number(0);
		
		stream >> number;
		return number;
	}
	
	string numberToString(double value)
	{
		stringstream stream;
		string str;
		
		stream << value;
		stream >> str;
		return str;
	}
	
	void open(void)
	{
		this->_file.open("207demography_data.csv");
	}
	
	void close(void)
	{
		this->_file.close();
	}
	
};

#endif
