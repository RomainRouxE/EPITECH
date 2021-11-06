#include "../INC/preflopP.hpp"

#define RED     "\033[31m"
#define RESET   "\033[0m"

int PreflopP()
{
	int a = 0;
	string c = "OUI";

	while (c == "OUI" || c == "o") {

		ifstream fichier("./TXT/PreflopP.txt");
		int x;
		string main, nb, line, word, size;

		if(fichier) {
			a = 0;
			int count = 1;
			cout << "Entrez le nombre de joueur a la table :" << endl;
			cout << endl;
			getline(cin, nb);
			stringstream nbI(nb);
			nbI >> x;
			if (x < 2 || x > 10) {
				cout << endl;
				cout << "Nombre de joueurs seulement entre 2 et 10." << endl;
				cout << endl;
				getline(cin,nb);
			}
			cout << endl;
			cout << "Entrez une main a evaluer :" << endl;
			cout << endl;
			getline(cin, main);
			while(getline(fichier,line)) {
				if (line.substr(0, line.find(" ")) == main) {
					while (count != x) {
						line=line.substr(line.find_first_of(" \t")+2);
						istringstream ss(line);
						ss >> size;
						if (count == x - 1) {
							a = 1;
							cout << endl;
							cout << "Vous avez " << RED <<  size << "%" << RESET << " de chance de gagner le coup avec cette main preflop." << endl;
						}
						count++;
					}
				}
			}
		}

		if (a == 0) {
			cout << endl;
			cout << "Main non valide ou main trop faible" << endl;
		}

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
