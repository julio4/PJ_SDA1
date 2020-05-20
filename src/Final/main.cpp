/**
 * @file main.cpp
 * @author Jules Doum�che, Martin Gwenole
 * @version 5 - 2019
 * @brief  Projet SDA - Sprint 5
 */

#include "tableauMb.h"
#include "dragonGame.h"
#include <clocale>

int main() {
	locale::global(locale{ "" });

	//Input stream

	ifstream in(fichier);
	if (!in) {
		cout << "Erreur!" << endl;
		cerr << "Fichier introuvable" << endl;
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
	missionDragonSp5(lab, drag);

	// On lib�re l'espace allou�, destruction des tableaux et des objets

	detruireDrag(drag);
	detruireLab(lab);
	detruireTab(lab);
	
	return 0;
}
