//
// Created by Jinho Shin on 7/30/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/sudoku.h"

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

            if (sudoku[i][j]->number != 0) {
                sudoku[i][j]->code = POSSIBLE;
            } else {
                sudoku[i][j]->code = 0x0;
            }
        }
    }

    return sudoku;
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

void printPuzzle(int **puzzle) {
    printf("------------------------------------\n");
    for (int i = 0; i < SIZE_ROWS; i++) {
        printf("|");

        //print each row
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            printf(" %d ", puzzle[i][j]);
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
