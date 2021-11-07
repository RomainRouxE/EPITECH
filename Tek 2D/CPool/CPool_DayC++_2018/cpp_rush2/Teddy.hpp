//
// EPITECH PROJECT, 2018
// Teddy header
// File description:
// 
//

#ifndef TEDDY_H_
#define TEDDY_H_

#include <string>
#include "Toy.hpp"

class Teddy : public Toy
{
protected:

public:
	Teddy(std::string title);
	virtual ~Teddy();
	virtual void isTaken();
};

#endif /* TEDDY_H_ */
