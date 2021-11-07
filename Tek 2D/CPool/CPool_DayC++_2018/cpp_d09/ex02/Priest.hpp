//
// EPITECH PROJECT, 2018
// Priest.hpp
// File description:
// Priest.hpp
//

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include <iostream>
#include "Mage.hpp"

class Priest: public Mage
{
public:
	Priest(std::string name, int lvl);
	~Priest();
	int CloseAttack();
	int RangeAttack();
	void Heal();
};

#endif
