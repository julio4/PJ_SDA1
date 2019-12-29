/**
 * @file main.cpp
 * @author Jules Doum�che, Martin Gwenole
 * @version 2 - 2019
 * @brief  Projet SDA - Sprint 2
 */

#include "tableauMb.h"
#include "dragonGame.h"
#include <clocale>

int main() {
	locale::global(locale{ "" });

	//Input stream

	ifstream in(fichier);
	if (!in) {
		cerr << "Erreur! Fichier introuvable" << endl;
		return 1;
	}

	//Initialisation Labyrinthe

	Lab lab;
	in >> lab.col >> lab.lin;
	initialiserTab(lab);
	initialiserLab(in, lab);
	in.close();

	//Recherche Dragon et affichage

	Dragon drag = initialiserDrag(lab);
	missionDragonSp2(lab, drag);

	// Desallouement
	detruireDrag(drag);
	detruireLab(lab);
	detruireTab(lab);

	return 0;
}
