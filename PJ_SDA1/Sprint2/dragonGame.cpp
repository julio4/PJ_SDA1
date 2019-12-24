#include "dragonGame.h"
#include <iostream>
#include "tableauMb.h"

Dragon initialiserDrag() {
	Dragon drag;
	drag.pos.z = 0;
	drag.pos.y = 0;
	drag.pos.x = 0;
	return drag;
}

void detruireDrag(Dragon& drag){
	drag.pos.z = 0;
	drag.pos.y = 0;
	drag.pos.x = 0;
}

void missionDragonSp2(Lab& lab, Dragon& drag) {
	unsigned int nb = 0;
	stack<Position> move;
	move.push(drag.pos);
	while (nb < 10 && !(move.empty())) {
		drag.pos = move.top();
		lab.tab[drag.pos.z][drag.pos.y][drag.pos.x].estLu = true;
		lab.tab[drag.pos.z][drag.pos.y][drag.pos.x].car = nb + 48;
		move.pop();
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

			//reverse stack
			if (deplacement.size() > 1) {
				stack<int> reverse;
				int size = deplacement.size();
				for (unsigned int i = 0; i < size; ++i) {
					reverse.push(deplacement.top());
					deplacement.pop();
				}
				deplacement.swap(reverse);
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
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y][drag.pos.x - 1].car != '#') {
						mouv.x--;
					}
					break;
				case 2:
					if (drag.pos.x == 0) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][lab.lin - drag.pos.y - 2][lab.col - 1].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = lab.lin - drag.pos.y - 2;
							mouv.x = lab.col - 1;
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y + 1][drag.pos.x - 1].car != '#') {
						mouv.x--;
						mouv.y++;
					}
					break;
				case 3:
					if (lab.tab[drag.pos.z][drag.pos.y + 1][drag.pos.x].car != '#') {
						mouv.y++;
					}
					break;
				case 4:
					if (drag.pos.x == (lab.col - 1)) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][lab.lin - drag.pos.y - 2][0].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = lab.lin - drag.pos.y - 2;
							mouv.x = 0;
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y + 1][drag.pos.x + 1].car != '#') {
						mouv.x++;
						mouv.y++;
					}
					break;
				case 5:
					if (drag.pos.x == (lab.col - 1)) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][(lab.lin - 1) - drag.pos.y][0].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = (lab.lin - 1) - drag.pos.y;
							mouv.x = 0;
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y][drag.pos.x + 1].car != '#') {
						mouv.x++;
						}
					break;
				case 6:
					if (drag.pos.x == (lab.col - 1)) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][lab.lin - drag.pos.y][0].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = lab.lin - drag.pos.y;
							mouv.x = 0;
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y - 1][drag.pos.x + 1].car != '#') {
						mouv.x++;
						mouv.y--;
					}
					break;
				case 7:
					if (lab.tab[drag.pos.z][drag.pos.y - 1][drag.pos.x].car != '#') {
						mouv.y--;
					}
					break;
				case 8:
					if (drag.pos.x == 0) {
						if (lab.tab[(NB_DAMIERS - 1) - drag.pos.z][lab.lin - drag.pos.y][lab.col - 1].car != '#') {
							mouv.z = (NB_DAMIERS - 1) - drag.pos.z;
							mouv.y = lab.lin - drag.pos.y;
							mouv.x = lab.col - 1;
						}
					}
					else if (lab.tab[drag.pos.z][drag.pos.y - 1][drag.pos.x - 1].car != '#') {
						mouv.x--;
						mouv.y--;
					}
					break;
				default:
					cerr << "Erreur lors de la recherche de chemin" << endl;
				}
				if (lab.tab[mouv.z][mouv.y][mouv.x].estLu == false) {
					move.push(mouv);
				}
				deplacement.pop();
			}
			affichersp2(lab);
			if (nb == 10) {
				while (!(move.empty())) {
					cout << "( " << move.top().x << ", " << move.top().y << ", " << move.top().z + 1 << ") ";
					move.pop();
				}
			}
		}
		else {
		cout << "Pas trouvé" << endl;
		}
	}
}
