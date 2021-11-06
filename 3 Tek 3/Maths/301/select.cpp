//
// EPITECH PROJECT,
// select.cpp
// File description:
// select.cpp
//

#include "301dannon.hpp"

int select(vector<float> list)
{
	int n = list.size();
	float min, save;
	int count = 0;
	int x;

	for (int i = 0; i < n - 1; i++) {
		min = list[i];
		count++;
		for (int j = i + 1; j < n - 1; j++) {
			if (list[j] < min) {
				min = list[j];
				x = j;
			}
			count++;
		}
		if (min != list[i]) {
			save = list[i];
			list[i] = min;
			list[x] = save;
		}
	}
	return (count);
}
