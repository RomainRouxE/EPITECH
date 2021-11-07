//
// EPITECH PROJECT, 2018
// GiftPaper.cpp
// File description:
// Function of GiftPaper
//

#include<iostream>
#include<string>
#include"GiftPaper.hpp"

GiftPaper::GiftPaper() : Wrap() {}

GiftPaper::~GiftPaper() {}

void GiftPaper::wrapMeThat(Object *gift)
{
	if (this->gift == NULL) {
		this->gift = gift;
		std::cout << "tuuuut tuuut tuut" << std::endl;
	}
	else
		std::cerr << "There is already a gift" << std::endl;
}
