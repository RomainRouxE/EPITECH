//
// EPITECH PROJECT,
// insert.cpp
// File description:
// insert.cpp
//

#include "301dannon.hpp"

int insertion(vector<float> list)
{
	int n = list.size();
	float save;
	int count = 0;
	int j;
	int x = 1;

	for (int i = 1; i < n; i++) {
		save = list[i];
		count++;
		if (list[i] < list[i - 1]) {
			for (int j = i; j > 0; j--) {
				list[j] = list[j - 1];
			}
			while (save > list[x]) {
//				cout << list[save]<< "&&" << list[x] << "&&" << x << endl;
				list[x - 1] = list[x];
				count++;
				x++;
			}
			count++;
			list[x - 1] = save;
			x = 1;
		}
/*		for (int z = 0; z < n; z++)
                                cout << list[z] << " ";
                        cout << endl;
                        cout << count << endl;*/
	}
	return (count);
}
