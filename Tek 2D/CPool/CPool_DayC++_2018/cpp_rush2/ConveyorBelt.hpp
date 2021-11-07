//
// EPITECH PROJECT, 2018
// ConveyorBelt.hpp
// File description:
// ConveyorBelt header
//

#ifndef CONVEYORBELT_H_
#define CONVEYORBELT_H_

#include <iostream>

class ConveyorBelt
{
protected:
	std::string _button;
public:
	ConveyorBelt();
	~ConveyorBelt();
	std::string getButton() const;
};

#endif /* CONVEYORBELT_H_ */
