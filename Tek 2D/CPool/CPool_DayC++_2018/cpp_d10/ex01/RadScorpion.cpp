//
// EPITECH PROJECT, 2018
// RadScorpion.cpp
// File description:
// RadScorpion.cpp
//

#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
: AEnemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}
