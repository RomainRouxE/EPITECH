//
// EPITECH PROJECT, 2018
// Warrior.hpp
// File description:
// Warrior.hpp
//

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include <iostream>
#include "Character.hpp"

class Warrior: public Character
{
private:
	std::string _weaponName;
	
public:
	Warrior(std::string name, int lvl, std::string weaponName = "hammer");
	~Warrior();
	int CloseAttack();
	int RangeAttack();
};

#endif
