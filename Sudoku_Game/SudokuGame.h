#pragma once
#include "SudokuBoard.h"
#include "SudokuSolver.h"
#include <stack>
#include <utility>
#include <iostream>
class SudokuGame
{
private:
	SudokuSolver solver;
	std::stack<std::pair<std::pair<int, int>, int>> undoStack;
public:
	SudokuGame( SudokuSolver& s) : solver(s) {};
	bool addNum(int row, int col, int value);
	void start();
};

