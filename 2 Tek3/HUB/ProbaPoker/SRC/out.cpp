#include "../INC/out.hpp"


//check etape ( return à if error else 1/2/3 depanding of the etape

int CheckEtape(string coup)
{
	if (coup == "River") {
		cout << endl;
		cout << "Aucune carte en plus a venir... Impossible d ameliorer votre main !" << endl;
		cout << endl;
		return (0);
	}

	if (coup != "Preflop" && coup != "Flop" && coup != "Turn") {
		cout << endl;
		cout << "Etape de la main non valide, entrez Preflop / Flop / Turn" << endl;
		cout << endl;
		return (0);
	}
	if (coup == "Preflop")
		return (1);
	if (coup == "Flop")
		return (2);
	if (coup == "Turn")
		return (3);
}


//Check if card = valid - return 0 if not valid else 1

int CheckCard(string c)
{
	ifstream fichier("./TXT/carte.txt");
	string mot;

	while(fichier >> mot) {
		if (c == mot)
			return (1);
	}
	cout << endl;
	cout << "Carte non valide entrez une autre." << endl;
	cout << endl;
	return (0);
}


//Get card until card is correct

std::string getcard()
{
	int x = 0;
	string c;
	
	while (x == 0) {
		getline(cin, c);
		x = CheckCard(c);
	}
	return (c);
}


//Check if every card are different - return 0 if 2 card are similar, return 0 if its ok

int carddif(string tab[7], int x)
{
	int a = 0;
	int y;
	
	while(a < x + 3) {
		y = a + 1;
		while (y <= x + 3) {
			if (tab[a] == tab[y])
				return (0);
			y++;
		}
		a++;
	}
	return (1);
}


//Out main function

int Out()
{
	int x = 0;
	int aredif = 0;
	string c = "OUI";
	string coup;
	string tab[7];

	while (c == "OUI" || c == "o") {
		cout << "Entrez votre main du type :" << endl;
		cout << "Kh" << endl;
                cout << "6d" << endl;
		cout << endl << "c -> CLUB - d -> DIAMAND - h -> HEART - s -> SPADE" << endl;
		cout << endl;

		//Get the 2 player card
		while (x == 0) {
			tab[0] = getcard();
			tab[1] = getcard();
			if (tab[0] != tab[1])
				x = 1;
		}

		x = 0;

		//Get etape
		cout << endl;
		cout << "Entrez a quelle etape du coup vous vous situez :" << endl;
		cout << "\t-Preflop" << endl;
		cout << "\t-Flop" << endl;
		cout << "\t-Turn" << endl;
		cout << endl;

		while (x == 0) {
			getline(cin, coup);
			x = CheckEtape(coup);
		}

		//Get board card until they are correct
		while (aredif == 0) {
			if (x == 1) {
				cout << endl << "Preflop :" << endl;
				cout << endl;
				aredif = 1;
			}

			if (x == 2) {
				cout << "Flop, entrez les 3 cartes du flop :" << endl;
				cout << endl;
				tab[2] = getcard();
				tab[3] = getcard();
				tab[4] = getcard();
				aredif = carddif(tab, x);
				if (aredif == 0)
					cout << "Vous avez rentrez des cartes identiques--> impossible." << endl;
			}

			if (x == 3) {
				cout << "Turn, entrez les 4 cartes du Turn :" << endl;
				cout << endl;
				tab[2] = getcard();
				tab[3] = getcard();
				tab[4] = getcard();
				tab[5] = getcard();
				aredif = carddif(tab, x);
				if (aredif == 0)
					cout << "Vous avez rentrez des cartes identiques --> impossible." << endl;
			}
		}

		//Calcul possible out
		getout(tab, x);

		cout << endl;
		cout << "Voulez vous recalculer les out ameliorant votre main ?" << endl;
		cout << "OUI pour recalculer" << endl;
		cout << "NON pour retourner au menu" << endl;
		cout << "QUIT pour fermer l app" << endl;
		cout << endl;
		getline(cin, c);
		x = 0;
		aredif = 0;
	}
	if (c == "QUIT" || c == "q")
		exit(0);
}


//Call vs function if mode selected

int getvs()
{
	int x = 0;
	int aredif = 0;
	string c = "OUI";
	string coup;
	string tab[7];

	while (c == "OUI" || c == "o") {
		cout << "Entrez votre main du type :" << endl;
		cout << "Kh" << endl;
		cout << "6d" << endl;
		cout << endl;
		cout << "c -> CLUB - d -> DIAMAND - h -> HEART - s -> SPADE" << endl;
		cout << endl;

		while (x == 0) {
                        tab[0] = getcard();
                        tab[1] = getcard();
                        if (tab[0] != tab[1])
                                x = 1;
                }

                x = 0;

		while (aredif == 0) {
			cout << endl;
			cout << "Entrez les 5 cartes du board :" << endl;
			cout << endl;
			tab[2] = getcard();
			tab[3] = getcard();
			tab[4] = getcard();
			tab[5] = getcard();
			tab[6] = getcard();
			aredif = carddif(tab, x);
			if (aredif == 0)
				cout << "Vous avez rentrez des cartes identiques --> impossible." << endl;
		}

		vs(tab, x);

		cout << "Voulez vous recalculer les out ameliorant votre main ?" << endl;
		cout << "OUI pour recalculer" << endl;
		cout << "NON pour retourner au menu" << endl;
		cout << "QUIT pour fermer l app" << endl;
		cout << endl;
		getline(cin, c);
		x = 0;
		aredif = 0;
	}
        if (c == "QUIT" || c == "q")
		exit(0);
}
