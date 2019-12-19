#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

enum {NB_DAMIERS = 2};

#include "tableauMb.h"
#include "labyrintheMb.h"

int main() {

	ifstream in;
	in.open("inSmall.txt");
	if (!in) {
		cout << "Erreur!" << endl;
		cerr << "Fichier introuvable" << endl;
		return 1;
	}

	int m; // x (colonne)
	in >> m;

	int n; // y (ligne)
	in >> n;

	//faire allocation dynamique de tableauMb du nb de colonnes et de lignes de chaque damier avec tableauMb[-][m][n]

	char*** tableauMb = new char** [NB_DAMIERS];
	for (int i = 0; i < NB_DAMIERS; ++i) {
		tableauMb[i] = new char*[m];
		for (int j = 0; j < m; ++j) {
			tableauMb[i][j] = new char[n];
		}
	}
	cout << m << " " << n << endl;

	//Enregistrement des tableaux
	char c;
	for (int i = 0; i < NB_DAMIERS; ++i) {
		//RECUPERE TABLEAU DANS tableauMd[i][m][n]
		for (int j = 0; j < n; ++j) {
			//RECUPERE ligne m
			for (int l = 0; l < m; ++l) {
				in >> c;
				tableauMb[i][j][l] = c;
				cout << tableauMb[i][j][l];
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	in.close();





	return 0;
}