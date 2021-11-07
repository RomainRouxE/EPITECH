//
// EPITECH PROJECT, 2018
// Coconut.hpp
// File description:
// Coconut.hpp
//

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include <iostream>
#include <string>
#include "Fruit.hpp"

class Coconut: public Fruit
{
public:
	Coconut();
	~Coconut();
	int getVitamins() const;
	std::string getName() const;
};

#endif
