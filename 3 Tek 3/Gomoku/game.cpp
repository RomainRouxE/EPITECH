#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int a = 0;
	int count = 0;
	int tour = 4;
	int colone, ligne, ce, le, savec, savel, z, size, save, save1, save2;
	char virg;
	string info;

	getline(cin, info);
	if (info.substr(0, info.find(" ")) == "START") {
		info=info.substr(info.find_first_of(" \t")+1);
		istringstream ss(info);
		ss >> size;
		if (size < 5 || size > 20) {
			while (size < 5 || size > 20) {
				cout << "ERROR" << endl;
				getline(cin, info);
				info=info.substr(info.find_first_of(" \t")+1);
				istringstream ss(info);
				ss >> size;
			}
		}
		cout << "OK" << endl;
		int t[20][20];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				t[i][j] = 0;
		while (info != "END") {
			z = 1;
			getline(cin, info);
			if (info.substr(0, info.find(" ")) == "RESTART") {
				cout << "OK" << endl;
				tour = 4;
				for (int i = 0; i < size; i++)
					for (int j = 0; j < size; j++)
						t[i][j] = 0;
			}
			if (info == "BEGIN") {
				ligne = 10;
				colone = 10;
				t[ligne][colone] = 2;
				cout << colone << "," << ligne << endl;
			}
			if (info == "BOARD") {
				string DONE = "aaa";
				int p;
				int c = 0;
				while (DONE != "DONE") {
					getline(cin, DONE);
					istringstream ss(DONE);
					if(DONE != "DONE") {
						if (DONE.length() > 7 || DONE.length() < 5) {
							cerr << "Erreur donnee board" << endl;
							exit(84);
						}
						for(int i = 0; i < DONE.length(); i++) {
							if(!(DONE[i] >= '0' && DONE[i] <= '9' || DONE[i] == ',')) {
								cerr << "Veuillez entrer des coordonnes du type [x],[y],[z]" << endl;
								exit(84);
							}
						}
						ss >> ce >> virg >> le >> virg >> p;
						if (virg = "," && ce >= 0 && ce <= 20 && le >= 0 && le <= 20) {
							if (p == 1) {
								c++;
								t[le][ce] = 2;
							}
							else
								t[le][ce] = 1;
							tour = 0;
							z = 0;
						}
						else {
							cerr << "Coordonne trop grand ou petit" << endl;
                                                        exit(84);
						}
					}
					if (c == 1 || c == 0)
						tour = 4;
				}
			}
			if (info == "ABOUT")
				cout << "name= IA Gomoku, author= Romain - Victor, country = France" << endl;
			if (info.substr(0, info.find(" ")) == "TURN" || z == 0) {
				if (z != 0) {
					info=info.substr(info.find_first_of(" \t")+1);
					istringstream ss(info);
					ss >> ce >> virg >> le;
					if (t[le][ce] != 0) {
						cerr << "Case deja prise" << endl;
						exit(84);
					}
					z = 1;
					t[le][ce] = 1;
				}
				if (tour == 4) {
					if (t[10][10] == 0) {
						ligne = 10;
						colone = 10;
					}
					else {
						ligne = 10;
						colone = 11;
					}
					tour = 0;
				}
				else {
// check 4 a la suite allie
					for (int i = 0; i < size && a == 0; ++i) {
						for (int j = 0; j < size && a == 0; ++j) {
							//horizontal
							if (j < size - 4 && a == 0) {
								if (t[i][j] == t[i][j+1] && t[i][j] == t[i][j+2] && t[i][j] == t[i][j+3] && t[i][j] == 2) {
									if (t[i][j-1] == 0) {
										colone = j-1;
										ligne = i;
										a = 1;
									}
									if (t[i][j+4] == 0 && a == 0) {
										colone = j+4;
										ligne = i;
										a = 1;
									}
								}
							}
							//vertical
							if (i < size - 4 && a == 0) {
								if (t[i][j] == t[i+1][j] && t[i][j] == t[i+2][j] && t[i][j] == t[i+3][j] && t[i][j] == 2) {
									if (t[i+4][j] == 0 && a == 0) {
										ligne = i+4;
										colone = j;
										a = 1;
									}
									if (t[i-1][j] == 0 && a == 0) {
										ligne = i-1;
										colone = j;
										a = 1;
									}
								}
							}
							//diag bas droite
							if (i < size - 4 && j < size - 4 && a == 0) {
								if (t[i][j] == t[i+1][j+1] && t[i][j] == t[i+2][j+2] && t[i][j] == t[i+3][j+3] && t[i][j] == 2) {
									if (t[i-1][j-1] == 0) {
										ligne = i-1;
										colone = j-1;
										a = 1;
									}
									if (t[i+4][j+4] == 0 && a == 0) {
										ligne = i+4;
										colone = j+4;
										a = 1;
									}
								}
							}
							//diag haut droite
							if (i > 4 && j < size - 4 && a == 0) {
								if (t[i][j] == t[i-1][j+1] && t[i][j] == t[i-2][j+2] && t[i][j] == t[i-3][j+3] && t[i][j] == 2) {
									if (t[i+1][j-1] == 0 && a == 0) {
										ligne = i+1;
										colone = j-1;
										a = 1;
									}
									if (t[i-4][j+4] == 0 && a == 0) {
										ligne = i-4;
										colone = j+4;
										a = 1;
									}
								}
							}
							//horizontal + space
							if (j < size - 5 && a == 0 && t[i][j] == 2) {
								for (save = j; save < j+5; ++save) {
									if (t[i][save] == 2)
										count++;
									if (t[i][save] == 0)
										savec = save;
								}
								if (count == 4 && t[i][savec] == 0) {
									colone = savec;
									ligne = i;
									count = 0;
									if (t[ligne][colone-1] == 2 && t[ligne][colone+1] == 2)
										a = 1;
								}
								count = 0;
							}
							//vertical + space
							if (i < size - 5 && a == 0 && t[i][j] == 2) {
								for (save = i; save < i+5; ++save) {
									if (t[save][j] == 2)
										count++;
									if (t[save][j] == 0)
										savel = save;
								}
								if (count == 4 && t[savel][j] == 0) {
									colone = j;
									ligne = savel;
									count = 0;
									if (t[ligne-1][colone] == 2 && t[ligne+1][colone] == 2)
                                                                                a = 1;
								}
								count = 0;
							}
							//bas droit + space
							if (i < size - 5 && j < size - 5 && a == 0 && t[i][j] == 2) {
								for (save1 = i, save2 = j; save1 < i+5, save2 < j+5; ++save1, ++save2) {
									if (t[save1][save2] == 2)
										count++;
									if (t[save1][save2] == 0) {
										savel = save1;
										savec = save2;
									}
								}
								if (count == 4 && t[savel][savec] == 0) {
									colone = savec;
									ligne = savel;
									count = 0;
									if (t[ligne-1][colone-1] == 2 && t[ligne+1][colone+1] == 2)
										a = 1;
								}
								count = 0;
							}
							//haut droit + space
							if (i > 4 && j < size - 5 && a == 0 && t[i][j] == 2) {
								for (save1 = i, save2 = j; save1 < i-5, save2 < j+5; --save1, ++save2) {
									if (t[save1][save2] == 2)
										count++;
									if (t[save1][save2] == 0) {
										savel = save1;
										savec = save2;
									}
								}
								if (count == 4 && t[savel][savec] == 0) {
									colone = savec;
									ligne = savel;
									count = 0;
									if (t[ligne-1][colone+1] == 2 && t[ligne+1][colone-1] == 2)
										a = 1;
								}
								count = 0;
							}
						}
					}
// check 4 a la suite ennemi
					for (int i = 0; i < size && a == 0; ++i) {
						for (int j = 0; j < size && a == 0; ++j) {
							//horizontal
							if (j < size - 4 && a == 0) {
								if (t[i][j] == t[i][j+1] && t[i][j] == t[i][j+2] && t[i][j] == t[i][j+3] && t[i][j] == 1) {
									if (t[i][j-1] == 0) {
										colone = j-1;
										ligne = i;
										a = 1;
									}
									if (t[i][j+4] == 0 && a == 0) {
										colone = j+4;
										ligne = i;
										a = 1;
									}
								}
							}
							//vertical
							if (i < size - 4 && a == 0) {
								if (t[i][j] == t[i+1][j] && t[i][j] == t[i+2][j] && t[i][j] == t[i+3][j] && t[i][j] == 1) {
									if (t[i+4][j] == 0 && a == 0) {
										ligne = i+4;
										colone = j;
										a = 1;
									}
									if (t[i-1][j] == 0 && a == 0) {
										ligne = i-1;
										colone = j;
										a = 1;
									}
								}
							}
							//diag bas droite
							if (i < size - 4 && j < size - 4 && a == 0) {
								if (t[i][j] == t[i+1][j+1] && t[i][j] == t[i+2][j+2] && t[i][j] == t[i+3][j+3] && t[i][j] == 1) {
									if (t[i-1][j-1] == 0) {
										ligne = i-1;
										colone = j-1;
										a = 1;
									}
									if (t[i+4][j+4] == 0 && a == 0) {
										ligne = i+4;
										colone = j+4;
										a = 1;
									}
								}
							}
							//diag haut droite
							if (i > 4 && j < size - 4 && a == 0) {
								if (t[i][j] == t[i-1][j+1] && t[i][j] == t[i-2][j+2] && t[i][j] == t[i-3][j+3] && t[i][j] == 1) {
									if (t[i+1][j-1] == 0 && a == 0) {
										ligne = i+1;
										colone = j-1;
										a = 1;
									}
									if (t[i-4][j+4] == 0 && a == 0) {
										ligne = i-4;
										colone = j+4;
										a = 1;
									}
								}
							}
							//horizontal + space
							if (j < size - 5 && a == 0 && t[i][j] == 1) {
								for (save = j; save < j+5; ++save) {
									if (t[i][save] == 1)
										count++;
									if (t[i][save] == 0)
										savec = save;
								}
								if (count == 4 && t[i][savec] == 0) {
									colone = savec;
									ligne = i;
									count = 0;
									if (t[ligne][colone-1] == 1 && t[ligne][colone+1] == 1)
                                                                                a = 1;
								}
								count = 0;
							}
							//vertical + space
                                                        if (i < size - 5 && a == 0 && t[i][j] == 1) {
                                                                for (save = i; save < i+5; ++save) {
                                                                        if (t[save][j] == 1)
                                                                                count++;
                                                                        if (t[save][j] == 0)
                                                                                savel = save;
                                                                }
                                                                if (count == 4 && t[savel][j] == 0) {
                                                                        colone = j;
                                                                        ligne = savel;
									count = 0;
									if (t[ligne-1][colone] == 1 && t[ligne+1][colone] == 1)
                                                                                a = 1;
                                                                }
								count = 0;
                                                        }
							//bas droit + space
							if (i < size - 5 && j < size - 5 && a == 0 && t[i][j] == 1) {
								for (save1 = i, save2 = j; save1 < i+5, save2 < j+5; ++save1, ++save2) {
									if (t[save1][save2] == 1)
										count++;
									if (t[save1][save2] == 0) {
										savel = save1;
										savec = save2;
									}
								}
								if (count == 4 && t[savel][savec] == 0) {
									colone = savec;
									ligne = savel;
									count = 0;
									if (t[ligne-1][colone-1] == 1 && t[ligne+1][colone+1] == 1)
										a = 1;
								}
								count = 0;
							}
							//haut droit + space
							if (i > 4 && j < size - 5 && a == 0 && t[i][j] == 1) {
								for (save1 = i, save2 = j; save1 < i-5, save2 < j+5; --save1, ++save2) {
									if (t[save1][save2] == 1)
										count++;
									if (t[save1][save2] == 0) {
										savel = save1;
										savec = save2;
									}
								}
								if (count == 4 && t[savel][savec] == 0) {
									colone = savec;
									ligne = savel;
									count = 0;
									if (t[ligne-1][colone+1] == 1 && t[ligne+1][colone-1] == 1)
										a = 1;
								}
								count = 0;
							}
						}
					}
//check 3 a la suite allie
					for (int i = 0; i < size && a == 0; ++i) {
						for (int j = 0; j < size && a == 0; ++j) {
							//horizontal
							if (j < size - 3) {
								if (t[i][j] == t[i][j+1] && t[i][j] == t[i][j+2] && t[i][j] == 2) {
									if (t[i][j-1] == 0 && a == 0) {
										colone = j-1;
										ligne = i;
										a = 1;
									}
									if (t[i][j+3] == 0 && a == 0) {
										colone = j+3;
										ligne = i;
										a = 1;
									}
								}
							}
							//vertical
							if (i < size - 3 && a == 0) {
								if (t[i][j] == t[i+1][j] && t[i][j] == t[i+2][j] && t[i][j] == 2) {
									if (t[i-1][j] == 0 && a == 0) {
										ligne = i-1;
										colone = j;
										a = 1;
									}
									if (t[i+3][j] == 0 && a == 0) {
										ligne = i+3;
										colone = j;
										a = 1;
									}
								}
							}
							//diag bas droite
							if (i < size - 3 && j < size - 3 && a == 0) {
								if (t[i][j] == t[i+1][j+1] && t[i][j] == t[i+2][j+2] && t[i][j] == 2) {
									if (t[i-1][j-1] == 0 && a == 0) {
										ligne = i-1;
										colone = j-1;
										a = 1;
									}
									if (t[i+3][j+3] == 0 && a == 0) {
										ligne = i+3;
										colone = j+3;
										a = 1;
									}
								}
							}
							//diag haut droite
							if (i > 3 && j < size - 3 && a == 0) {
								if (t[i][j] == t[i-1][j+1] && t[i][j] == t[i-2][j+2] && t[i][j] == 2) {
									if (t[i+1][j-1] == 0 && a == 0) {
										ligne = i+1;
										colone = j-1;
										a = 1;
									}
									if (t[i-3][j+3] == 0 && a == 0) {
										ligne = i-3;
										colone = j+3;
										a = 1;
									}
								}
							}
						}
					}
//check 3 a la suite ennemi
					for (int i = 0; i < size && a == 0; ++i) {
						for (int j = 0; j < size && a == 0; ++j) {
							//horizontal
							if (j < size - 3) {
								if (t[i][j] == t[i][j+1] && t[i][j] == t[i][j+2] && t[i][j] == 1) {
									if (t[i][j-1] == 0 && a == 0) {
										colone = j-1;
										ligne = i;
										a = 1;
									}
									if (t[i][j+3] == 0 && a == 0) {
										colone = j+3;
										ligne = i;
										a = 1;
									}
								}
							}
							//vertical
							if (i < size - 3 && a == 0) {
								if (t[i][j] == t[i+1][j] && t[i][j] == t[i+2][j] && t[i][j] == 1) {
									if (t[i-1][j] == 0 && a == 0) {
										ligne = i-1;
										colone = j;
										a = 1;
									}
									if (t[i+3][j] == 0 && a == 0) {
										ligne = i+3;
										colone = j;
										a = 1;
									}
								}
							}
							//diag bas droite
							if (i < size - 3 && j < size - 3 && a == 0) {
								if (t[i][j] == t[i+1][j+1] && t[i][j] == t[i+2][j+2] && t[i][j] == 1) {
									if (t[i-1][j-1] == 0 && a == 0) {
										ligne = i-1;
										colone = j-1;
										a = 1;
									}
									if (t[i+3][j+3] == 0 && a == 0) {
										ligne = i+3;
										colone = j+3;
										a = 1;
									}
								}
							}
							//diag haut droite
							if (i > 3 && j < size - 3 && a == 0) {
								if (t[i][j] == t[i-1][j+1] && t[i][j] == t[i-2][j+2] && t[i][j] == 1) {
									if (t[i+1][j-1] == 0 && a == 0) {
										ligne = i+1;
										colone = j-1;
										a = 1;
									}
									if (t[i-3][j+3] == 0 && a == 0) {
										ligne = i-3;
										colone = j+3;
										a = 1;
									}
								}
							}
						}
					}
//check 2 a la suite allie
					for (int i = 0; i < size && a == 0; ++i) {
						for (int j = 0; j < size && a == 0; ++j) {
							//horizontal
							if (j < size - 2) {
								if (t[i][j] == t[i][j+1] && t[i][j] == 2) {
									if (t[i][j-1] == 0 && a == 0) {
										colone = j-1;
										ligne = i;
										a = 1;
									}
									if (t[i][j+2] == 0 && a == 0) {
										colone = j+2;
										ligne = i;
										a = 1;
									}
								}
							}
							//vertical
							if (i < size - 2 && a == 0) {
								if (t[i][j] == t[i+1][j] && t[i][j] == 2) {
									if (t[i+2][j] == 0 && a == 0) {
										ligne = i+2;
										colone = j;
										a = 1;
									}
									if (t[i-1][j] == 0 && a == 0) {
										ligne = i-1;
										colone = j;
										a = 1;
									}
								}
							}
							//diag bas droite
							if (i < size - 2 && j < size - 2 && a == 0) {
								if (t[i][j] == t[i+1][j+1] && t[i][j] == 2) {
									if (t[i-1][j-1] == 0 && a == 0) {
										ligne = i-1;
										colone = j-1;
										a = 1;
									}
									if (t[i+2][j+2] == 0 && a == 0) {
										ligne = i+2;
										colone = j+2;
										a = 1;
									}
								}
							}
							//diag haut droite
							if (i > 2 && j < size - 2 && a == 0) {
								if (t[i][j] == t[i-1][j+1] && t[i][j] == 2) {
									if (t[i+1][j-1] == 0 && a == 0) {
										ligne = i+1;
										colone = j-1;
										a = 1;
									}
									if (t[i-2][j+2] == 0 && a == 0) {
										ligne = i-2;
										colone = j+2;
										a = 1;
									}
								}
							}
						}
					}
				}
				// check si case libre si non prend une case libre
				if (t[ligne][colone] != 0 || ligne < 0 || ligne > size || colone < 0 || colone > size) {
					for (int i = 0; i < size && a == 0; ++i) {
						for (int j = 0; j < size && a == 0; ++j) {
							if (j < size) {
								if (t[i][j] == 2) {
									if (t[i][j-1] == 0 && a == 0) {
										colone = j-1;
										ligne = i;
										if (ligne >= 0 && colone >= 0)
											a = 1;
									}
									if (t[i][j+1] == 0 && a == 0) {
										colone = j+1;
										ligne = i;
										if (ligne >= 0 && colone >= 0)
											a = 1;
									}
									if (t[i+1][j] == 0 && a == 0) {
										ligne = i+1;
										colone = j;
										if (ligne >= 0 && colone >= 0)
											a = 1;
									}
									if (t[i-1][j] == 0 && a == 0) {
										ligne = i-1;
										colone = j;
										if (ligne >= 0 && colone >= 0)
											a = 1;
									}
								}
							}
						}
					}
				}
				cout << colone << "," << ligne << endl;
				if (t[ligne][colone] != 0) {
					cerr << "Case deja prise" << endl;
					exit(84);
				}
				t[ligne][colone] = 2;
			}
			a = 0;
			for (int i = 0; i < size; ++i) {
				for (int j = 0; j < size; ++j) {
					if (t[i][j] == 1)
						cout << "X";
					else if(t[i][j] == 2)
						cout << "O";
					else
						cout << "-";
				}
				cout << endl;
			}

		}
	}
	else
		cout << "Error" << endl;
}
