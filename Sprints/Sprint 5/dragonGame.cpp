/**
 * @file dragonGame.cpp
 * @brief Initialisation du Dragon et recherche du PDM dans le labyrinthe
 * Projet SDA 1
 */
#include "dragonGame.h"

/**
 * @brief Initialise le dragon dans une structure Dragon
 * @see detruireDrag, pour r�initialiser les positions du dragon en fin d'utilisation
 * @param[in] lab : le labyrinthe
 * @return Dragon
 */
Dragon initialiserDrag(Lab& lab) {
	Dragon drag;
	initialiserPos(lab, drag);
	return drag;
}

/**
 * @brief R�initialise � z�ro les position du dragon
 * @see initialiserDrag, pour initialiser les positions du Dragon
 * @param[in-out] drag : le dragon
 * @pre drag est initialis�
 */
void detruireDrag(Dragon& drag){
	drag.pos.z = 0;
	drag.pos.y = 0;
	drag.pos.x = 0;
}

/**
 * @brief Execute le sprint 5 et l'affiche
 * @see initialiserDrag, initialiserTab, initialiserLab, affichersp5
 * @param[in-out] lab : le labyrinthe
 * @param[in-out] drag : le dragon
 * @pre Lab est initialis�, drag est initialis�
 */
void missionDragonSp5(Lab& lab, Dragon& drag) {
	stack<Position> pile;
	stack<Position> filAriane;
	filAriane.push(drag.pos);
	pile.push(drag.pos);

	while (!(filAriane.top().z == lab.PDM.z && filAriane.top().y == lab.PDM.y && filAriane.top().x == lab.PDM.x) && !pile.empty()) {
		drag.pos = pile.top();
		pile.pop();

		while (!filAriane.empty() && (!estConnexe(lab, filAriane.top(), drag.pos))) {
			filAriane.pop();
		}
		filAriane.push(drag.pos);

		if (!(drag.pos.z == lab.PDM.z && drag.pos.y == lab.PDM.y && drag.pos.x == lab.PDM.x)) {
			//push dans pile positions possibles de pos(i, j) de 1 � 8

			//Recherche et mouvement
			Position mouv = drag.pos;
			for (unsigned int i = 1; i <= 8; ++i) {
				mouv = drag.pos;
				switch (i) {
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
					if (drag.pos.y != (lab.lin - 1)) {
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
					}
					break;
				case 3:
					if (drag.pos.y != (lab.lin - 1) && lab.tab[drag.pos.z][drag.pos.y + 1][drag.pos.x].car != '#') {
						mouv.y++;
					}
					break;
				case 4:
					if (drag.pos.y != (lab.lin - 1)) {
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
					if (drag.pos.y != 0) {
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
					}
					break;
				case 7:
					if (drag.pos.y != 0 && lab.tab[drag.pos.z][drag.pos.y - 1][drag.pos.x].car != '#') {
						mouv.y--;
					}
					break;
				case 8:
					if (drag.pos.y != 0) {
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
					}
					break;
				default:
					cerr << "Erreur lors de la recherche de chemin" << endl;
				}
				if (!(mouv.z == drag.pos.z && mouv.y == drag.pos.y && mouv.x == drag.pos.x) 
					&& lab.tab[mouv.z][mouv.y][mouv.x].estLu == false) {
					pile.push(mouv);
				}
			}
			lab.tab[drag.pos.z][drag.pos.y][drag.pos.x].estLu = true;
		}
	}

	if (filAriane.top().z == lab.PDM.z && filAriane.top().y == lab.PDM.y && filAriane.top().x == lab.PDM.x) {
		cout << "Trouv�" << endl;
		unsigned int size = filAriane.size();
		stack<Position> chemin;
		chemin = filAriane;
		for (unsigned int i = 0; i < size; ++i) {
			lab.tab[filAriane.top().z][filAriane.top().y][filAriane.top().x].car = 'C';
			filAriane.pop();
		}
		affichersp5(lab, chemin);
	}
	else {
		cout << "Non trouv�" << endl;
		affichersp5(lab, filAriane);
	}
}
