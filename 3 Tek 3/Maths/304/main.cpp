//
// EPITECH PROJECT,
// main.cpp
// File description:
// main.cpp
//

#include "304pacman.hpp"

static void error()
{
	cerr << "Error" << endl;
	exit(84);
}

static void usage(char **av)
{
	cout << "file    file describing the board, using the following characters:" << endl;
	cout << "\t   ‘0’ for an empty square,"<< endl;
	cout << "\t   ‘1’ for a wall," << endl;
	cout << "\t   ‘F’ for the ghost’s position," << endl;
	cout << "\t   ‘P’ for Pacman’s position." << endl;
	cout << "c1      character to display for a wall" << endl;
	cout << "c2      character to display for an empty space." << endl;
	exit(0);
}

char intochar(int link)
{
	stringstream strs;
	strs << link;
	string temp_str = strs.str();
	char* char_type = (char*) temp_str.c_str();
	return (*char_type);
}

int main(int ac, char **av)
{
	if (ac == NULL)
		error();
	if (ac == 2 && string("-h") == av[1])
		usage(av);

	if (ac != 4 || strlen(av[2]) != 1 || strlen(av[3]) != 1 || av[2] == av[3])
		error();

	char mychar;
	int x = 0;
	int y = 0;
	int size, size2;
	ifstream ifs;
	ifs.open (av[1]);
	if (!ifs)
		error();
	else {
		while (!ifs.eof()) {
			ifs.get(mychar);
			x++;
			if (mychar == '\n'){
				x = 0;
				y++;
			}
		}
        }
	ifs.close();

	char tab[y+1][x];
	int exist = 0;
	size = x;
	size2 = y+1;
	x = 0;
	y = 0;

	ifs.open (av[1]);
	while (!ifs.eof()) {
		ifs.get(mychar);
		if (mychar == '\n'){
			if (x != size - 1)
				error();
			y++;
			x = 0;
		}
		else {
			if (mychar != '1' && mychar != '0' && mychar != 'P' && mychar != 'F')
				error();
			if (mychar == 'F' || mychar == 'P')
				exist++;
			if (mychar ==  '1')
				tab[y][x] = *av[2];
			else if (mychar == '0')
				tab[y][x] = *av[3];
			else
				tab[y][x] = mychar;
			x++;
		}
	}

	if (exist != 2)
		error();

	int found = 0;
	int link = 1;
	char c;
	while (found == 0) {
		for (x = size - 2; x >= 0; x--) {
			for (y = 0; y < size2; y++) {
				if (link == 1 && tab[y][x] == 'F') {
					if (tab[y-1][x] == 'P')
						break;
					else if (tab[y-1][x] == *av[3]) {
						c = intochar(link);
						tab[y-1][x] = c;
					}
					if (tab[y][x+1] == 'P')
                                                break;
                                        else if (tab[y][x+1] == *av[3]) {
						c = intochar(link);
                                                tab[y][x+1] = c;
					}
					if (tab[y+1][x] == 'P')
                                                break;
                                        else if (tab[y+1][x] == *av[3]) {
						c = intochar(link);
                                                tab[y+1][x] = c;
					}
					if (tab[y][x-1] == 'P')
                                                break;
                                        else if (tab[y][x-1] == *av[3]) {
						c = intochar(link);
                                                tab[y][x-1] = c;
					}
				}

				if (tab[y][x] != *av[2] && tab[y][x] != *av[3] && tab[y][x] != 'F' && tab[y][x] != 'P' && (int)tab[y][x]-48 < link && found == 0) {
					if (tab[y-1][x] == 'P')
						found = 1;
					else if (tab[y-1][x] == *av[3]) {
						c = intochar(link%10);
						tab[y-1][x] = c;
					}
					if (tab[y][x+1] == 'P')
						found = 1;
					else if (tab[y][x+1] == *av[3] && found == 0) {
						c = intochar(link%10);
						tab[y][x+1] = c;
					}					
					if (tab[y+1][x] == 'P')
                                                found = 1;
                                        else if (tab[y+1][x] == *av[3] && found == 0) {
						c = intochar(link%10);
                                                tab[y+1][x] = c;
					}
                                        if (tab[y][x-1] == 'P')
                                                found = 1;
                                        else if (tab[y][x-1] == *av[3] && found == 0) {
						c = intochar(link%10);
                                                tab[y][x-1] = c;
					}
				}
			}
		}
		link++;
		if (link > 20)
			break;
	}

	for (y = 0; y < size2; y++)
		for (x = 0; x < size - 1; x++) {
			cout << tab[y][x];
			if (x == size-2)
				cout << endl;
		}

}
