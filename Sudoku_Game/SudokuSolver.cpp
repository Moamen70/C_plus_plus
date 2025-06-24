#include "SudokuSolver.h"
#include <random>
#include <chrono>



bool SudokuSolver::solveRecursive(int row, int col)
{
    if (row == 9) return true;

    int nextRow = (col == 8) ? row + 1 : row;
    int nextCol = (col + 1) % 9;

    if (this->board.getCell(row,col) != 0) {
       return solveRecursive(nextRow, nextCol);
    }
    for (int val = 1; val <= 9; val++) {
        if (this->board.isValidMove(row, col, val)) {
            this->board.setCell(row, col, val);
            if (solveRecursive(nextRow, nextCol)) {
                return true;
            }
            this->board.setCell(row, col, 0);
        }
    }
    return false;
}


bool SudokuSolver::solve()
{
    return solveRecursive(0, 0);
}



