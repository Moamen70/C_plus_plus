#pragma once
#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

#include <vector>

class SudokuBoard {
public:
    static const int SIZE = 9;

    SudokuBoard(int filledCells = 35);

    // Accessors
    int getCell(int row, int col) const;
    void setCell(int row, int col, int value);

    // Validation
    bool isValidMove(int row, int col, int value) const;

    // Board display
    void printBoard() const;

    // Generate random valid (non-conflicting) cells for testing
    void generateRandomBoard(int filledCells);

private:
    std::vector<std::vector<int>> board;

    // Helpers
    bool isInRow(int row, int value) const;
    bool isInCol(int col, int value) const;
    bool isInBox(int startRow, int startCol, int value) const;
};

#endif 