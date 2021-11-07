//
// EPITECH PROJECT, 2018
// Lime.hpp
// File description:
// Lime.hpp
//

#ifndef LIME_HPP_
#define LIME_HPP_

#include <iostream>
#include <string>
#include "Lemon.hpp"

class Lime : public Lemon
{
public:
	Lime();
	~Lime();
	int getVitamins() const;
	std::string getName() const;
};

#endif
