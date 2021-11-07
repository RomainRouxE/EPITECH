//
// EPITECH PROJECT, 2018
// LittleHand.hpp
// File description:
// LittleHand.hpp
//

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include <iostream>
#include <string>
#include "Lemon.hpp"
#include "Banana.hpp"
#include "FruitBox.hpp"
#include "Lime.hpp"

class LittleHand
{
public:
	LittleHand();
	~LittleHand();
	static void sortFruitBox(FruitBox &unsorted,
				 FruitBox &lemons,
				 FruitBox &bananas,
				 FruitBox &limes);
};

#endif
