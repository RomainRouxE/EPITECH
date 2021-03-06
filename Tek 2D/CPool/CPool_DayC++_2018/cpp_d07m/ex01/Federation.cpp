//
// EPITECH PROJECT, 2018
// Federation.cpp
// File description:
// Federation.cpp
//

#include "WarpSystem.hpp"
#include "Federation.hpp"
#include <iostream>
#include <string>

Federation::Starfleet::Ship::Ship(int length, int width,
				  std::string name, short maxWarp)
{
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = maxWarp;
	std::cout << "The ship USS " << name << " has been finished. It is "
		  << length << " m in length and " << width
		  << " m in width."<< std::endl;;
	std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
	
}

Federation::Ship::~Ship()
{
	
}

Federation::Ship::Ship(int length, int width,
		       std::string name)
{
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = 1;
	std::cout <<"The independant ship "<< name
		  <<" just finished its construction. It is " << length
		  << " m in length and " << width << " m in width."<<std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
	this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

void Federation::Starfleet::Captain::setAge(int age)
{
	this->_age = age;
}

int Federation::Starfleet::Captain::getAge()
{
	return (this->_age);
}

std::string Federation::Starfleet::Captain::getName()
{
	return (this->_name);
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
	this->captain = captain;
	std::cout << this->captain->getName()
		  << ": I'm glad to be the captain of the USS "
		  << this->_name<< "."<<std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *_core)
{
	this->Core = _core;
	std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
	if (this->Core->checkReactor()->isStable() == true)
	{
		std::cout << "USS " << this->_name
			  << ": The core is stable at the time." << std::endl;
	}
	else
		std::cout << "USS " << this->_name
			  << ": The core is unstable at the time." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *_core)
{
	this->Core = _core;
	std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
	if (this->Core->checkReactor()->isStable() == true)
	{
		std::cout << this->_name
			  << ": The core is stable at the time." << std::endl;
	}
	else
		std::cout << this->_name
			  << ": The core is unstable at the time." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
	this->_name = name;
	std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}
