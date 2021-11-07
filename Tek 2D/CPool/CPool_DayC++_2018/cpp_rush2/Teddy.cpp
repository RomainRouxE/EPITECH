//
// EPITECH PROJECT, 2018
// Teddy.cpp
// File description:
// Function of Teddy
//

#include <iostream>
#include <string>
#include "Teddy.hpp"

Teddy::Teddy(std::string title) : Toy()
{
	this->title = title;
}

Teddy::~Teddy() {}

void Teddy::isTaken()
{
	std::cout << "gra hu" << std::endl;
}
