//
// EPITECH PROJECT, 2018
// FruitBox.hpp
// File description:
// FruitBox.hpp
//

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
private:
	int _size;
	int _nb;
	FruitNode *list;
	
public:
	FruitBox(int size);
	~FruitBox();
	int nbFruits() const;
	bool putFruit(Fruit *f);
	Fruit *pickFruit();
	FruitNode *head() const;
};

#endif
