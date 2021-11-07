//
// EPITECH PROJECT, 2018
// Object.cpp
// File description:
// Function of Object
//

#include <iostream>
#include <string>
#include "Object.hpp"

Object::Object() {}

Object::~Object() {}

void Object::isTaken() {}

void Object::wrapMeThat(Object *gift)
{
	if (gift) {
		std::cout << "tuuuut tuuut tuut" << std::endl;
	}
	else
		std::cerr << "There is already a gift" << std::endl;
}
