/**
 * @file Item.h
 * @brief Définition des constantes et des types
 * Projet SDA 1
 */
#pragma once

using namespace std;
typedef char ItemMb;

//Constantes

enum { STRING_SIZE = 30, NB_DAMIERS = 2};

void recherche(ItemMb*** tab, int& x, int& y, int& coordx, int& coordy);

struct Position {
	int x, y, z;
};