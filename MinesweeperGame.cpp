#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<char>> createMinesBoard(unsigned int x = 10, unsigned int y = 10, unsigned int mines = 33);
vector<vector<char>> createPlayingBoard(vector<vector<char>>);
void displayBoard(vector<vector<char>>);

int main() {
	vector<vector<char>> minesBoard = createMinesBoard(5,5,5);
	vector<vector<char>> playingBoard = createPlayingBoard(minesBoard);
	displayBoard(playingBoard);
}

//Creates a board that stores the locations of all the mines
vector<vector<char>> createMinesBoard(unsigned int x, unsigned int y, unsigned int mines) {

	//Create board of specified size, but with no mines
	vector<vector<char>> board;
	for (unsigned int i = 0; i < y; i++) {
		board.push_back(vector<char>());
		for (unsigned int j = 0; j < x; j++) {
			board[i].push_back('0');
		}
	}
	//Add mines into board
	srand(0);
	unsigned int implementedMines = 0;
	unsigned int randX = rand() % x;
	unsigned int randY = rand() % y;

	while (implementedMines < mines) {
		if (board[randY][randX] == '0') {
			board[randY][randX] = '1';
			implementedMines++;
			randX = rand() % x;
			randY = rand() % y;
		}
		else {
			randX = rand() % x;
			randY = rand() % y;
		}
		
	}

	return board;
}

//Creates board that shows number of surrounding mines
vector<vector<char>> createPlayingBoard(vector<vector<char>> minesBoard) {
	vector<vector<char>> board = minesBoard;
	for (unsigned int i = 0; i < minesBoard.size(); i++) {
		for (unsigned int j = 0; j < minesBoard[i].size(); j++) {
			char numOfMines = '0';
			if (minesBoard[i][j] == '1') {
				board[i][j] = 'M';
			}
			else {
				if (i != 0) {
					if (minesBoard[i - 1][j] == '1') {
						numOfMines++;
					}
					if (j != 0) {
						if (minesBoard[i - 1][j - 1] == '1') {
							numOfMines++;
						}
					}
					if (j != board[i].size() - 1) {
						if (minesBoard[i - 1][j + 1] == '1') {
							numOfMines++;
						}
					}
				}
				if (i != board.size() - 1) {
					if (minesBoard[i + 1][j] == '1') {
						numOfMines++;
					}
					if (j != minesBoard[i].size() - 1) {
						if (minesBoard[i + 1][j + 1] == '1') {
							numOfMines++;
						}
					}
					if (j != 0) {
						if (minesBoard[i + 1][j - 1] == '1') {
							numOfMines++;
						}
					}
				}
				if (j != board[i].size() - 1) {
					if (minesBoard[i][j + 1] == '1') {
						numOfMines++;
					}
				}
				if (j != 0) {
					if (minesBoard[i][j - 1] == '1') {
						numOfMines++;
					}
				}
				board[i][j] = numOfMines;
			}
		}
	}
	return board;
}


//Displays the given board
void displayBoard(vector<vector<char>> board) {
	for (unsigned int i = 0; i < board.size(); i++) {
		for (unsigned int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
}