#ifndef HOTLINE_HPP
#define HOTLINE_HPP

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

class Hotline
{
private:
	int param1;
	int param2;
public:
	Hotline();
	~Hotline();
	int Param(int, int);
	int Combination();
	int Binomial();
	int Poisson();
};

#endif
