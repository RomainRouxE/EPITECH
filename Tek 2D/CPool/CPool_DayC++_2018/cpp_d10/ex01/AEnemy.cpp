//
// EPITECH PROJECT, 2018
// AEnnemy.cpp
// File description:
// AEnnemy.cpp
//

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, std::string const & type)
: hp(hp), type(type) {

}

AEnemy::~AEnemy()
{

}

std::string const & AEnemy::getType() const
{
	return type;
}

int AEnemy::getHP() const
{
	return hp;
}

void AEnemy::takeDamage(int damage)
{
	if (damage > 0) {
		hp -= damage;
	}
}
