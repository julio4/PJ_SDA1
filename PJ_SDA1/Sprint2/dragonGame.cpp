#include "dragonGame.h"
#include <iostream>
#include "tableauMb.h"

stack<Position> initialiserDrag(Position& posDrag) {
	stack<Position> pile;
	pile.push(posDrag);
	return pile;
}

void detruireDrag(stack<Position>& pile){
	while (!pile.empty()) {
		pile.pop();
	}
}

void missionDragonSp2(Item*** tab, stack<Position>& pile, Position& posDrag, Position& posPDM, unsigned int& m, unsigned int& n) {
	unsigned int nb = 0;
	while (nb < 10) {
		tab[posDrag.z][posDrag.y][posDrag.x].estLu = true;
		tab[posDrag.z][posDrag.y][posDrag.x].car = nb + 48;
		++nb;
		pile.pop(); // dépiler position ( i, j)

		//Mettre à jour chemin connexe

		if (!(posDrag.z == posPDM.z && posDrag.y == posPDM.y && posDrag.x == posPDM.x)) {

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
					if (posDrag.y != (n - 1))
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
					if (posDrag.y != 0)
						deplacement.push(i);
					else
						i = 8;
					break;
				default:
					cerr << "Erreur" << endl;
				}
			}

			while (!deplacement.empty()) {
				switch (deplacement.top()) {
				case 1:
					if (posDrag.x == 0) {
						if (tab[(NB_DAMIERS - 1) - posDrag.z][(n - 1) - posDrag.y][posDrag.x].car != '#') {
							posDrag.z = (NB_DAMIERS - 1) - posDrag.z;
							posDrag.y = (n - 1) - posDrag.y;
							pile.push(posDrag);
						}
					}
					else if (tab[posDrag.z][posDrag.y][posDrag.x - 1].car != '#') {
						posDrag.x--;
						pile.push(posDrag);
					}
					break;
				case 2:
					if (posDrag.x == 0) {
						if (tab[(NB_DAMIERS - 1) - posDrag.z][(n - 1) - posDrag.y][posDrag.x].car != '#') {
							posDrag.z = (NB_DAMIERS - 1) - posDrag.z;
							posDrag.y = (n - 1) - posDrag.y;
							pile.push(posDrag);
						}
					}
					else if (tab[posDrag.z][posDrag.y + 1][posDrag.x - 1].car != '#') {
						posDrag.x--;
						posDrag.y++;
						pile.push(posDrag);
					}
					break;
				case 3:
					if (tab[posDrag.z][posDrag.y + 1][posDrag.x].car != '#') {
						posDrag.y++;
						pile.push(posDrag);
					}
					break;
				case 4:
					if (posDrag.x == (m - 1)) {
						if (tab[(NB_DAMIERS - 1) - posDrag.z][(n - 1) - posDrag.y][posDrag.x].car != '#') {
							posDrag.z = (NB_DAMIERS - 1) - posDrag.z;
							posDrag.y = (n - 1) - posDrag.y;
							pile.push(posDrag);
						}
					}
					else if (tab[posDrag.z][posDrag.y + 1][posDrag.x + 1].car != '#') {
						posDrag.x++;
						posDrag.y++;
						pile.push(posDrag);
					}
					break;
				case 5:
					if (posDrag.x == (m - 1)) {
						if (tab[(NB_DAMIERS - 1) - posDrag.z][(n - 1) - posDrag.y][posDrag.x].car != '#') {
							posDrag.z = (NB_DAMIERS - 1) - posDrag.z;
							posDrag.y = (n - 1) - posDrag.y;
							pile.push(posDrag);
						}
					}
					else if (tab[posDrag.z][posDrag.y][posDrag.x + 1].car != '#') {
						posDrag.x++;
						pile.push(posDrag);
						}
					break;
				case 6:
					if (posDrag.x == (m - 1)) {
						if (tab[(NB_DAMIERS - 1) - posDrag.z][(n - 1) - posDrag.y][posDrag.x].car != '#') {
							posDrag.z = (NB_DAMIERS - 1) - posDrag.z;
							posDrag.y = (n - 1) - posDrag.y;
							pile.push(posDrag);
						}
					}
					else if (tab[posDrag.z][posDrag.y - 1][posDrag.x + 1].car != '#') {
						posDrag.x++;
						posDrag.y--;
						pile.push(posDrag);
					}
					break;
				case 7:
					if (tab[posDrag.z][posDrag.y - 1][posDrag.x].car != '#') {
						posDrag.y--;
						pile.push(posDrag);
					}
					break;
				case 8:
					if (posDrag.x == 0) {
						if (tab[(NB_DAMIERS - 1) - posDrag.z][(n - 1) - posDrag.y][posDrag.x].car != '#') {
							posDrag.z = (NB_DAMIERS - 1) - posDrag.z;
							posDrag.y = (n - 1) - posDrag.y;
							pile.push(posDrag);
						}
					}
					else if (tab[posDrag.z][posDrag.y - 1][posDrag.x - 1].car != '#') {
						posDrag.x--;
						posDrag.y--;
						pile.push(posDrag);
					}
					break;
				default:
					cerr << "Erreur lors de la recherche de chemin" << endl;
				}
				deplacement.pop();
			}
			affichersp2(tab, m, n);

		}
	}
}
