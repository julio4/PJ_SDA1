#include "indexPositionMb.h"
#include <iostream>

void initialiserPos(Lab& lab, Dragon& drag) {
	bool initDrag = false;
	bool initPDM = false;
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
			for (unsigned int j = 0; j < lab.lin; ++j) {
				for (unsigned int l = 0; l < lab.col; ++l) {
					if (lab.tab[i][j][l].car == 'D') {
						drag.pos.z = i;
						drag.pos.y = j;
						drag.pos.x = l;
						initDrag = true;
					}
					if (lab.tab[i][j][l].car == 'P') {
						lab.PDM.z = i;
						lab.PDM.y = j;
						lab.PDM.x = l;
						initPDM = true;
					}
					if (initDrag && initPDM) {
						return;
					}
				}
			}
		}
	cerr << "Erreur! Fichier texte non conforme." << endl;
	return;
}
