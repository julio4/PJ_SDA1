/**
 * @file labyrintheMb.h
 * @brief Permet d'affecter et de r�initialiser le labyrinthe, et d'afficher le sprint 1
 * Projet SDA 1
 */
#pragma once
#include <iostream>
#include <fstream>

#include "item.h"

/**
* @brief Initialise le labyrinthe dans un tableau 3D
* @see detruireLab, pour r�initialiser le tableau en fin d'utilisation
* @param[in,out] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du tableau
* @param[in] y : nombre de lignes du tableau
* @pre tab est initialis�, in est ouvert
*/
void initialiserLab(ifstream& in, ItemMb*** tab, int& x, int& y);

/**
* @brief R�initialise le tableau 3D � des valeures nulles.
* @see initialiserLab, pour initialiser le labyrinthe dans un tableau 3D
* @param[in,out] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du labyrinthe
* @param[in] y : nombre de lignes du labyrinthe
* @pre tab est initialis�
*/
void detruireLab(ItemMb*** tab, int& x, int& y);

/**
* @brief Affiche la sortie demand�e en Sprint 1 (taille du labyrinthe et les 2 labyrinthes)
* @param[in] tab : tableauMb le tableau 3D
* @param[in] x : taille d'une ligne du labyrinthe
* @param[in] y : nombre de lignes du labyrinthe
* @pre tab est initialis� et affect�
*/
void affichersp1(ItemMb*** tab, int& x, int& y);