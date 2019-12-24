/**
 * @file tableauMb.h
 * @brief Permet d'initialiser/d�sallouer en m�moire le tableau 3D avant/apr�s affection du labyrinthe
 * Projet SDA 1
 */
#include "tableauMb.h"

/**
* @brief Initialise un tableau 3D allou�e en m�moire dynamique et r�cup�re sa taille
* @see detruireTab, pour une d�sallocation en fin d'utilisation
* @param[in] in : flux d'entr�e
* @param[in,out] x : taille d'une ligne du labyrinthe
* @param[in,out] y : nombre de lignes du labyrinthe
* @return tab : le tableau 3D d'ItemMb
*/
Case*** initialiserTab(unsigned int& x, unsigned int& y) {

	Case*** tab = new Case**[NB_DAMIERS];
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
		tab[i] = new Case*[y];
		for (unsigned int j = 0; j < y; ++j) {
			tab[i][j] = new Case[x];
		}
	}
	return tab;
}

/**
* @brief D�salloue tab
* @see initialiserTab, pour l'initialisation du tableau
* @param[in,out] tab : tableauMb le tableau 3D
* @param[in,out] x : taille d'une ligne du labyrinthe
* @param[in,out] y : nombre de lignes du labyrinthe
* @pre tab est initialis�
*/
void detruireTab(Lab lab) {
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
		for (unsigned int j = 0; j < lab.lin; ++j) {
			delete[] lab.tab[i][j];
		}
		delete[] lab.tab[i];
	}
	delete[] lab.tab;
	lab.col = 0;
	lab.lin = 0;
}

