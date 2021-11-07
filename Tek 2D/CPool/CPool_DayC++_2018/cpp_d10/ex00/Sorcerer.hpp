//
// EPITECH PROJECT, 2018
// Sorcerer.hpp
// File description:
// Sorcerer.hpp
//

#ifndef __SORCERER_HPP__
#define __SORCERER_HPP__

#include <string>
#include <iostream>

#include "Victim.hpp"

class Sorcerer {
protected:
	std::string name;
	std::string title;

	virtual void speak(std::string message);

public:
	Sorcerer(std::string name, std::string title);
	virtual ~Sorcerer();

	std::string getName() const;
	std::string getTitle() const;

	virtual void polymorph(Victim const & civil) const;

};

std::ostream & operator<<(std::ostream & os, Sorcerer & sorcerer);

#endif
