#include "../INC/cote.hpp"

#define RED     "\033[31m"
#define RESET   "\033[0m"


//Check if value are > 0

int ispotok(int a)
{
	if (a > 0)
		return (1);
	else
		return (0);
}


int cote()
{
	int odd, prcent, x, y;
	int potok = 0;
	string c = "OUI";
	string mise, pot;

	while (c == "OUI" || c == "o") {

		potok = 0;
		while (potok == 0) {
			cout << "Entrez le pot au debut du tour :" << endl;
			cout << endl;
			getline(cin, pot);
			cout << endl;

			//String to int + if error x will be 0
			x = atoi(pot.c_str());
			potok = ispotok(x);
			if (potok == 0) {
				cout <<	"Valeur impossible, le pot doit etre positif" << endl;
				cout <<	endl;
			}
		}
		potok = 0;
		while (potok == 0) {
			cout << "Entrez la mise du joueur :" << endl;
			cout << endl;
			getline(cin, mise);
			cout << endl;

			//String to int + if error y will be 0
			y = atoi(mise.c_str());
			potok = ispotok(y);
			if (potok == 0) {
				cout << "Valeur impossible, la mise doit etre positif" << endl;
				cout << endl;
			}
		}

		//calcul odd and prcent
		odd  = (x + y) * 100 / y;
		prcent = 10000 / (odd + 100);

		cout <<  "Vous avez une cote de " << RED << prcent << "%" << RESET << endl;

		cout << endl;
		cout << "Voulez vous calculer un nouveau % preflop ?" << endl;
		cout << "OUI pour recalculer" << endl;
		cout << "NON pour retourner au menu" << endl;
		cout << "QUIT pour fermer l app" << endl;
		cout << endl;
		getline(cin, c);
	}
	if (c == "QUIT" || c == "q")
                exit(0);
}
