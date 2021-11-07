//
// EPITECH PROJECT, 2018
// PlasmaRifle.hpp
// File description:
// PlasmaRifle.hpp
//


#ifndef __PLASMARIFLE_H__
#define __PLASMARIFLE_H__

#include <string>
#include <iostream>

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
protected:

public:
	PlasmaRifle();
	virtual ~PlasmaRifle();

	virtual void attack() const;
};

#endif
