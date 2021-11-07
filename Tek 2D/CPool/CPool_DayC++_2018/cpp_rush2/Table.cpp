//
// EPITECH PROJECT, 2018
// Table.cpp
// File description:
// Function of Table
//

#include <iostream>
#include <string>
#include "Table.hpp"
#include "Object.hpp"
#include "Toy.hpp"

ITable::ITable()
{
	_nbObject = 0;
}

ITable::~ITable()
{
}

int ITable::getObject() const
{
	return _nbObject;
}

void ITable::lookObject()
{
	std::cout << "\n";
}

void ITable::addObject(Object *gift)
{
	if ((++_nbObject) <= 10) {
		_gift[_nbObject] = *gift;
		++_nbObject;
	}
}

void ITable::moveObject()
{
	if ((_nbObject - 1) >= 0) {
		--_nbObject;
	}
}
