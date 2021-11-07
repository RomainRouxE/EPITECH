//
// EPITECH PROJECT, 2018
// PowerFist.hpp
// File description:
// PowerFist.hpp
//


#ifndef __POWERFIST_H__
#define __POWERFIST_H__

#include <string>
#include <iostream>

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
protected:

public:
	PowerFist();
	virtual ~PowerFist();

	virtual void attack() const;

};

#endif
