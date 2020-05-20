/**
 * @file labyrintheMb.h
 * @brief Permet d'initialiser et de r�initialiser le labyrinthe, et d'afficher le sprint 3
 * Projet SDA 1
 */
#pragma once

#include "header.h"

/**
 * @brief Initialise le labyrinthe dans un tableau 3D
 * @see detruireLab, pour r�initialiser le tableau en fin d'utilisation
 * @param[in] in : le flux d'entr�e afin d'initialiser le labyrinthe
 * @param[in-out] lab : le labyrinthe � initialiser
 * @pre tab est initialis�, in est ouvert
 */
void initialiserLab(ifstream& in, Lab& lab);

/**
 * @brief R�initialise le tableau 3D � des valeures nulles.
 * @see initialiserLab, pour initialiser le labyrinthe dans un tableau 3D
 * @param[in,out] lab : Labyrinthe contenant le tableau 3D et ses dimensions
 * @pre lab(.tab, .col, .lin) est initialis�
 */
void detruireLab(Lab& lab);

/**
 * @brief Affiche le Sprint 3
 * @see missionDragonSp2, afin d'effectuer le sprint 3 et provoquer son affichage par l'appel de cette fonction
 * @param[in] lab : Labyrinthe contenant le tableau 3D et ses dimensions
 * @pre lab(.tab, .col, .lin) est initialis�
 */
void affichersp3(Lab& lab);