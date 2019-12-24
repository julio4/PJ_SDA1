/**
 * @file Item.h
 * @brief Définition des constantes et des types
 * Projet SDA 1
 */
#pragma once

#include "case.h"

typedef Case Item;

typedef struct {
	Case*** tab;
	unsigned int col;
	unsigned int lin;
	Position PDM;
} Lab;