#include "302separation.hpp"

vector<string> names;
vector<string> all;

bool nameexist(string name)
{
	for (int i = 0; i < names.size(); i++)
		if (names[i] == name)
			return (true);
	return (false);
}

bool islinkM(string link, string end)
{
	for(int n = 0; n < all.size(); n = n + 3)
		if (all[n] == link && all[n+1] == end || all[n] == end && all[n+1] == link)
			return true;
	return false;
}

string getlinkM(string glink, int i)
{
	if (all[i] == glink) {
		return (all[i+1]);
	}
	else if (all[i+1] == glink)
		return (all[i]);
	else
		return ("NULL");
}

int algo(string start, string end, int max)
{
	string link1,  link2, link3, link4, link5;
	int x = 0;
	int path = -1;

	if (start == end)
		path = 0;
	for(int x = 1; path == -1 && x <= max; x++) {
		if (x == 1)
			if (islinkM(start, end))
				path = x;
		if (x == 2) {
			for(int i = 0; i < all.size() && path == -1; i = i + 3) {
				link1 = getlinkM(start, i);
				if (link1 != "NULL")
					if (islinkM(link1, end))
						path = x;
			}
		}
		if (x == 3) {
			for(int i = 0; i < all.size() && path == -1; i = i + 3) {
				link1 = getlinkM(start, i);
				for(int j = 0; j < all.size() && path == -1; j = j + 3) {
					link2 = getlinkM(link1, j);
					if (link1 != "NULL")
						if (islinkM(link2, end))
							path = x;
				}
			}
		}
		if (x == 4) {
			for(int i = 0; i < all.size() && path == -1; i = i + 3) {
				link1 = getlinkM(start, i);
				for(int j = 0; j < all.size() && path == -1; j = j + 3) {
					link2 = getlinkM(link1, j);
					for(int k = 0; k < all.size() && path == -1; k = k + 3) {
						link3 = getlinkM(link2, k);
						if (link1 != "NULL")
							if (islinkM(link3, end))
								path = x;
					}
				}
			}
		}
		if (x == 5) {
			for(int i = 0; i < all.size() && path == -1; i = i + 3) {
				link1 = getlinkM(start, i);
				for(int j = 0; j < all.size() && path == -1; j = j + 3) {
					link2 = getlinkM(link1, j);
					for(int k = 0; k < all.size() && path == -1; k = k + 3) {
						link3 = getlinkM(link2, k);
						for(int l = 0; l < all.size() && path == -1; l = l + 3) {
							link4 = getlinkM(link3, l);
							if (link1 != "NULL")
								if (islinkM(link4, end))
									path = x;
						}
					}
				}
			}
		}
		if (x == 6) {
			for(int i = 0; i < all.size() && path == -1; i = i + 3) {
				link1 = getlinkM(start, i);
				for(int j = 0; j < all.size() && path == -1; j = j + 3) {
					link2 = getlinkM(link1, j);
					for(int k = 0; k < all.size() && path == -1; k = k + 3) {
						link3 = getlinkM(link2, k);
						for(int l = 0; l < all.size() && path == -1; l = l + 3) {
							link4 = getlinkM(link3, l);
							for(int m = 0; m < all.size() && path == -1; m = m + 3) {
								link5 = getlinkM(link4, m);
								if (link1 != "NULL")
									if (islinkM(link5, end))
										path = x;
							}
						}
					}
				}
			}
		}
	}
	if (path == -1)
		path = 0;
	return (path);
}

void matrix(char **av)
{
	ifstream file(av[1]);
	string line;
	string delimiter(" is friends with ");

	while (getline(file, line)) {
		if (line.find(delimiter) != string::npos) {
			size_t pos = 0;
			string name;
			while ((pos = line.find(delimiter)) != string::npos) {
				name = line.substr(0, pos);
				if (!nameexist(name)) {
					names.push_back(name);
				}
				all.push_back(name);
				line.erase(0, pos + delimiter.length());
			}
			if (!nameexist(line))
				names.push_back(line);
			all.push_back(line);
			all.push_back(" ");
		}	
	}
//	for (int i = 0; i < names.size(); i++)
//		cout << names[i] << endl;
//	for (int i =0; i < all.size(); i++)
//		cout << all[i] << endl;

	sort(names.begin(), names.end());
	for (int i = 0; i < names.size(); i++)
		cout << names[i] << endl;

	cout << endl;
	int x = names.size();
	int matrice[x][x];
	int max = atoi(av[2]);

	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++)
			matrice[i][j] = algo(names[i], names[j], max);
	for (int i = 0; i < names.size(); i++)
		for (int j = 0; j < names.size(); j++) {
			if (islinkM(names[i], names[j]))
				cout << "1";
			else
				cout << "0";
			if (j != x - 1)
				cout << " ";
			else
				cout << endl;
		}
	cout << endl;

	for (int i = 0; i < names.size(); i++)
                for (int j = 0; j < names.size(); j++) {
			cout << matrice[i][j];
                        if (j != x - 1)
                                cout << " ";
			else
                                cout << endl;
		}
	
}
