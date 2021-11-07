//
// EPITECH PROJECT, 2018
// Fruit.cpp
// File description:
// Fruit.cpp
//

#include "Fruit.hpp"

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

int Fruit::getVitamins() const
{
	return _vitamins;
}

std::string Fruit::getName() const
{
	return _name;
}
