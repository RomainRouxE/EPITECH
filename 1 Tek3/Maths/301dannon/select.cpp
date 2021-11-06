//
// EPITECH PROJECT, 2018
// select.cpp
// File description:
// select.cpp
//

#include "301dannon.hpp"

int select(std::vector<double> list)
{
	int n = 0;
	int tmp;
	for (int i = 0; i < list.size() - 1; i++) {
		for (int j = i + 1; j < list.size() - 1; j++) {
			n++;
			if (list[i] > list[j]) {
				n++;
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
	return (n);
}
			    
