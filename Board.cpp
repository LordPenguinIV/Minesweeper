#include "Board.h"
#include "BoardCell.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

Board::Board(unsigned int boardY, unsigned int boardX, unsigned int mines): BOARD_HEIGHT(boardY), BOARD_WIDTH(boardX), NUM_OF_MINES(mines) {
	for (unsigned int y = 0; y < BOARD_HEIGHT; y++) {
		this->board.push_back(vector<BoardCell>());
		for (unsigned int x = 0; x < BOARD_WIDTH; x++) {
			this->board[y].push_back(BoardCell());
		}
	}
}

void Board::displayBoard() {
	for (unsigned int y = 0; y < BOARD_HEIGHT; y++) {
		for (unsigned int x = 0; x < BOARD_WIDTH; x++) {
			cout << this->board[y][x].getNumOfAdjMines() << "  ";
		}
		cout << endl;
	}
}

void Board::generateMines(unsigned int startY, unsigned int startX) {
	srand(0);
	unsigned int implementedMines = 0;
	unsigned int randX = rand() % BOARD_WIDTH;
	unsigned int randY = rand() % BOARD_HEIGHT;

	while (implementedMines < NUM_OF_MINES) {
		if (!this->board[randY][randX].getIsMine() && (randX != startX && randY != startY)) {
			this->board[randY][randX].setIsMine(true);
			implementedMines++;
			randX = rand() % BOARD_WIDTH;
			randY = rand() % BOARD_HEIGHT;
		}
		else {
			randX = rand() % BOARD_WIDTH;
			randY = rand() % BOARD_HEIGHT;
		}

	}
}