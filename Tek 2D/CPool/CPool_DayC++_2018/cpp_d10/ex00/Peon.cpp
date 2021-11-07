//
// EPITECH PROJECT, 2018
// Peon.cpp
// File description:
// Peon.cpp
//

#include "Peon.hpp"

Peon::Peon(std::string name)
	: Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const {
	std::cout << name << " has been turned into a pink pony !" << std::endl;
}
