#include "dragonGame.h"
#include <iostream>
#include "tableauMb.h"

Dragon initialiserDrag() {
	Dragon drag;
	return drag;
}

void detruireDrag(stack<Position>& pile){
	while (!pile.empty()) {
		pile.pop();
	}
}

void missionDragonSp2(Lab lab, Dragon drag) {
	unsigned int nb = 0;
	while (nb < 10 && !(drag.move.empty())) {
		drag.pos = drag.move.top();
		lab.tab[drag.pos.z][drag.pos.y][drag.pos.x].estLu = true;
		lab.tab[drag.pos.z][drag.pos.y][drag.pos.x].car = nb + 48;
		drag.move.pop();
		++nb;
		//Mettre à jour chemin connexe

		if (!(drag.pos.z == lab.PDM.z && drag.pos.y == lab.PDM.y && drag.pos.x == lab.PDM.x)) {

			//Orientation
			stack<int> deplacement;

			for (int i = 1; i < 8; ++i) {
				switch (i) {
				case 1:
					deplacement.push(i);
					break;
				case 2:
				case 3:
				case 4:
					if (drag.pos.y != (lab.lin - 1))
						deplacement.push(i);
					else
						i = 4;
					break;
				case 5:
					deplacement.push(i);
					break;
				case 6:
				case 7:
				case 8:
					if (drag.pos.y != 0)
						deplacement.push(i);
					else
						i = 8;
					break;
				default:
					cerr << "Erreur" << endl;
				}
			}

			while (!deplacement.empty()) {
				Position mouv = drag.pos;
				switch (deplacement.top()) {
				case 1:
					if (drag.pos.x == 0) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][(lab.lin - 1) - drag.pos.y][lab.col - 1].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = (lab.lin - 1) - drag.pos.y;
							mouv.x = lab.col - 1;
							drag.move.push(mouv);
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y][drag.pos.x - 1].car != '#') {
						mouv.x--;
						drag.move.push(mouv);
					}
					break;
				case 2:
					if (drag.pos.x == 0) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][lab.lin - drag.pos.y - 2][lab.col - 1].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = lab.lin - drag.pos.y - 2;
							mouv.x = lab.col - 1;
							drag.move.push(mouv);
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y + 1][drag.pos.x - 1].car != '#') {
						mouv.x--;
						mouv.y++;
						drag.move.push(mouv);
					}
					break;
				case 3:
					if (lab.tab[drag.pos.z][drag.pos.y + 1][drag.pos.x].car != '#') {
						mouv.y++;
						drag.move.push(mouv);
					}
					break;
				case 4:
					if (drag.pos.x == (lab.col - 1)) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][lab.lin - drag.pos.y - 2][0].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = lab.lin - drag.pos.y - 2;
							mouv.x = 0;
							drag.move.push(mouv);
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y + 1][drag.pos.x + 1].car != '#') {
						mouv.x++;
						mouv.y++;
						drag.move.push(mouv);
					}
					break;
				case 5:
					if (drag.pos.x == (lab.col - 1)) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][(lab.lin - 1) - drag.pos.y][0].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = (lab.lin - 1) - drag.pos.y;
							mouv.x = 0;
							drag.move.push(mouv);
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y][drag.pos.x + 1].car != '#') {
						mouv.x++;
						drag.move.push(mouv);
						}
					break;
				case 6:
					if (drag.pos.x == (lab.col - 1)) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][lab.lin - drag.pos.y][0].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = lab.lin - drag.pos.y;
							mouv.x = 0;
							drag.move.push(mouv);
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y - 1][drag.pos.x + 1].car != '#') {
						mouv.x++;
						mouv.y--;
						drag.move.push(mouv);
					}
					break;
				case 7:
					if (lab.tab[drag.pos.z][drag.pos.y - 1][drag.pos.x].car != '#') {
						mouv.y--;
						drag.move.push(mouv);
					}
					break;
				case 8:
					if (drag.pos.x == 0) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][lab.lin - drag.pos.y][lab.col - 1].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = lab.lin - drag.pos.y;
							mouv.x = lab.col - 1;
							drag.move.push(mouv);
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y - 1][drag.pos.x - 1].car != '#') {
						mouv.x--;
						mouv.y--;
						drag.move.push(mouv);
					}
					break;
				default:
					cerr << "Erreur lors de la recherche de chemin" << endl;
				}
				deplacement.pop();
			}
			cout << "( " << drag.move.top().z << ", " << drag.move.top().y << ", " << drag.move.top().x << ")" << endl;
			affichersp2(lab);
		}
		else {
		cout << "Pas trouvé" << endl;
		}
	}
}
