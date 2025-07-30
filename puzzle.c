//
// Created by Jinho Shin on 7/30/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

int ** createPuzzle() {
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

    for (int i = 0; i < 9; i++) {
        puzzle[i] = (int *) malloc(sizeof(int) * 9);

        for (int j = 0; j < 9; j++) {
            puzzle[i][j] = array[i][j];
        }

    }
    return puzzle;
}

void printPuzzle(int ** puzzle) {

    for (int i = 0; i < 9; i++) {
        //print each row
        for (int j = 0; j < 9; j++) {
            printf(" %d ", puzzle[i][j]);
            if (j % 3 == 2 && j != 8) {
                printf("\t");
            }
        }
        printf("\n");
        if (i % 3 == 2 && i != 8) {
            printf("\n");
        }
    }
}