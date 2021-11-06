//
// EPITECH PROJECT, 2019
// algo.cpp
// File description:
// algo.cpp
//

#include "307.hpp"

static void error()
{
	std::cerr << "Empty file or other error" << std::endl;
	exit(84);
}

void algo(char **av)
{
	std::cout << "Resources: " << av[1] << " F1, " << av[2]
		  << " F2, " << av[3] << " F3," << av[4]
		  << " F4" << std::endl << std::endl;

	std::cout << "Oat: " << "" << "units at $" << av[5] << "/unit" << std::endl;
	std::cout << "Wheat: " << "" << "units at $" << av[6] << "/unit" << std::endl;
        std::cout << "Corn: " << "" << "units at $" << av[7] << "/unit" << std::endl;
        std::cout << "Barley: " << "" << "units at $" << av[8] << "/unit" << std::endl;
        std::cout << "Soy: " << "" << "units at $" << av[9] << "/unit" << std::endl;
	std::cout << std::endl;
	std::cout << "Totl production value: $" << "" << std::endl;
	exit(0);
}
