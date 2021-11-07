//
// EPITECH PROJECT, 2018
// ConveyorBelt.cpp
// File description:
// Function of ConveyorBelt
//

#include <iostream>
#include <string>
#include "ConveyorBelt.hpp"

ConveyorBelt::ConveyorBelt()
{
	_button = "IN";
}

ConveyorBelt::~ConveyorBelt()
{

}

std::string ConveyorBelt::getButton() const
{
	return (this->_button);
}
