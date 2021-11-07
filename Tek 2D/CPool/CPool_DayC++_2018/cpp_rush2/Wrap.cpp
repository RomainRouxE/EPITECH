//
// EPITECH PROJECT, 2018
// Wrap.cpp
// File description:
// Function of Wrap
//

#include<iostream>
#include<string>
#include"Wrap.hpp"

Wrap::Wrap() : Object()
{
	this->open = true;
	this->gift = NULL;
	std::cout << "whistles while working" << std::endl;
}

Wrap::~Wrap() {}

void Wrap::wrapMeThat(Object *gift)
{
	if (this->gift == NULL) {
		this->gift = gift;
		std::cout << "tuuuut tuuut tuut" << std::endl;
	}
	else
		std::cerr << "There is already a gift" << std::endl;
}

void Wrap::openMe()
{
	this->open = true;
	this->gift = NULL;
}

void Wrap::closeMe()
{
	this->open = false;
}
