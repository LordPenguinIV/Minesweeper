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

	Board board = Board(BOARD_HEIGHT, BOARD_WIDTH, NUMBER_OF_MINES);
	board.displayBoard();
}

//Creates board that shows number of surrounding mines for every square
vector<vector<char>> createPlayingBoard(vector<vector<char>> minesBoard) {

	vector<vector<char>> board;
	for (unsigned int i = 0; i < minesBoard.size(); i++) {
		board.push_back(vector<char>());
		for (unsigned int j = 0; j < minesBoard[i].size(); j++) {
			board[i].push_back('0');
		}
	}

	for (unsigned int y = 0; y < minesBoard.size(); y++) {
		for (unsigned int x = 0; x < minesBoard[y].size(); x++) {
			char numOfMines = '0';
			if (minesBoard[y][x] == '1') {
				board[y][x] = 'M';
			}
			else {
				if (y != 0) {
					if (minesBoard[y - 1][x] == '1') {
						numOfMines++;
					}
					if (x != 0) {
						if (minesBoard[y - 1][x - 1] == '1') {
							numOfMines++;
						}
					}
					if (x != board[y].size() - 1) {
						if (minesBoard[y - 1][x + 1] == '1') {
							numOfMines++;
						}
					}
				}
				if (y != board.size() - 1) {
					if (minesBoard[y + 1][x] == '1') {
						numOfMines++;
					}
					if (x != minesBoard[y].size() - 1) {
						if (minesBoard[y + 1][x + 1] == '1') {
							numOfMines++;
						}
					}
					if (x != 0) {
						if (minesBoard[y + 1][x - 1] == '1') {
							numOfMines++;
						}
					}
				}
				if (x != board[y].size() - 1) {
					if (minesBoard[y][x + 1] == '1') {
						numOfMines++;
					}
				}
				if (x != 0) {
					if (minesBoard[y][x - 1] == '1') {
						numOfMines++;
					}
				}
				board[y][x] = numOfMines;
			}
		}
	}
	return board;
}
