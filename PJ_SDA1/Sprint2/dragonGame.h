#pragma once

#include "indexPositionMb.h"

stack<Position> initialiserDrag(Position& posDrag);

void detruireDrag(stack<Position>& pile);

void missionDragonSp2(Item*** tab, stack<Position>& pile, Position& posDrag, Position& posPDM, unsigned int& m, unsigned int& n);