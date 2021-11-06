#include "../INC/preflopP.hpp"
#include "../INC/out.hpp"
#include "../INC/vs.hpp"
#include "../INC/cote.hpp"


int main()
{
	string mode;

	//get mode wanted until QUIT/q

	while (mode != "QUIT") {
		cout << endl;
		cout << "Choisissez le mode :" << endl;
		cout << endl << endl;
		cout << "- Proba preflop : Proba / p" << endl;
		cout << endl;
		cout << "- Determine les out possible : Out / o" << endl;
		cout << endl;
		cout << "- Determine votre meilleur main ainsi que les mains meilleur que la votre : VS / v" << endl;
		cout << endl;
		cout << "- Calcul la cote du pot : Cote / c" << endl;
		cout << endl;
		cout << "- Quit / q" << endl;
		cout << endl;
		getline(cin, mode);
		cout << endl;
		if (mode == "Proba" || mode == "p")
			PreflopP();
		if (mode == "Out" || mode == "o")
			Out();
		if (mode == "VS" || mode == "v")
			getvs();
		if (mode == "Cote" || mode == "c")
                        cote();
		if (mode == "QUIT" || mode == "q")
			exit(0);
	}
}
