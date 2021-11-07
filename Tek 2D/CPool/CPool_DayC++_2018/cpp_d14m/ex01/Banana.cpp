//
// EPITECH PROJECT, 2018
// Banana.cpp
// File description:
// Banana.cpp
//

#include "Banana.hpp"

Banana::Banana() : Fruit()
{
	_vitamins = 5;
	_name = "banana";
}

Banana::~Banana()
{
}

int Banana::getVitamins() const
{
	return _vitamins;
}

std::string Banana::getName() const
{
	return _name;
}
