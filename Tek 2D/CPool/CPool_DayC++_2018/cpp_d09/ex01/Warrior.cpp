//
// EPITECH PROJECT, 2018
// Warrior.cpp
// File description:
// Warrior.cpp
//

#include <iostream>
#include <string>
#include "Warrior.hpp"
#include "Character.hpp"

Warrior::Warrior(std::string name, int lvl, std::string weaponName) : Character(name, lvl), _weaponName(weaponName)
{
	this->_force = 12;
	this->_endurance = 12;
	this->_intelligence = 12;
	this->_esprit = 5;
	this->_agilite = 7;
	std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
	if (Range == Character::CLOSE) {
		if (_power >= 30) {
			_power -= 30;
			std::cout << _name << " strikes with his " << _weaponName << std::endl;
			return (20 + _force);
		}
		std::cout << _name << " out of power" << std::endl;
		_power = 0;
	}
	return (0);
}

int Warrior::RangeAttack()
{
	if (Range == Character::RANGE) 	{
		if (_power >= 10) {
			_power -= 10;
			std::cout << _name << " intercepts" << std::endl;
			Range = Character::CLOSE;
			return (0);
		}
		std::cout << _name << " out of power" << std::endl;
		_power = 0;
	}
	return (0);
}
