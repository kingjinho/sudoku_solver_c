cmake_minimum_required(VERSION 3.31)
project(sudoku_solver C)

set(CMAKE_C_STANDARD 11)

add_executable(sudoku_solver src/main.c
        include/sudoku.h
        src/puzzle.c
        src/square.c
        src/box.c)
