#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

enum {NB_DAMIERS = 2};

#include "tableauMb.h"
#include "labyrintheMb.h"

int main() {
	char tableauMb[NB_DAMIERS][2][2];
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



	char a;
	in >> a;
	while (in) {
		cout << a;
		in >> a;
	}
	in.close();
	return 0;
}