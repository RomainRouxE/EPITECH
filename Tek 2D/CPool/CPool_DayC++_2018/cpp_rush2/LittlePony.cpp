//
// EPITECH PROJECT, 2018
// LittlePony.cpp
// File description:
// Function of Little Pony
//

#include <iostream>
#include <string>
#include "LittlePony.hpp"

LittlePony::LittlePony(std::string title) : Toy()
{
        this->title = title;
}

LittlePony::~LittlePony() {}

void LittlePony::isTaken()
{
        std::cout << "yo man" << std::endl;
}
