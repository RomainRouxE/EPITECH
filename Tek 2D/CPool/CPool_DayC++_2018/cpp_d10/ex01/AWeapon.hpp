//
// EPITECH PROJECT, 2018
// AWeapon.hpp
// File description:
// AWeapon.hpp
//

#ifndef __AWEAPON_HPP_
#define __AWEAPON_HPP_

#include <string>
#include <iostream>

class AWeapon {
protected:
	std::string name;
	int apcost;
	int damage;

public:
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon();

	std::string const & getName() const;
	int getAPCost() const;
	int getDamage() const;

	virtual void attack() const = 0;

};

#endif
