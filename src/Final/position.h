/**
 * @file position.h
 * @brief D�finition structure Position
 * Projet SDA 1
 */
#pragma once

typedef struct {
	unsigned int z, y, x;	// Trois coordonn�es, x et y pour la position dans le damier
							// et z pour le damier (0 ou 1)
} Position;
