//
// EPITECH PROJECT, 2018
// Victim.hpp
// File description:
// Vitcim.hpp
//

#ifndef __VICTIM_HPP_
#define __VICTIM_HPP_

#include <string>
#include <iostream>

class Victim {
protected:
	std::string name;
	
public:
	Victim(std::string name);
	virtual ~Victim();

	virtual std::string getName() const;
	
	virtual void getPolymorphed() const;
	
};

std::ostream & operator<<(std::ostream & os, Victim & victim);

#endif
