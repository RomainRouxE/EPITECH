#include "302separation.hpp"

vector<string> separation;

bool nameExist(string name)
{
        for (int i = 0; i < separation.size(); i++)
                if (separation[i] == name)
                        return (true);
        return (false);
}

bool islink(string link, string end)
{
	for(int n = 0; n < separation.size(); n = n + 3)
		if (separation[n] == link && separation[n+1] == end || separation[n] == end && separation[n+1] == link)
			return true;
	return false;
}

string getlink(string glink, int i)
{
	if (separation[i] == glink) {
		return (separation[i+1]);
	}
	else if (separation[i+1] == glink)
		return (separation[i]);
	else
		return ("NULL");
}

int algo(char **av)
{
	string start = av[2];
	string end  = av[3];
	string link1,  link2, link3, link4, link5;
	int x = 0;
	int path = -1;

	for(int x = 1; path == -1 && x < 7; x++) {
		if (x == 1)
			if (islink(start, end))
				path = x;
		if (x == 2) {
			for(int i = 0; i < separation.size() && path == -1; i = i + 3) {
				link1 = getlink(start, i);
				if (link1 != "NULL")
					if (islink(link1, end))
						path = x;
			}
		}
		if (x == 3) {
			for(int i = 0; i < separation.size() && path == -1; i = i + 3) {
				link1 = getlink(start, i);
				for(int j = 0; j < separation.size() && path == -1; j = j + 3) {
					link2 = getlink(link1, j);
					if (link1 != "NULL")
						if (islink(link2, end))
							path = x;
				}
			}
		}
		if (x == 4) {
			for(int i = 0; i < separation.size() && path == -1; i = i + 3) {
				link1 = getlink(start, i);
				for(int j = 0; j < separation.size() && path == -1; j = j + 3) {
					link2 = getlink(link1, j);
					for(int k = 0; k < separation.size() && path == -1; k = k + 3) {
						link3 = getlink(link2, k);
						if (link1 != "NULL")
							if (islink(link3, end))
								path = x;
					}
				}
			}
		}
		if (x == 5) {
			for(int i = 0; i < separation.size() && path == -1; i = i + 3) {
				link1 = getlink(start, i);
				for(int j = 0; j < separation.size() && path == -1; j = j + 3) {
					link2 = getlink(link1, j);
					for(int k = 0; k < separation.size() && path == -1; k = k + 3) {
						link3 = getlink(link2, k);
						for(int l = 0; l < separation.size() && path == -1; l = l + 3) {
							link4 = getlink(link3, l);
							if (link1 != "NULL")
								if (islink(link4, end))
									path = x;
						}
					}
				}
			}
		}
		if (x == 6) {
			for(int i = 0; i < separation.size() && path == -1; i = i + 3) {
				link1 = getlink(start, i);
				for(int j = 0; j < separation.size() && path == -1; j = j + 3) {
					link2 = getlink(link1, j);
					for(int k = 0; k < separation.size() && path == -1; k = k + 3) {
						link3 = getlink(link2, k);
						for(int l = 0; l < separation.size() && path == -1; l = l + 3) {
							link4 = getlink(link3, l);
							for(int m = 0; m < separation.size() && path == -1; m = m + 3) {
								link5 = getlink(link4, m);
								if (link1 != "NULL")
									if (islink(link5, end))
										path = x;
							}
						}
					}
				}
			}
		}
	}

	cout << "Degree of separation between " << av[2] << " and " << av[3] << ": " << path << endl;
}

void sseparation(char **av)
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
                                separation.push_back(name);
                                line.erase(0, pos + delimiter.length());
                        }
                        separation.push_back(line);
			separation.push_back(" ");
                }
        }
//      for (int i =0; i < separation.size(); i++) 
//              cout << separation[i] << endl;

	if (!strcmp(av[2], av[3])) {
		cout << "Degree of separation between " << av[2] << " and " << av[3] << ": 0" << endl;
		exit (0);
	}
	if (!nameExist(av[2]) || !nameExist(av[3])) {
		cout << "Degree of separation between " << av[2] << " and " << av[3] << ": -1" << endl;
		exit (0);
	}
	algo(av);
}
