/**
 * @file labyrintheMb.cpp
 * @brief Permet d'affecter et de r�initialiser le labyrinthe, et d'afficher le sprint 1
 * Projet SDA 1
 */
#include "labyrintheMb.h"

/**
* @brief Initialise le labyrinthe dans un tableau 3D
* @see detruireLab, pour r�initialiser le tableau en fin d'utilisation
* @param[in,out] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du tableau
* @param[in] y : nombre de lignes du tableau
* @pre tab est initialis�, in est ouvert
*/
void initialiserLab(ifstream& in, Item*** tab, unsigned int& x, unsigned int& y) {
	Item item;
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
		//Ecrit tableau[i]
		for (unsigned int j = 0; j < y; ++j) {
			//Ecrit ligne j
			for (unsigned int l = 0; l < x; ++l) {
				in >> item.car;
				tab[i][j][l] = item;
			}
		}
	}
}

/**
* @brief R�initialise le tableau 3D � des valeures nulles.
* @see initialiserLab, pour initialiser le labyrinthe dans un tableau 3D
* @param[in,out] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du labyrinthe
* @param[in] y : nombre de lignes du labyrinthe
* @pre tab est initialis�
*/
void detruireLab(Item*** tab, unsigned int& x, unsigned int& y) {
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
		//Supprime tab[i]
		for (unsigned int j = 0; j < y; ++j) {
			//Supprime ligne j
			for (unsigned int l = 0; l < x; ++l) {
				tab[i][j][l].car = NULL;
				tab[i][j][l].estLu = false;
			}
		}
	}
}

/**
* @brief Affiche la sortie demand�e en Sprint 1 (taille du labyrinthe et les 2 labyrinthes)
* @param[in] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du labyrinthe
* @param[in] y : nombre de lignes du labyrinthe
* @pre tab est initialis� et affect�
*/
void affichersp2(Item*** tab, unsigned int& x, unsigned int& y) {
	cout << x << " " << y << endl;
	for (int i = 0; i < NB_DAMIERS; ++i) {
		//Lire tab[i]
		for (int j = 0; j < y; ++j) {
			//Lire ligne j
			for (int l = 0; l < x; ++l) {
				cout << tab[i][j][l].car;
			}
			cout << endl;
		}
		/* Si pas de saut de lignes apr�s affichage du dernier tableau ( tab[1] )
		if (i < NB_DAMIERS - 1) {
			cout << endl;
		}
		*/
		cout << endl;
	}
}
