#pragma once
#include <stack>

typedef struct {
	unsigned int z, y, x;
} Position;

typedef struct {
	std::stack<Position> move;
	Position pos;
} Dragon;
