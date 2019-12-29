/**
 * @file tableauMb.h
 * @brief Permet d'initialiser/d�sallouer en m�moire le tableau 3D avant/apr�s affection du labyrinthe
 * Projet SDA 1
 */
#include "tableauMb.h"

/**
 * @brief Initialise le tableau 3D lab.tab allou�e en m�moire dynamique
 * @see detruireTab, pour une d�sallocation en fin d'utilisation
 * @param[in,out] lab : structure lab, contenant la dimension du labyrinthe et le tableau 3D associ�
 */
void initialiserTab(Lab& lab) {
	lab.tab = new Case**[NB_DAMIERS];
	for (unsigned int i = 0; i < NB_DAMIERS; ++i) {
		lab.tab[i] = new Case*[lab.lin];
		for (unsigned int j = 0; j < lab.lin; ++j) {
			lab.tab[i][j] = new Case[lab.col];
		}
	}
}

/**
 * @brief D�salloue lab.tab
 * @see initialiserTab, pour l'initialisation du tableau
 * @param[in,out] lab : structure lab, contenant la dimension du labyrinthe et le tableau 3D associ�
 * @pre lab.tab est initialis�
 */
void detruireTab(Lab& lab) {
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

