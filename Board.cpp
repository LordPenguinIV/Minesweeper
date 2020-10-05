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
			if (!isMine(y, x))
				cout << this->board[y][x].getNumOfAdjMines() << " ";
			else
				cout << "M ";
		}
		cout << endl;
	}
}

void Board::generateMines(unsigned int startY, unsigned int startX) {
	srand((unsigned)time(0));
	unsigned int implementedMines = 0;
	unsigned int randX = rand() % BOARD_WIDTH;
	unsigned int randY = rand() % BOARD_HEIGHT;

	while (implementedMines < NUM_OF_MINES) {
		if ((!this->board[randY][randX].getIsMine()) || (randX != startX && randY != startY)) {
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

bool Board::isMine(unsigned int y, unsigned int x) {
	//Returns false if invalid location
	if (y < 0 || y >= BOARD_HEIGHT || x < 0 || x >= BOARD_WIDTH)
		return false;
	else
		return this->board[y][x].getIsMine();
}

void Board::generateNumMinesAdjacent() {
	unsigned int numOfMines = 0;
	for (unsigned int y = 0; y < BOARD_HEIGHT; y++) {
		for (unsigned int x = 0; x < BOARD_WIDTH; x++) {
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					numOfMines = (this->isMine(y + i, x + j)) ? numOfMines + 1 : numOfMines;
				}
			}
			this->board[y][x].setNumOfAdjMines(numOfMines);
			numOfMines = 0;
		}
	}
	
}