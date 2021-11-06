//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main.cpp
//

#include "autocompletion.hpp"

static bool isNumber(const std::string &string)
{
	size_t	i;

	i = 0;
	while (i < string.length()) {
		if (string[i] < '0' || string[i] > '9')
			return false;
		i++;
	}
	return true;
}

static bool isStreetType(const std::string &arg)
{
	std::string	string = arg;
	return string == "allée" || string == "avenue" || string == "boulevard" || string == "chemin" || string == "impasse" || string == "place" || string == "quai" || string == "rue" || string == "square";
}

static void usage()
{
	std::cout << "USAGE" << std::endl;
	std::cout << "\t./autocompletion dictionnary" << std::endl << std::endl;
	std::cout << "DESCRIPTION" << std::endl;
	std::cout << "\tdictionnary file, containing one address per line, serving as knowledge base" << std::endl;
	exit(0);
}

static void badArg()
{
	std::cerr << "Invalid argument" << std::endl;
	exit(84);
}

static void noAddress()
{
	std::cerr << "Unknown address" << std::endl;
	exit(84);
}

static bool checkName(const std::string &name)
{
	if (name.empty())
		return false;
	char	c = '0';
	while (c <= '9')
		if (name.find(c++) != std::string::npos)
			return false;
	return true;
}

static bool checkAddress(const std::string &address)
{
	std::vector<std::string> split;
	std::istringstream iss(address);
	std::string tmp;
	while (std::getline(iss, tmp, ' '))
		split.push_back(tmp);
	if (address.empty() || address[0] != ' ' || split.size() < 4 || !isNumber(split[1]) || !isStreetType(split[2]))
		return false;
	return true;
}

static void check(char *path)
{
	std::ifstream stream;
	std::string line;

	stream.open(path);
	while (std::getline(stream, line)) {
		std::vector<std::string> split;
		std::istringstream iss(line);
		std::string tmp;
		while (std::getline(iss, tmp, ','))
			split.push_back(tmp);
		if (split.size() != 2 || !checkName(split[0]) || !checkAddress(split[1]))
			std::cerr << line << std::endl;
	}
	std::getline(std::cin, line);
	if(line == "ABORT")
		exit (0);

	else
		noAddress();
	stream.close();
}

int main(int ac, char **av)
{	
	if (ac != 2)
		badArg();
	if (std::string("-h") == av[1])
		usage();
	std::ifstream file(av[1]);
	if(file) {
		check(av[1]);
		return (0);
	}
	else
		badArg();
}
