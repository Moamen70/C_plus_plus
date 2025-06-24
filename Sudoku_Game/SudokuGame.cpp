#include "SudokuGame.h"

bool SudokuGame::addNum(int row, int col, int value)
{
    return false;
}

void SudokuGame::start()
{
    int preset[9][9] = {
        {0,0,6, 1,0,0, 0,0,0},
        {5,0,0, 0,4,0, 0,0,0},
        {0,2,0, 0,0,9, 7,0,0},
        {8,0,5, 0,0,6, 0,9,0},
        {6,0,0, 0,0,1, 0,0,0},
        {0,0,4, 9,0,2, 0,0,0},
        {0,0,1, 0,0,0, 0,0,0},
        {0,0,0, 8,0,0, 2,7,0},
        {0,0,0, 5,0,0, 6,3,0}
    };
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            solver.getBoard().setCell(i, j, preset[i][j]);
    solver.getBoard().printBoard();
    int choise{ 0 }, row{ 0 }, col{ 0 }, val{ 0 };
    while (choise != 4) {
        std::cout << "1) Enter a move" << std::endl;
        std::cout << "2) Undo last move" << std::endl;
        std::cout << "3) Solve automatically" << std::endl;
        std::cout << "4) Exit" << std::endl;
        std::cin >> choise;
        if (choise == 1) {
            std::cout << "Enter the number of row (1-9):";
            std::cin >> row;
            if (row < 1 || row > 9) {
                std::cout << "Connot add this row number, please use values from (1-9)" << std::endl;
                continue;
            }
            std::cout << "Enter the number of column (1-9):";
            std::cin >> col;
            if (row < 1 || row > 9) {
                std::cout << "Connot add this column number, please use values from (1-9)" << std::endl;
                continue;
            }
            std::cout << "Enter the value:";
            std::cin >> val;
            if (val < 1 || val > 9) {
                std::cout << "Connot add this value please use values from (1-9)" << std::endl;
            }else{
                if (solver.getBoard().isValidMove(row - 1, col - 1, val)) {
                    solver.getBoard().setCell(row - 1, col - 1, val);
                    undoStack.push({ {row - 1,col - 1},val });
                    std::cout << "Value added succsessfully!" << std::endl;
                    solver.getBoard().printBoard();
                    std::cout << "--------------------------------------------------" << std::endl;
                }
                else {
                    std::cout << "Invalid move!" << std::endl;
                    std::cout << "--------------------------------------------------" << std::endl;
                }
            }
        }
        else if (choise == 2) {
            if (!undoStack.empty()) {
                auto lastMove = undoStack.top();
                undoStack.pop();
                solver.getBoard().setCell(lastMove.first.first, lastMove.first.second, 0);
                std::cout << "Last move removed!" << std::endl;
                solver.getBoard().printBoard();
            }else
                std::cout << "There are no moves to undo!" << std::endl;
        }
        else if (choise == 3) {
            if (solver.solve()) {
                solver.getBoard().printBoard();
                break;
            }
            else {
                std::cout << "The game cannot solved!" << std::endl;
            }
        }
        else if (choise == 4) {
            std::cout << "The end of the game!" << std::endl;
            break;
        }
        else {
            std::cout << "Please Enter a valid choise!" << std::endl;
            std::cout << "-----------------------------------------------" << std::endl;
            continue;
        }       
    }
}
