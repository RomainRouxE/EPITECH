//
// EPITECH PROJECT, 2018
// Skat.cpp
// File description:
// Skat.cpp
//

#include "Skat.hpp"
#include <string>
#include <iostream>

Skat::Skat(std::string const& name, int stimPaks)
{
	this->_name = name;
	this->_stimPaks = stimPaks;
}

Skat::Skat(std::string const& name)
{
	this->_name = name;
	this->_stimPaks = 15;
}

Skat::Skat(int stimPaks)
{
	this->_name = "bob";
	this->_stimPaks = stimPaks;
}

Skat::Skat()
{
	this->_name = "bob";
	this->_stimPaks = 15;
}

Skat::~Skat()
{
}

int&	Skat::stimPaks()
{
	return (_stimPaks);
}

std::string	const& Skat::name()
{
	return (_name);
}

void	Skat::shareStimPaks(int number, int &stock)
{
	if (number <= _stimPaks)
	{
		stock = stock + number;
		_stimPaks = _stimPaks + number;
		std::cout << "Keep the change." << std::endl;
	}
	else
		std::cout << "Don’t be greedy" << std::endl;
}

void	Skat::addStimPaks(unsigned int number)
{
	_stimPaks += number;
	if (number == 0)
		std::cout << "Hey boya, did you forget something ?" << std::endl;
}

void	Skat::useStimPaks()
{
	if (_stimPaks > 0)
	{
		_stimPaks--;
		std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
	}
	else
		std::cout << "Mediiiiiic" << std::endl;
}

void	Skat::status()
{
	std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir !" <<std::endl;
}
