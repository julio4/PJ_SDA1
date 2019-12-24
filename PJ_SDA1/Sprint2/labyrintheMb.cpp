/**
 * @file labyrintheMb.cpp
 * @brief Permet d'affecter et de réinitialiser le labyrinthe, et d'afficher le sprint 1
 * Projet SDA 1
 */
#include "labyrintheMb.h"

/**
* @brief Initialise le labyrinthe dans un tableau 3D
* @see detruireLab, pour réinitialiser le tableau en fin d'utilisation
* @param[in,out] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du tableau
* @param[in] y : nombre de lignes du tableau
* @pre tab est initialisé, in est ouvert
*/
void initialiserLab(ifstream& in, Lab lab) {
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
		//Ecrit tableau[i]
		for (unsigned int j = 0; j < lab.lin; ++j) {
			//Ecrit ligne j
			for (unsigned int l = 0; l < lab.col; ++l) {
				in >> lab.tab[i][j][l].car;
			}
		}
	}
}

/**
* @brief Réinitialise le tableau 3D à des valeures nulles.
* @see initialiserLab, pour initialiser le labyrinthe dans un tableau 3D
* @param[in,out] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du labyrinthe
* @param[in] y : nombre de lignes du labyrinthe
* @pre tab est initialisé
*/
void detruireLab(Lab lab) {
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
		//Supprime tab[i]
		for (unsigned int j = 0; j < lab.lin; ++j) {
			//Supprime ligne j
			for (unsigned int l = 0; l < lab.col; ++l) {
				lab.tab[i][j][l].car = NULL;
				lab.tab[i][j][l].estLu = false;
			}
		}
	}
}

/**
* @brief Affiche la sortie demandée en Sprint 1 (taille du labyrinthe et les 2 labyrinthes)
* @param[in] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du labyrinthe
* @param[in] y : nombre de lignes du labyrinthe
* @pre tab est initialisé et affecté
*/
void affichersp2(Lab lab) {
	cout << lab.col << " " << lab.lin << endl;
	for ( unsigned int i = 0; i < NB_DAMIERS; ++i) {
		//Lire tab[i]
		for (unsigned int j = 0; j < lab.lin; ++j) {
			//Lire ligne j
			for (unsigned int l = 0; l < lab.col; ++l) {
				cout << lab.tab[i][j][l].car;
			}
			cout << endl;
		}
		/* Si pas de saut de lignes après affichage du dernier tableau ( tab[1] )
		if (i < NB_DAMIERS - 1) {
			cout << endl;
		}
		*/
		cout << endl;
	}
}
