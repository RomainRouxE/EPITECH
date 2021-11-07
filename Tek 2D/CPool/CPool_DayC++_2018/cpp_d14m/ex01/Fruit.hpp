//
// EPITECH PROJECT, 2018
// Fruit.hpp
// File description:
// Fruit.hpp
//

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>
#include <string>

class Fruit
{
protected:
	int _vitamins;
	std::string _name;
	
public:
	Fruit();
	virtual ~Fruit();
	virtual int getVitamins() const;
	virtual std::string getName() const = 0;
};

#endif
