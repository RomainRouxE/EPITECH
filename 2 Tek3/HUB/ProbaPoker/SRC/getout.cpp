#include "../INC/getout.hpp"

#define RED     "\033[31m"
#define RESET   "\033[0m"


//Finf if there is any square / brelan possible else just a simple pair

int getpair(string carte[8], int x, int a)
{
	int y = 1;
	int z = 1;
	int same = 0;
	int proba;
	int probat = 0;

	while (y <= 2) {
		while (z <= x) {
			if (carte[y] == carte[z])
				same++;
			z++;
		}

		if (same == 3) {
			proba = 100 / (52 - x) * (7 - x);
			cout << endl;
			cout << "Tout les " << carte[y] << " manquants ameliorent votre main et forme un carre" << endl;
			cout << "Vous avez " << proba << "% de chance d'ameliorer votre main" << endl;
			probat = probat + 1;
		}
		if (same == 2) {
			proba = 2 * 100 / (52 - x) * (7 - x);
			cout << endl;
			cout << "Tout les " << carte[y] << " manquants ameliorent votre main et forme un brelan" << endl;
			cout << "Vous avez " << proba << "% de chance d'ameliorer votre main" << endl;
			probat = probat	+ 2;
		}
		if (same == 1 && a != 3) {
			proba = 3 * 100 / (52 - x) * (7 - x);
			cout << endl;
			cout << "Tout les " << carte[y] << " manquants ameliorent votre main et forme une paire" << endl;
			cout << "Vous avez " << proba << "% de chance d'ameliorer votre main" << endl;
			probat = probat	+ 3;
		}
		z = 2;
		same = 0;
		y++;
		if (carte[1] == carte[2])
			return (2);
	}
	return (probat);
}


//find if there is any full or double pair possible

int getdouble(string carte[7], int x)
{
	int z = 3;
	int same1 = 1;
	int same2 = 1;
	int proba;
	int probat = 0;

	while (z <= x) {
		if (carte[1] == carte[z])
			same1++;
		if (carte[2] == carte[z])
			same2++;
		z++;
	}

	if (same1 == 2 && same2 == 2) {
		proba = 4 * 100 / (52 - x) * (7 - x);
		cout << endl;
		cout << "Tout les " << carte[1] << " et " << carte[2] << " manquants ameliorent votre main et forme un full" << endl;
		cout << "Vous avez " << proba << "% de chance d'ameliorer votre main" << endl;
		return (4);
	}
	if (same1 == 2 && same2 == 1) {
		proba = 3 * 100 / (52 - x) * (7 - x);
		cout << endl;
		cout << "Tout les " << carte[2] << " manquants ameliorent votre main et forme une double pair" << endl;
		cout << "Vous avez " << proba << "% de chance d'ameliorer votre main" << endl;
		return (3);
	}
	if (same1 == 1 && same2 == 2) {
		proba = 3 * 100 / (52 - x) * (7 - x);
		cout << endl;
		cout << "Tout les " << carte[1] << " manquants ameliorent votre main et forme une double pair" << endl;
		cout << "Vous avez " << proba << "% de chance d'ameliorer votre main" << endl;
		return (3);
	}
	return (0);
}


//Find if there is any straight possible

int isstraight(string carte[7], int x)
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


	while (nb1 <= x) {
		while (z <= 10) {
			straight = 0;
			m = z;
			if (carte[nb1] == compare[m]) {
				straight = 1;
				m++;
				while (nb2 <= x)  {
					if (carte[nb2] == compare[m]) {
						if (carte[nb2] == "A")
							save = 1;
						straight++;
						nb2 = 1;
						m++;
					}
					else
						nb2++;
				}

				if (straight >= 4 && save != 1) {
					cout << endl;
					cout << "Suite possible, les 4 cartes inferieurs ainsi que les 4 carte superieurs ameliorent votre main" << endl;
					return (8);
				}
				if (straight >= 4 && save == 1) {
					cout << endl;
					cout << "Suite possible, seulement 4 cartes permettent la suite." << endl;
					return (4);
				}
				save = 0;
				nb2 = 0;
			}
			z++;
		}
		z = 0;
		nb1++;
	}
	return (0);
}


// Find if there is any flush possible

int isflush(string c[7], int x)
{
	int y = 1;
	int z = 1;
	int flush = 0;
	int proba;

	while (y <= 2) {
		while (z <= x) {
                        if (c[y] == c[z])
                                flush++;
                        z++;
		}
		
		if (flush == 4) {
			proba = 9 * 100 / (52 - x) * (7 - x);
			cout << endl;
			cout << "Tout les " << c[y] << " manquants ameliorent votre main et forme un flush" << endl;
			cout << "Vous avez " << proba << "% de chance d'ameliorer votre main" << endl;
			return (9);
		}
		z = 2;
		flush = 0;
		y++;
	}
	return (0);
}


//Getout main function

int getout(string tab[7], int x)
{
	string carte[8];
	string c[8];

	//use a to block pair if double pair possible
	int a = 0;
	
	//y = number card probat = proba total
	int y;
	int probat = 0;

	//Preflop

	if (x == 1) {
		//Separate value from color, only keep value for preflop since color doesn t change anything
		carte[1] = tab[0].substr(0, tab[0].size()-1);
		carte[2] = tab[1].substr(0, tab[1].size()-1);

		//Paire - brelan - carre
		probat = getpair(carte, 2, a);
		y = 2;
	}

	//Flop

	if (x == 2) {
		//Separate value and color of the cards
		c[1] = tab[0].back();
		c[2] = tab[1].back();
		c[3] = tab[2].back();
		c[4] = tab[3].back();
		c[5] = tab[4].back();
		carte[1] = tab[0].substr(0, tab[0].size()-1);
		carte[2] = tab[1].substr(0, tab[1].size()-1);
		carte[3] = tab[2].substr(0, tab[2].size()-1);
		carte[4] = tab[3].substr(0, tab[3].size()-1);
		carte[5] = tab[4].substr(0, tab[4].size()-1);

		//Couleur
		probat = isflush(c, 5);

		//Straight
		probat = probat + isstraight(carte, 5);

		//double pair - full
		if (carte[1] != carte[2]) {
			a = getdouble(carte, 5);
			probat = probat + a;
		}

		//Paire - brelan - carre
		probat = probat + getpair(carte, 5, a);

		y = 5;
	}

	//Turn

	if (x == 3) {
		//Separate value and color of the cards
		c[1] = tab[0].back();
		c[2] = tab[1].back();
		c[3] = tab[2].back();
		c[4] = tab[3].back();
		c[5] = tab[4].back();
		c[6] = tab[5].back();
		carte[1] = tab[0].substr(0, tab[0].size()-1);
		carte[2] = tab[1].substr(0, tab[1].size()-1);
		carte[3] = tab[2].substr(0, tab[2].size()-1);
		carte[4] = tab[3].substr(0, tab[3].size()-1);
		carte[5] = tab[4].substr(0, tab[4].size()-1);
		carte[6] = tab[5].substr(0, tab[5].size()-1);

		//Flush
		probat = isflush(c, 6);

		//straight
		probat = probat + isstraight(carte, 6);

		//double pair - full
		if (carte[1] != carte[2]) {
			a = getdouble(carte, 6);
			probat = probat + a;
		}

		//Paire - brelan - carre
		probat = probat +getpair(carte, 6, a);

		y = 6;
	}

	//print proba total
	probat = probat * 100 / (52 - y) * (7 - y) - 5;
	cout << endl;
	cout << RED << "Proba totale d'amelioration : " << probat << "%" << RESET << endl;
}
