//
// Created by Jinho Shin on 7/30/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/sudoku.h"

Sudoku *createSudoku(Square ***squares, Box **boxes) {
    Sudoku *sudoku = malloc(sizeof(Sudoku));

    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;
}

int updateSudoku(Square ***sudoku, int row, int column) {
    int number = sudoku[row][column]->number;

    for (int x = 0; x < SIZE_ROWS; x++) {
        if (sudoku[x][column]->possible[number - 1] == 0) {
            sudoku[x][column]->solvable--;
        }
        sudoku[x][column]->possible[number - 1] = 1;
    }

    for (int x = 0; x < SIZE_ROWS; x++) {
        if (sudoku[row][x]->possible[number - 1] == 0) {
            sudoku[row][x]->solvable--;
        }
        sudoku[row][x]->possible[number - 1] = 1;
    }

    return 1;
}

Sudoku *setupPuzzle(int **puzzle) {
    Square ***sudoku = malloc(sizeof(Square **) * 9);
    Box **boxes = createBoxes();
    int currentBox = 0;

    /* loop through rows */
    for (int i = 0; i < SIZE_ROWS; i++) {
        sudoku[i] = (Square **) malloc(sizeof(Square *) * 9);
        /* loop through columns */
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            sudoku[i][j] = (Square *) malloc(sizeof(Square) * 9);

            sudoku[i][j]->number = puzzle[i][j];
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            sudoku[i][j]->solvable = 9;

            boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            //initialize
            for (int x = 0; x < SIZE_ROWS; x++) {
                sudoku[i][j]->possible[x] = 0;
            }

            if (j == 2 || j == 5) {
                currentBox++;
            }
        }
        currentBox -= 2;

        if (i == 2) {
            currentBox = 3;
        }

        if (i == 5) {
            currentBox = 6;
        }
    }

    for (int i = 0; i < SIZE_ROWS; i++) {
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            if (sudoku[i][j]->number != 0) {
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }

    return createSudoku(sudoku, boxes);
}

int checkPuzzle(Square ***sudoku, Box **boxes) {
    for (int i = 0; i < SIZE_ROWS; i++) {
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            if (sudoku[i][j]->solvable == 1) {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);

                return 1;
            }
        }
    }

    return boxSingles(sudoku, boxes);
}

int **createPuzzle() {
    int **puzzle;
    int array[9][9] = {
        9, 0, 2, 7, 3, 0, 4, 0, 0,
        0, 8, 0, 0, 4, 9, 0, 0, 0,
        3, 7, 0, 0, 5, 1, 9, 2, 0,

        0, 0, 0, 0, 0, 0, 0, 5, 7,
        2, 1, 0, 0, 0, 0, 3, 9, 6,
        0, 0, 0, 9, 1, 0, 0, 8, 0,

        5, 3, 1, 0, 0, 0, 0, 7, 2,
        6, 4, 0, 5, 0, 0, 8, 3, 0,
        0, 0, 7, 0, 0, 3, 5, 4, 0
    };

    puzzle = (int **) malloc(sizeof(int *) * 9);

    for (int i = 0; i < SIZE_ROWS; i++) {
        puzzle[i] = (int *) malloc(sizeof(int) * 9);

        for (int j = 0; j < SIZE_COLUMNS; j++) {
            puzzle[i][j] = array[i][j];
        }
    }
    return puzzle;
}

void printPuzzle(Square ***sudoku) {
    printf("------------------------------------\n");
    for (int i = 0; i < SIZE_ROWS; i++) {
        printf("|");

        //print each row
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            printf(" %d ", sudoku[i][j]->number);
            if (j % 3 == 2) {
                printf(" | ");
            }
        }

        printf("\n");

        if (i % 3 == 2 && i != 8) {
            printf("------------------------------------\n");
        }
    }
    printf("------------------------------------\n");
}
