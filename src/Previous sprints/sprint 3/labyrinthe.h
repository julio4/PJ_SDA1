/**
 * @file labyrinthe.h
 * @brief D�finition structure Lab
 * Projet SDA 1
 */
#pragma once

#include "item.h"
#include "dragon.h"

typedef struct {
	Case*** tab;
	unsigned int col;
	unsigned int lin;
	Position PDM;
} Lab;