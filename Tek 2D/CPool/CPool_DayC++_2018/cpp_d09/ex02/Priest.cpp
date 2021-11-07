//
// EPITECH PROJECT, 2018
// Priest.cpp
// File description:
// Priest.cpp
//

#include <iostream>
#include <string>
#include "Priest.hpp"
#include "Mage.hpp"

Priest::Priest(std::string name, int lvl) : Mage(name, lvl)
{
	this->_force = 4;
	this->_endurance = 4;
	this->_intelligence = 42;
	this->_esprit = 21;
	this->_agilite = 2;
	std::cout << _name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
	if (Range == Priest::CLOSE) {
		if (_power >= 10) {
			_power -= 10;
			std::cout << _name << " uses a spirit explosion" << std::endl;
			return (10 + _esprit);
		}
		std::cout << _name << " out of power" << std::endl;
		_power = 0;
	}
	return (0);
}

int Priest::RangeAttack()
{
	if (Range == Priest::RANGE) {
		if (_power >= 25) {
			_power -= 25;
			std::cout << _name << " launches a fire ball" << std::endl;
			return (20 + _esprit);
		}
		std::cout << _name << " out of power" << std::endl;
		_power = 0;
	}
	return (0);
}

void Priest::Heal()
{
	if (_power >= 25) {
		_power -= 25;
		_pv += 70;
		if (_pv > 100)
			_pv = 100;
		std::cout << _name << " casts a little heal spell" << std::endl;
	}
	else {
		_power = 0;
		std::cout << _name << " out of power" << std::endl;
	}
}
