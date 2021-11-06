//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "../include/AbstractVM.hpp"

int main(int ac, char **av)
{
	try {
		AbstractVM vm(ac, av);
		vm.load_line();
		mv._exec();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
	return (0);
}
