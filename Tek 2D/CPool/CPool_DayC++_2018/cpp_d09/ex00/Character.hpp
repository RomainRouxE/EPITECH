//
// EPITECH PROJECT, 2018
// Character.hpp
// File description:
// Character.hpp
//

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>

class Character
{
public:
	enum AttackRange
	{
		CLOSE,
		RANGE
	};
	AttackRange Range;
	
private:
	std::string _name;
	std::string _race;
	int _lvl;
	int _power;
	int _pv;
	int _force;
	int _endurance;
	int _intelligence;
	int _esprit;
	int _agilite;
	
public:
	Character(std::string name, int lvl);
	~Character();
	const std::string &getName() const;
	int getLvl() const;
	int getPv() const;
	int getPower() const;
	int CloseAttack();
	int RangeAttack();
	void Heal();
	void RestorePower();
	void TakeDamage(int _damage);
};

#endif
