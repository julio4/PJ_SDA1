/**
 * @file main.cpp
 * @author Jules Doumèche, Martin Gwenole
 * @version 1 - 2019
 * @brief  Projet SDA - Sprint 1
 */

/*
ARBORESCENCE DES #INCLUDE:

							+----------+
							| main.cpp |
							+----+-----+
								 ^
								 |
								 |
						   +-----+-------+        +---------------+
						   | tableauMb.h +<-------+ tableauMb.cpp |
						   +-----+-------+        +---------------+
		 +-----------+           ^
		 | <fstream> +------+    |
		 +-----------+      v    |
						 +--+----+--------+     +------------------+
						 | labyrintheMb.h +<----+ labyrintheMb.cpp |
						 +--+----+--------+     +------------------+
		+------------+      ^    ^
		| <iostream> +------+    |
		+------------+           |
							 +---+----+
							 | item.h |
							 +--------+

*/

#include "tableauMb.h"

int main() {

	// Initialisation variable + input stream

	int x = 0; // x, colonne
	int y = 0; // y, ligne

	int coordx = 0;
	int coordy = 0;

	ifstream in;
	/* Ouverture du fichier .txt via la console
	char fic[STRING_SIZE] = { NULL };
	do {
		cout << "Entrez fichier à ouvrir:";
		cin >> fic;
		cout << endl;
		in.open(fic);
		if (!in) {
			cout << "Erreur!" << endl;
			cerr << "Fichier introuvable" << endl;
			//return 1;
		}
	} while (!in); */
	in.open(file_in);
	if (!in) {
		cout << "Erreur!" << endl;
		cerr << "Fichier introuvable" << endl;
		return 1;
	}

	// Execution Sprint1

	ItemMb*** tableauMb = initialiserTab(in, x, y);
	initialiserLab(in, tableauMb, x, y);

	recherche(tableauMb, x, y, coordx, coordy);
	cout << coordx << " " << coordy << endl;

	in.close();

	detruireLab(tableauMb, x, y);
	detruireTab(tableauMb, x, y);

	return 0;
}

void recherche(ItemMb*** tab, int& x, int& y) {

	ifstream iread;
	iread.open(file_in, ifstream::in);

	char c = NULL;
	Position spyro, plan;

	for (int i = 0; i < NB_DAMIERS; ++i) {
		//Lire tab[i]
		for (int j = 0; j < y; ++j) {
			//Lire ligne j
			for (int k = 0; k < x; ++k) {
				c = tab[i][j][k];
				if (c == 'D') {
					init_pos(spyro, i, j, k);
				}
				if (c == 'P') {
					init_pos(plan, i, j, k);
				}
			}
		}
	}

	iread.close();
}

void init_pos(Position& pos,int& z, int& y, int& x) {
	
	pos.x = x;
	pos.y = y;
	pos.z = z;

}

void fonction_principal_selon_hugo(Position& spyro, Position& peach) {

}