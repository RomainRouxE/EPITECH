//
// EPITECH PROJECT, 2018
// insert.cpp
// File description:
// insert.cpp
//

#include "301dannon.hpp"

int insert(std::vector<double> list)
{
	int n = 0;
	int key;
	for (int i = 0; i < list.size() - 1; i++) {
		key = list[i];
		int j = i;

		while (j >= 1 && list[j] > key) {
			list[j+1] = list[j];
			j = j-1;
		}
		list[j+1] = key;
		n++;
	}
	return (n);
}
