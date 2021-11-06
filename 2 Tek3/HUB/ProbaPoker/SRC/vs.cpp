#include "../INC/vs.hpp"

#define RED     "\033[31m"
#define RESET   "\033[0m"


//Check if square

int square(string carte[8])
{
	int y = 1;
	int z = 1;
	int same = 0;

	while (y <= 2) {
		while (z <= 8) {
			if (carte[y] == carte[z])
				same++;
			z++;
		}

		if (same == 4) {
			cout << endl;
			cout << RED << "Vous avez un carre," << RESET << endl;
			cout << endl;
			cout << "Seulement un carre plus eleve ou une quinte-flush vous bat." << endl;
			cout << endl;
			return (1);
		}
		z = 2;
		same = 0;
		y++;
	}
	return (0);
}


//Check if full

int full(string carte[8])
{
	int z = 1;
	int y = 1;
	int save1;
	int save2;
	int same1 = 0;
	int same2 = 0;

	while (y <= 6) {
		while (z <= 8) {
			if (carte[y] == carte[z]) {
				save1 = y;
				same1++;
			}
			z++;
		}
		if (same1 == 3) {
			break;
		}

		same1 = 0;
		z = 1;
		y++;
	}

	y = 1;
	z = 1;
	if (same1 == 3) {
		while (y <= 7) {
			while (z <= 8) {
				if (carte[y] == carte[z] && carte[y] != carte[save1]) {
					same2++;
					save2 = y;
				}
				z++;
			}
			if (same2 == 2)
				break;
			same2 = 0;
			z = 1;
			y++;
		}
	}

	if (same1 == 3 && same2 == 2) {
		cout << endl;
		cout << RED << "Vous avez un full, " << carte[save1] << " par les " << carte[save2] << RESET << endl;
		cout << endl;
		cout << "Seulement un full meilleur, un carre ou une quinte-flush vous bat" << endl;
		cout << endl;
		return (1);
	}
	return (0);
}


//Check if flush + flush hight

int flush(string c[8], string carte[8])
{
	int y = 1;
	int z = 1;
	int flush = 0;
	int save = 0;

	while (y <= 3) {
		while (z <= 8) {
			if (c[y] == c[z]) {
				flush++;
				if (carte[z] == "A")
					save = 1;
			}
			z++;
		}

		if (flush >= 5) {
			if (save == 1) {
				cout << endl;
				cout << RED << "Vous avez une couleur hauteur A" << RESET << endl;
				cout << endl;
				cout << "Vous avez la couleur la plus haute, seulement un full ou mieux vous bats" << endl;
				cout << endl;
				return (1);
			}
			else {
				cout << endl;
				cout << RED << "Vous avez une couleur pas max" << RESET << endl;
				cout << endl;
				cout << "Une couleur plus haute, un full ou mieux vous bat." << endl;
				cout << endl;
				return (1);
			}
		}
		save = 0;
		z = 2;
		flush = 0;
		y++;
	}
	return (0);
}


//Check if straight + straight hight

int straight(string carte[8])
{
	int nb1 = 1;
	int nb2 = 1;
	int z = 0;
	int straight,m;
	int save = 0;
	string compare[14];

	compare[0] = "A";
	compare[1] = "2";
	compare[2] = "3";
	compare[3] = "4";
	compare[4] = "5";
	compare[5] = "6";
	compare[6] = "7";
	compare[7] = "8";
	compare[8] = "9";
	compare[9] = "10";
	compare[10] = "J";
	compare[11] = "Q";
	compare[12] = "K";
	compare[13] = "A";

	while (nb1 <= 8) {
		while (z <= 10) {
			straight = 0;
			m = z;
			if (carte[nb1] == compare[m]) {
				straight = 1;
				m++;
				while (nb2 <= 8)  {
					if (carte[nb2] == compare[m]) {
						if (carte[nb2] == "A")
							save = 1;
						straight++;
						nb2 = 1;
						m++;
					}
					else
						nb2++;
					if (straight == 5)
						break;

				}

				if (straight == 5) {
					if (save == 1) {
						cout << endl;
						cout << RED << "Vous avez une suite max" << RESET << endl;
						cout << "Une couleur, un full ou mieux vous bats seulement" << endl;
						cout << endl;
						return (1);
					}
					else {
						cout << endl;
						cout << RED <<  "Vous avez une suite" << RESET << endl;
						cout << "Un suite superieur, une couleur, un full ou mieux vous bats seulement" << endl;
						cout << endl;
						return (1);
					}
				}
				nb2 = 0;
			}
			z++;
		}
		z = 0;
		nb1++;
	}
	return (0);
}


//Check if three of a kind + if served + three of a kind hight

int brelan(string carte[8])
{
	int z = 1;
	int y = 1;
	int save;
	int same1 = 0;

	while (y <= 6) {
		while (z <= 8) {
			if (carte[y] == carte[z]) {
				save = y;
				same1++;
			}
			z++;
		}
		if (same1 == 3) {
			break;
		}
		same1 = 0;
		z = 1;
		y++;
	}
	if (same1 == 3 && carte[1] != carte[save] && carte[2] != carte[save]) {
		cout << endl;
       		cout << RED << "Vous avez un brelan servit, n'importe quelle carte superieur a la votre, pair ou mieux vous bats" << RESET << endl;
		cout << endl;
	       	return (1);
	}
	else if (same1 == 3 && carte[1] == carte[save] || carte[2] == carte[save])
		if (carte[save] != "A") {
			cout << endl;
			cout << RED << "Vous avez un brelan de " << carte[save] << RESET << endl;
			cout << endl;
			cout << "Un brelan plus eleve, une suite, un couleur ou un full vous bat." << endl;
			cout << endl;
			return (1);
		}
		else {
			cout << endl;
			cout << RED << "Vous avez un brelan de " << carte[save] << RESET << endl;
			cout << endl;
			cout << "Un brelan meilleur kicker, une suite, un couleur ou mieux vous bat." << endl;
			cout << endl;
			return (1);
		}
	return (0);
}


//check if double pair

int doublep(string carte[8])
{
	int z = 1;
	int y = 1;
	int save1;
	int save2;
	int same1 = 0;
	int same2 = 0;

	while (y <= 7) {
		while (z <= 8) {
			if (carte[y] == carte[z]) {
				save1 = y;
				same1++;
			}
			z++;
		}
		if (same1 == 2) {
			break;
		}
		same1 = 0;
		z = 1;
		y++;
	}

	y = 1;
	z = 1;
	if (same1 == 2) {
		while (y <= 7) {
			while (z <= 8) {
				if (carte[y] == carte[z] && carte[y] != carte[save1]) {
					same2++;
					save2 = y;
				}
				z++;
			}
			if (same2 == 2)
				break;
			same2 = 0;
			z = 1;
			y++;
		}
	}

	if (same1 == 2 && same2 == 2) {
		cout << endl;
		cout << RED << "Vous avez 2 paires, " << carte[save1] << " et " << carte[save2] << RESET << endl;
		cout << endl;
		cout << "Une double paire plus haute, un brelan ou mieux vous bat" << endl;
		cout << endl;
		return (1);
	}
	return (0);
}



//Check if pair + pair hight

int paire(string carte[8])
{
	int z = 1;
	int y = 1;
	int save;
	int same1 = 0;

	while (y <= 6) {
		while (z <= 8) {
			if (carte[y] == carte[z]) {
				save = y;
				same1++;
			}
			z++;
		}
		if (same1 == 2) {
			break;
		}
		same1 = 0;
		z = 1;
		y++;
	}
	if (same1 == 2 && carte[1] != carte[save] && carte[2] != carte[save]) {
		cout << endl;
		cout << RED << "Vous avez une paire servit, n'importe quelle carte superieur a la votre, pair ou mieux vous bats" << RESET << endl;
		cout << endl;
		return (1);
	}
	else if (same1 == 2 && carte[1] == carte[save] || carte[2] == carte[save]) {
		if (carte[save] == "A") {
			cout << RED << "Vous avez une paire de " << carte[save] << RESET << endl;
			cout << endl;
			cout << "Une paire d as meilleur kicker, un brelan ou mieux vous bat." << endl;
			cout << endl;
			return (1);
		}
		else {
			cout << RED << "Vous avez une paire de " << carte[save] << RESET << endl;
			cout << endl;
			cout << "Une paire plus haute, un brelan ou mieux vous bat." << endl;
			cout << endl;
			return (1);
		}
	}
	return (0);
}


//Get hightest card

int hauteur(string carte[8])
{
	int x = 1;
	int y = 0;
	int save = 12;
	string compare[13];

	compare[0] = "A";
	compare[1] = "K";
	compare[2] = "Q";
	compare[3] = "J";
	compare[4] = "10";
	compare[5] = "9";
	compare[6] = "8";
	compare[7] = "7";
	compare[8] = "6";
	compare[9] = "5";
	compare[10] = "4";
	compare[11] = "3";
	compare[12] = "2";


	while (x <= 7) {
		while (y <= 12) {
			if (carte[x] == compare[y]) {
				if (save >= y) {
					save = y;
					break;
				}
			}
			y++;
		}
		y = 0;
		x++;
	}

	if (compare[save] == "A") {
		cout << endl;
		cout << RED << "Vous avez une hauteur A" << RESET << endl;
		cout << endl;
		cout << "Une paire, double paire ou mieux vous bats." << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << RED << "Vous avez une hauteur " << compare[save] << RESET << endl;
		cout << endl;
		cout << "Une carte plus haute, une paire ou mieux vous bats." << endl;
		cout << endl;
	}
}


//call function to get bet hand

int getourbest(string c[8], string carte[8])
{
	int x= 0;

	x = square(carte);
	if (x == 0)
		x = full(carte);
	if (x == 0)
		x = flush(c, carte);
	if (x == 0)
		x = straight(carte);
	if (x == 0)
		x = brelan(carte);
	if (x == 0)
		x = doublep(carte);
	if (x == 0)
		x = paire(carte);
	if (x == 0)
		hauteur(carte);
}


//separate card/color

int vs(string tab[7], int x)
{
	string carte[8];
	string c[8];

	c[1] = tab[0].back();
	c[2] = tab[1].back();
	c[3] = tab[2].back();
	c[4] = tab[3].back();
	c[5] = tab[4].back();
	c[6] = tab[5].back();
	c[7] = tab[6].back();
	carte[1] = tab[0].substr(0, tab[0].size()-1);
	carte[2] = tab[1].substr(0, tab[1].size()-1);
	carte[3] = tab[2].substr(0, tab[2].size()-1);
	carte[4] = tab[3].substr(0, tab[3].size()-1);
	carte[5] = tab[4].substr(0, tab[4].size()-1);
	carte[6] = tab[5].substr(0, tab[5].size()-1);
	carte[7] = tab[6].substr(0, tab[6].size()-1);

	getourbest(c, carte);

}
