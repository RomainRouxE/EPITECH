//
// EPITECH PROJECT, 2019
// algo.cpp
// File description:
// algo.cpp
//

#include "305.hpp"

static void error()
{
	std::cerr << "Empty file or other error" << std::endl;
	exit(84);
}

void algo(char **av)
{
	std::ifstream (ifs);
	ifs.open (av[1]);
	std::vector<double> list;
	std::string line;
	std::getline(ifs, line);

	std::string word;
	std::istringstream iStrinfStream(line);
	while (std::getline(iStrinfStream, word, ';')) {
		list.push_back(std::atof(word.c_str()));
	}
	if (list.size() <= 0)
		error();
	std::cout << "Total duration of construction:" << std::endl;
	std::cout << "Lan must begin at t=0" << std::endl;
	error();
}
