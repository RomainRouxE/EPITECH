//
// EPITECH PROJECT, 2018
// algo.cpp
// File description:
// algo.cpp
//

#include "301dannon.hpp"

static void error()
{
	std::cerr << "Empty file or not only number" << std::endl;
	exit(84);
}

bool is_num(const std::string& s)
{
	int i = 0;
	int a = 0;
	std::string::const_iterator num = s.begin();

	while (num != s.end()) {
		if (std::isdigit(*num) || *num == '.' || *num == '-') {
			if (*num == '.')
				i++;
			if (*num == '-')
				a++;
		}
		else
			error();
		if (i > 1 || a > 1)
			error();
		num++;
	}
	return (true);
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
	while (std::getline(iStrinfStream, word, ' ')) {
		is_num(word);
		list.push_back(std::atof(word.c_str()));
	}
	if (list.size() <= 0)
		error();
	if (list.size() == 1)
		std::cout << list.size() << " element" << std::endl;
	else
		std::cout << list.size() << " elements" << std::endl;
	int a = select(list);
	int b = insert(list);
	int c = bubble(list);
	std::cout << "select sort: " << a;
	if (a != 0)
		std::cout << " comparisons" << std::endl;
	else
		std::cout << " comparison" << std::endl;
	std::cout << "insertion sort: " << b;
	if (b != 0)
		std::cout << " comparisons" << std::endl;
	else
		std::cout << " comparison" << std::endl;
	std::cout << "bubble sort: " << c;
	if (c != 0)
		std::cout << " comparisons" << std::endl;
	else
		std::cout << " comparison" << std::endl;
	std::cout << "fusion sort: " << " comparisons" << std::endl;
	std::cout << "quick sort: " << " comparisons" << std::endl;
}
