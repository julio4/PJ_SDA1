/**
 * @file main.cpp
 * @author Jules Doum�che, Martin Gwenole
 * @version 2 - 2019
 * @brief  Projet SDA - Sprint 2
 */

/*
ARBORESCENCE DES #INCLUDE:

*/

#include "tableauMb.h"
#include "dragonGame.h"
#include <clocale>

const char FICHIER[STRING_SIZE] = "inSmall.txt";

int main() {
	//locale::global(locale{ "" });

	// Initialisation variable + input stream

	ifstream in(FICHIER);
	/* Ouverture du fichier .txt via la console
	char fic[STRING_SIZE] = { NULL };
	do {
	cout << "Entrez fichier � ouvrir:";
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
	Lab lab;
	in >> lab.col >> lab.lin;
	//in >> m >> n;

	
	initialiserTab(lab);
	initialiserLab(in, lab);
	in.close();

	Dragon drag = initialiserDrag();
	initialiserPos(lab, drag);

	missionDragonSp2(lab, drag);

	// Developpement

	//
	detruireDrag(drag);
	detruireLab(lab);
	detruireTab(lab);
	return 0;
}
