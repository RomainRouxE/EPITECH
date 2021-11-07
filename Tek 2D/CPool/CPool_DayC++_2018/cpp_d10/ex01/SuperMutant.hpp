//
// EPITECH PROJECT, 2018
// SuperMutant.hpp
// File description:
// SuperMutant.hpp
//

#ifndef __SUPERMUTANT_H__
#define __SUPERMUTANT_H__

#include <string>
#include <iostream>

#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
protected:

public:
	SuperMutant();
	~SuperMutant();

	void takeDamage(int damage);

};

#endif
