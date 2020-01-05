/**
 * @file tableauMb.h
 * @brief Permet d'initialiser/d�sallouer en m�moire le tableau 3D avant/apr�s affection du labyrinthe
 * Projet SDA 1
 */
#pragma once

#include "labyrintheMb.h"

/**
 * @brief Initialise le tableau 3D lab.tab allou�e en m�moire dynamique
 * @see detruireTab, pour une d�sallocation en fin d'utilisation
 * @param[in,out] lab : structure lab, contenant la dimension du labyrinthe et le tableau 3D associ�
 */
void initialiserTab(Lab& lab);

/**
 * @brief D�salloue lab.tab
 * @see initialiserTab, pour l'initialisation du tableau
 * @param[in,out] lab : structure lab, contenant la dimension du labyrinthe et le tableau 3D associ�
 * @pre lab.tab est initialis�
 */
void detruireTab(Lab& lab);