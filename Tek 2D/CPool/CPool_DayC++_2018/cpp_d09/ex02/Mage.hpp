//
// EPITECH PROJECT, 2018
// Mage.hpp
// File description:
// Mage.hpp
//

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include <iostream>
#include "Character.hpp"

class Mage: public Character
{
public:
	Mage(std::string name, int lvl);
	~Mage();
	int CloseAttack();
	int RangeAttack();
	void RestorePower();
};

#endif
