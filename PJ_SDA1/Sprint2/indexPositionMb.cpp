#include "indexPositionMb.h"

Position initialiserPos(Item*** tab, unsigned int& x, unsigned int& y) {
	Position pos_init;
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
		for (unsigned int j = 0; j < y; ++j) {
			for (unsigned int l = 0; l < x; ++l) {
				if (tab[i][j][l].car == 'D') {
					pos_init.z = i;
					pos_init.y = j;
					pos_init.x = l;
					return pos_init;
				}
			}
		}
	}
	// cerr << "Erreur lors de l'initialisation de la position du dragon" << endl;
}
