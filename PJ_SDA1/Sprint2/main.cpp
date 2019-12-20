/**
 * @file main.cpp
 * @author Jules Doumèche, Martin Gwenole
 * @version 2 - 2019
 * @brief  Projet SDA - Sprint 2
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
#include "dragonGame.h"

const char FICHIER[STRING_SIZE] = "inSmall.txt";

int main() {

	// Initialisation variable + input stream

	unsigned int m, n;

	ifstream in(FICHIER);
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
	if (!in) {
		cout << "Erreur!" << endl;
		cerr << "Fichier introuvable" << endl;
		return 1;
	}

	// Execution Sprint2
	in >> m >> n;

	Item*** tableauMb = initialiserTab(m, n);
	initialiserLab(in, tableauMb, m, n);

	affichersp2(tableauMb, m, n);

	in.close();
	detruireLab(tableauMb, m, n);
	detruireTab(tableauMb, m, n);
	return 0;
}