//
// EPITECH PROJECT, 2018
// Toy.hpp
// File description:
// Class toy header
//

#ifndef TOY_H_
#define TOY_H_

#include"Object.hpp"

class Toy : public Object
{
protected:
	std::string title;
public:
	Toy();
	virtual ~Toy();

	void isTaken();
};

#endif /* TOY_H_ */
