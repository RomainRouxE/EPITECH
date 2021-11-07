//
// EPITECH PROJECT, 2018
// Federation.cpp
// File description:
// Federation.cpp
//

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
	: _length(length), _width(width), _name(name), _maxWarp(maxWarp)
{
	std::cout << "The ship USS " << this->_name
		  << " has been finished. It is " << this->_length
		  << " m in length and " << this->_width << " m in width."
		  << std::endl;
	std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
	: _length(length), _width(width), _name(name), _maxWarp(1)
{
	std::cout << "The independant ship " << this->_name
		  << " just finished its construction. It is "
		  << this->_length << " m in length and " << this->_width
		  << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
	
}

Federation::Starfleet::Ship::~Ship()
{
	
}

void	Federation::Starfleet::Ship::setupCore(WarpSystem::Core*PtrCore)
{
	this->_core = PtrCore;
	std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void	Federation::Ship::setupCore(WarpSystem::Core*PtrCore)
{
	this->_core = PtrCore;
	std::cout << this->_name << ": The core is set." << std::endl;
}

void	Federation::Starfleet::Ship::checkCore()
{
	if (this->_core->checkReactor()->isStable() == true)
		std::cout << "USS " << this->_name
			  << ": The core is stable at the time." << std::endl;
	else
		std::cout << "USS " << this->_name
			  << ": The core is unstable at the time." << std::endl;
}

void	Federation::Ship::checkCore()
{
	if (this->_core->checkReactor()->isStable() == true)
		std::cout << this->_name << ": The core is stable at the time."
			  << std::endl;
	else
		std::cout << this->_name << ": The core is unstable at the time."
			  << std::endl;
}
