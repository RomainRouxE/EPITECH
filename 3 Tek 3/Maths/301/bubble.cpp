//
// EPITECH PROJECT,
// bubble.cpp
// File description:
// bubble.cpp
//

#include "301dannon.hpp"

int bubble(vector<float> list)
{
	int n = list.size();
	float save;
	int count = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			count++;
			if (list[j] > list[j + 1]) {
				save = list[j];
				list[j] = list[j + 1];
				list[j + 1] = save;
			}
		}
	}
	return (count);
}
