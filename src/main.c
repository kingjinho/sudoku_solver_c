#include "../include/sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main() {
    int **puzzle = createPuzzle();
    Sudoku *sudoku = setupPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    checkPuzzle(sudoku->squares, sudoku->boxes);
    checkPuzzle(sudoku->squares, sudoku->boxes);

    printf("\n\n");

    printPuzzle(sudoku->squares);


    return 0;
}
