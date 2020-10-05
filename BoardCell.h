#ifndef BOARDCELL_H
#define BOARDCELL_H

class BoardCell {
	private:
		bool isMine;
		bool isRevealed;
		unsigned int numOfAdjMines;
	public:
		BoardCell(bool isMine = false, bool isRevealed = false, unsigned int numOfMines = 0);
		bool getIsMine();
		bool getIsRevealed();
		unsigned int getNumOfAdjMines();
		void setIsMine(bool);
		void setNumOfAdjMines(unsigned int);
		void reveal();
};


#endif // !BOARDCELL_H