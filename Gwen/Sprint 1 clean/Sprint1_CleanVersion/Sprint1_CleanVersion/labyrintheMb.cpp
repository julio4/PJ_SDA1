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
void initialiserLab(ifstream& in, ItemMb*** tab, int& x, int& y) {
	ItemMb item;
	for (int i = 0; i < NB_DAMIERS; ++i) {
		//Ecrit tableau[i]
		for (int j = 0; j < y; ++j) {
			//Ecrit ligne j
			for (int l = 0; l < x; ++l) {
				in >> item;
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
void detruireLab(ItemMb*** tab, int& x, int& y) {
	for (int i = 0; i < NB_DAMIERS; ++i) {
		//Supprime tab[i]
		for (int j = 0; j < y; ++j) {
			//Supprime ligne j
			for (int l = 0; l < x; ++l) {
				tab[i][j][l] = NULL;
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
void affichersp1(ItemMb*** tab, int& x, int& y) {

	ofstream iwrite;
	iwrite.open(file_out, ofstream::out | ofstream::trunc);

	iwrite << x << " " << y << endl;
	for (int i = 0; i < NB_DAMIERS; ++i) {
		//Lire tab[i]
		for (int j = 0; j < y; ++j) {
			//Lire ligne j
			for (int l = 0; l < x; ++l) {
				iwrite << tab[i][j][l];
			}
			iwrite << endl;
		}
		/* Si pas de saut de lignes apr�s affichage du dernier tableau ( tab[1] )
		if (i < NB_DAMIERS - 1) {
			iwrite << endl;
		}
		*/
		iwrite << endl;
	}

	iwrite.close();
}
