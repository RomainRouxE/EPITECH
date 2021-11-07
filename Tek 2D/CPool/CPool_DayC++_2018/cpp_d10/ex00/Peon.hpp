//
// EPITECH PROJECT, 2018
// Peon.hpp
// File description:
// Peon.hpp
//

#ifndef __PEON_HPP_
#define __PEON_HPP_

#include <string>
#include <iostream>

#include "Victim.hpp"

class Peon : public Victim {
protected:
	
public:
	Peon(std::string name);
	virtual ~Peon();
	
	void getPolymorphed() const;
	
};

#endif
