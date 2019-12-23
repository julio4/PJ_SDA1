#include "indexPositionMb.h"
#include <iostream>

void initialiserPos(Position& posDrag, Position& posPDM, Item*** tab, unsigned int& x, unsigned int& y) {
	bool initDrag = false;
	bool initPDM = false;
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
			for (unsigned int j = 0; j < y; ++j) {
				for (unsigned int l = 0; l < x; ++l) {
					if (tab[i][j][l].car == 'D') {
						posDrag.z = i;
						posDrag.y = j;
						posDrag.x = l;
						initDrag = true;
					}
					if (tab[i][j][l].car == 'P') {
						posPDM.z = i;
						posPDM.y = j;
						posPDM.x = l;
						initPDM = true;
					}
					if (initDrag && initPDM) {
						return;
					}
				}
			}
		}
	cerr << "Erreur lors de l'initialisation de la position du dragon" << endl;
	return;
}
