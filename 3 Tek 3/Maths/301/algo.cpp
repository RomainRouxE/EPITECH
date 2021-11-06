//
// EPITECH PROJECT,
// algo.cpp
// File description:
// algo.cpp
//

#include "301dannon.hpp"

static void error()
{
	cerr << "Empty file or not only number" << endl;
	exit(84);
}

bool is_num(string& s)
{
	int i = 0;
	int a = 0;
	string::const_iterator num = s.begin();

	while (num != s.end()) {
		if (isdigit(*num) || *num == '.' || *num == '-') {
			if (*num == '.')
				i++;
			if (*num == '-')
				a++;
		}
		else
			error();
		if (i > 1 || a > 1)
			error();
		num++;
	}
	return (true);
}

vector<float> number(char **av)
{
	vector<string>::iterator it;
	vector<string> nbs;
	vector<float> tab;
	ifstream file;
	string line;
	string save;
	string nb;

	file.open(av[1]);
	getline(file, line);
	file.close();

	stringstream ss(line);
	const char *fnb;
	
	while (getline(ss, nb, ' ')) {
		if ((nb.compare("")) != 0)
			nbs.push_back(nb);
	}
	for (it = nbs.begin(); it != nbs.end(); it++) {
		save = *it;
		fnb = save.c_str();
		if (is_num(save) == true)
			tab.push_back((float)atof(fnb));
	}
	return (tab);
}

void algo(char **av)
{
	vector<float> list;

	list = number(av);
	if (list.size() <= 0)
		error();

	if (list.size() == 1)
		cout << list.size() << " element" << endl;
	else
		cout << list.size() << " elements" << endl;

	 int a = select(list);
	 cout << "Selection sort: " << a;
	 if (a > 1)
		 cout << " comparisons" << endl;
	 else
		 cout << " comparison" << endl;

	 a = insertion(list);
	 cout << "Insertion sort: " << a;
         if (a > 1)
                 cout << " comparisons" << endl;
         else
                 cout << " comparison" << endl;

	 a = bubble(list);
         cout << "Bubble sort: " << a;
         if (a > 1)
                 cout << " comparisons" << endl;
         else
                 cout << " comparison" << endl;

	 a = quicksort(list);
         cout << "Quicksort: " << a;
         if (a > 1)
                 cout << " comparisons" << endl;
         else
                 cout << " comparison" << endl;

	 a = merge(list);
         cout << "Merge sort: " << a;
         if (a > 1)
                 cout << " comparisons" << endl;
         else
		 cout << " comparison" << endl;
}
