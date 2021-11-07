//
// EPITECH PROJECT, 2018
// FruitNode.hpp
// File description:
// FruitNode.hpp
//

#ifndef FRUINODE_HPP_
#define FRUINODE_HPP_

#include "Fruit.hpp"

struct FruitNode
{
	Fruit *fruit;
	FruitNode *next;
};

#endif
