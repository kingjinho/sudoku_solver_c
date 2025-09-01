#include "../include/sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main() {
    int **puzzle = createPuzzle();
    Sudoku *sudoku = setupPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    while (UNSOLVED > 0) {
        int progress = checkPuzzle(sudoku->squares, sudoku->boxes);
        if (progress == 0) {
            printf("Failed to solve the puzzle");
            break;
        }
    }

    printf("\n\n");

    printPuzzle(sudoku->squares);


    return 0;
}
