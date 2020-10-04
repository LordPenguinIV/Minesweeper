#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<char>> createBlankBoard(unsigned int x = 10, unsigned int y = 10);
vector<vector<char>> createMinesBoard(unsigned int x = 10, unsigned int y = 10, unsigned int mines = 20);
vector<vector<char>> createPlayingBoard(vector<vector<char>>);
void displayBoard(vector<vector<char>>);

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

	vector<vector<char>> minesBoard = createMinesBoard(BOARD_HEIGHT, BOARD_WIDTH, NUMBER_OF_MINES);
	vector<vector<char>> playingBoard = createPlayingBoard(minesBoard);
	displayBoard(playingBoard);
}

//Creates a board that stores the locations of all the mines
vector<vector<char>> createMinesBoard(unsigned int y, unsigned int x, unsigned int mines) {
	vector<vector<char>> board = createBlankBoard(y , x);
	
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

//Creates board that shows number of surrounding mines for every square
vector<vector<char>> createPlayingBoard(vector<vector<char>> minesBoard) {

	vector<vector<char>> board = createBlankBoard(minesBoard.size(), minesBoard[0].size());

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

//Displays the given board
void displayBoard(vector<vector<char>> board) {
	for (unsigned int y = 0; y < board.size(); y++) {
		for (unsigned int x = 0; x < board[y].size(); x++) {
			cout << board[y][x] << "  ";
		}
		cout << endl;
	}
}

//Creates a blank board
vector<vector<char>> createBlankBoard(unsigned int x, unsigned int y) {
	vector<vector<char>> board;
	for (unsigned int i = 0; i < y; i++) {
		board.push_back(vector<char>());
		for (unsigned int j = 0; j < x; j++) {
			board[i].push_back('0');
		}
	}
	return board;
}