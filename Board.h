#ifndef BOARD_H
#define BOARD_H

#include "BoardCell.h"
#include <vector>
using namespace std;

class Board {
	private:
		vector<vector<BoardCell>> board;
	public:
		const unsigned int BOARD_HEIGHT;
		const unsigned int BOARD_WIDTH;
		const unsigned int NUM_OF_MINES;

		Board(unsigned int boardY = 10, unsigned int boardX = 10, unsigned int mines = 20);
		void displayBoard();
		void generateMines(unsigned int, unsigned int);
};

#endif // !BOARD_H