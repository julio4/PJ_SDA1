#include "dragonGame.h"
#include <iostream>

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
	pile.push(posDrag);
	while (nb < 10) {
		tab[posDrag.z][posDrag.y][posDrag.x].estLu = true;
		tab[posDrag.z][posDrag.y][posDrag.x].car = (char)nb;
		++nb;
		pile.pop(); // dépiler position ( i, j)

		//Mettre à jour chemin connexe

		if (!(posDrag.z == posPDM.z && posDrag.y == posPDM.y && posDrag.x == posPDM.x)) {
			
			//Orientation
			stack<int> deplacement;
			for (int i = 0; i < 8; ++i) {
				
				//case 1:
					if (posDrag.x == 0) {
				
					}

			}

			if (posDrag.y == 0) { // enlever 8, 7, 6
				for (int i = 0; i < 3; ++i) {
					deplacement.pop();
				}
			}
			else {
				
			}

			if (posDrag.x == 0) {
				//CHANGES LES POSITION A LA FIN DE BANDE 2
			}


			switch (deplacement.top()) {
			case 1:
				posDrag.x--;
				break;
			case 2:
				posDrag.x--;
				posDrag.y++;
				break;
			case 3:
				posDrag.y++;
				break;
			case 4:
				posDrag.x++;
				posDrag.y++;
				break;
			case 5:
				posDrag.x++;
				break;
			case 6:
				posDrag.x++;
				posDrag.y--;
				break;
			case 7:
				posDrag.y--;
				break;
			case 8:
				posDrag.x--;
				posDrag.y--;
				break;
			case 9:
				//changement de bande
				break;
			case 10:
				//changement de bande
				break;
			case 11:
				//changement de bande
				break;
			default:
				cerr << "Erreur lors de la recherche de chemin" << endl;
		}

	}
}
