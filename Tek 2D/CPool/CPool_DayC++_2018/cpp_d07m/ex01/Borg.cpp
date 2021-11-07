//
// EPITECH PROJECT, 2018
// Borg.cpp
// File description:
// Borg.cpp
//


#include <iostream>
#include <string>
#include "WarpSystem.hpp"
#include "Federation.hpp"
#include "Borg.hpp"

Borg::Ship::Ship()
{
	this->_side = 300;
	this->_maxWarp = 9;
	
	std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
	
}

void Borg::Ship::setupCore(WarpSystem::Core *_core)
{
	this->Core = _core;
}

void Borg::Ship::checkCore()
{
	if (this->Core->checkReactor()->isStable() == true)
		std::cout << "Everything is in order." << std::endl;
	else
		std::cout << "Critical failure imminent." << std::endl;
}
