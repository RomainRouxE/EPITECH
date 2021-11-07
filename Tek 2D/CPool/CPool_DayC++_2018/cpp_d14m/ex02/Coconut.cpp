//
// EPITECH PROJECT, 2018
// Coconut.cpp
// File description:
// Coconut.cpp
//

#include "Coconut.hpp"

Coconut::Coconut() : Fruit()
{
	_vitamins = 15;
	_name = "coconut";
}

Coconut::~Coconut()
{
}

std::string Coconut::getName() const
{
	return _name;
}

int Coconut::getVitamins() const
{
	return _vitamins;
}
