//
// EPITECH PROJECT, 2018
// Box.cpp
// File description:
// Function of Box
//

#include<iostream>
#include<string>
#include"Box.hpp"

Box::Box() : Wrap() {}

Box::~Box() {}

void Box::wrapMeThat(Object *gift)
{
	if (this->open == true && this->gift == NULL) {
		this->gift = gift;
		this->open = false;
		std::cout << "tuuuut tuuut tuut" << std::endl;
	}
	else if (this->open == false)
		std::cerr << "The wrap is close" << std::endl;
	else
		std::cerr << "There is already a gift" << std::endl;
}
