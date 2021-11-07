//
// EPITECH PROJECT, 2018
// Banana.hpp
// File description:
// Banana.hpp
//

#ifndef BANANA_HPP_
#define BANANA_HPP_

#include "Fruit.hpp"

class Banana : public Fruit
{
public:
	Banana();
	~Banana();
	int getVitamins() const;
	std::string getName() const;
};

#endif
