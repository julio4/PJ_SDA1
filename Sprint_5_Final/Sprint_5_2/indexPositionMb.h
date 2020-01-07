/**
 * @file indexPositionMb.h
 * @brief Permet de rechercher les positions initiales du Dragon et des Plans du Monde
 * Projet SDA 1
 */
#pragma once

#include "tableauMb.h"

/**
 * @brief Initialise la position du Dragon et du PDM dans le labyrinthe
 * @see initialiserDrag
 * @param[in-out] lab : le labyrinthe
 * @param[in-out] drag : le dragon
 * @pre tab est initialis�, in est ouvert
 */
void initialiserPos(Lab& lab, Dragon& drag);

/**
 * @brief D�termine si 2 Position sont connexe dans le labyrinthe
 * @param[in] lab : le labyrinthe
 * @param[in] a : premi�re position
 * @param[in] b : deuxi�me position
 * @return true si Connexe, false sinon
 */
bool estConnexe(const Lab& lab, Position a, Position b);