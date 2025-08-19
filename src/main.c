#include "../include/sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main() {
    int ** puzzle = createPuzzle();
    Square ***sudoku = setupPuzzle(puzzle);

    printPuzzle(sudoku);

    checkPuzzle(sudoku);
    checkPuzzle(sudoku);
    checkPuzzle(sudoku);
    checkPuzzle(sudoku);
    checkPuzzle(sudoku);
    checkPuzzle(sudoku);

    printf("\n\n");

    printPuzzle(sudoku);


    return 0;
}