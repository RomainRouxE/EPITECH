//
// EPITECH PROJECT, 2018
// Lemon.cpp
// File description:
// Lemon.cpp
//

#include "Lemon.hpp"

Lemon::Lemon() : Fruit()
{
	_vitamins = 3;
	_name = "lemon";
}

Lemon::~Lemon()
{
}

int Lemon::getVitamins() const
{
	return _vitamins;
}

std::string Lemon::getName() const
{
	return _name;
}
