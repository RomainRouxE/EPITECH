//
// EPITECH PROJECT, 2018
// bubble.cpp
// File description:
// bubble.cpp
//

#include "301dannon.hpp"

int bubble(std::vector<double> list)
{
	int n = 0;
	int tmp;

	for (int i = 0; i < list.size() - 1; i++) {
		for (int j = 0; j < list.size() - i; j++) {
			n++;
			if (list[j] > list[j + 1]) {
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
	return (n);
}
