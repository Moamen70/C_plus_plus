#pragma once
#include "SudokuBoard.h"
class SudokuSolver
{
private:
	//std::vector<std::vector<int>> currentBoard;
	SudokuBoard& board;
	bool solveRecursive(int row, int col);
public:
	SudokuSolver(SudokuBoard& b) : board(b) {};
	bool solve();
	SudokuBoard& getBoard()const {
		return this->board;
	}
};

