#include "dragonGame.h"

stack<Position> initialiserDrag(Position& posDrag) {
	stack<Position> pile;
	pile.push(posDrag);
	return pile;
}

void detruireDrag(stack<Position>& pile){
	while (!pile.empty()) {
		pile.pop();
	}
}

void missionDragonSp2(Item*** tab, stack<Position>& pile, Position& posDrag){
	unsigned int n = 0;
	while (pile.size < 10) {
		pile.push(posDrag);
		
	}
}
