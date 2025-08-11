//
// Created by Jinho Shin on 7/30/25.
//

#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern char POSSIBLE;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Box {
    struct Box *next;
} Box;

typedef struct Square {
    int number;
    /* 000000000
       987654321 */
    char code;
    Box *box;
    int row;
    int column;
} Square;

int **createPuzzle();

void printPuzzle(int **puzzle);

Square ***setupPuzzle(int **puzzle);

#endif
