//
// Created by Jinho Shin on 7/30/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/sudoku.h"

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

Square ***setupPuzzle(int **puzzle) {
    Square ***sudoku = malloc(sizeof(Square **) * 9);

    /* loop through rows */
    for (int i = 0; i < SIZE_ROWS; i++) {
        sudoku[i] = (Square **) malloc(sizeof(Square *) * 9);
        /* loop through colums */
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            sudoku[i][j] = (Square *) malloc(sizeof(Square) * 9);

            sudoku[i][j]->number = puzzle[i][j];
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;

            //initialize
            for (int x = 0; x < SIZE_ROWS; x++) {
                sudoku[i][j]->possible[x] = 0;
            }
        }
    }

    for (int i = 0; i < SIZE_ROWS; i++) {
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            if (sudoku[i][j]->number != 0) {
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }

    return sudoku;
}

int checkPuzzle(Square ***sudoku) {
    for (int i = 0; i < SIZE_ROWS; i++) {

        for (int j = 0; j < SIZE_COLUMNS; j++) {
            if (sudoku[i][j]->solvable == 1) {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
            }
        }
    }

    return 1;
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
            printf(" %d ", sudoku[i][j] -> number);
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
