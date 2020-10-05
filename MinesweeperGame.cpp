#include <iostream>
#include <vector>
#include <iomanip>
#include "Board.h"
#include "BoardCell.h"
using namespace std;

vector<vector<char>> createPlayingBoard(vector<vector<char>>);

int main() {
	//Gets user input for board height, width, and number of mines
	unsigned int temp;
	cout << "Enter board height: ";
	cin >> temp;
	const unsigned int BOARD_HEIGHT = temp;
	cout << "Enter board width: ";
	cin >> temp;
	const unsigned int BOARD_WIDTH = temp;
	cout << "Enter number of mines: ";
	cin >> temp;
	const unsigned int NUMBER_OF_MINES = temp;
	unsigned int x, y;

	cout << "Enter location as \"x y\": ";
	cin >> x >> y;

	Board board = Board(BOARD_HEIGHT, BOARD_WIDTH, NUMBER_OF_MINES);
	board.displayBoard();
	cout << endl;
	board.generateMines(y, x);
	board.displayBoard();
	cout << endl;
	board.generateNumMinesAdjacent();
	board.displayBoard();
}