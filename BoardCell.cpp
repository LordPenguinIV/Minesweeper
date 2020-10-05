#include "BoardCell.h"
using namespace std;

BoardCell::BoardCell(bool isMine, bool isRevealed, unsigned int numOfMines) {
	this->isMine = isMine;
	this->isRevealed = isRevealed;
	this->numOfAdjMines = numOfMines;
}

bool BoardCell::getIsMine() {
	return this->isMine;
}

bool BoardCell::getIsRevealed() {
	return this->isRevealed;
}

unsigned int BoardCell::getNumOfAdjMines() {
	return this->numOfAdjMines;
}

void BoardCell::setIsMine(bool isMine) {
	this->isMine = isMine;
}

void BoardCell::setNumOfAdjMines(unsigned int numOfMines) {
	this->numOfAdjMines = numOfMines;
}

void BoardCell::reveal() {
	this->isRevealed = true;
}