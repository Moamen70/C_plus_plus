#include "SudokuBoard.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>

SudokuBoard::SudokuBoard(int filledCells) {
    board = std::vector<std::vector<int>>(SIZE, std::vector<int>(SIZE, 0));
    //generateRandomBoard(filledCells);
}

int SudokuBoard::getCell(int row, int col) const {
    return board[row][col];
}

void SudokuBoard::setCell(int row, int col, int value) {
    board[row][col] = value;
}

bool SudokuBoard::isValidMove(int row, int col, int value) const {
    if (value < 1 || value > 9 || row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return false;
    if (board[row][col] != 0)
        return false;
    return !isInRow(row, value) && !isInCol(col, value) && !isInBox(row - row % 3, col - col % 3, value);
}

bool SudokuBoard::isInRow(int row, int value) const {
    for (int col = 0; col < SIZE; ++col) {
        if (board[row][col] == value)
            return true;
    }
    return false;
}

bool SudokuBoard::isInCol(int col, int value) const {
    for (int row = 0; row < SIZE; ++row) {
        if (board[row][col] == value)
            return true;
    }
    return false;
}

bool SudokuBoard::isInBox(int startRow, int startCol, int value) const {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board[startRow + r][startCol + c] == value)
                return true;
        }
    }
    return false;
}

void SudokuBoard::printBoard() const {
    std::cout << "-------------------------\n";
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (col % 3 == 0 && col != 0)
                std::cout << "| ";

            if (board[row][col] == 0)
                std::cout << ". ";
            else
                std::cout << board[row][col] << " ";
        }
        std::cout << "\n";
        if ((row + 1) % 3 == 0 && row != 8)
            std::cout << "-------------------------\n";
    }
    std::cout << "-------------------------\n";
}

void SudokuBoard::generateRandomBoard(int filledCells) {
    for (auto& row : board)
        std::fill(row.begin(), row.end(), 0);

    std::mt19937 gen(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<> distRow(0, SIZE - 1);
    std::uniform_int_distribution<> distCol(0, SIZE - 1);
    std::uniform_int_distribution<> distVal(1, 9);

    int placed = 0, attempts = 0;
    const int maxAttempts = 1000;

    while (placed < filledCells && attempts < maxAttempts) {
        int row = distRow(gen);
        int col = distCol(gen);
        if (board[row][col] != 0) {
            ++attempts;
            continue;
        }

        int val = distVal(gen);
        if (isValidMove(row, col, val)) {
            board[row][col] = val;
            ++placed;
        }

        ++attempts;
    }
}
