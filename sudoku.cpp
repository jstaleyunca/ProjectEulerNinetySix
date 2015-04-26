/* 
 * File:   sudoku.cpp
 * Author: John
 * 
 * Created on March 31, 2015, 3:33 PM
 */

#include "sudoku.h"

sudoku::sudoku(int puzzle[9][9]) {
    // Initializes starting location
    indexRow = 0; 
    indexCol = 0;
    // initializes sudokuGrid, box, row, column, and possible arrays
    for(int i = 0; i < 9; i++) {
        box[i] = 0;
        row[i] = 0;
        column[i] = 0;
        possible[i] = 0;
        for(int j = 0; j < 9; j++) {
            sudokuGrid[i][j] = puzzle[i][j]; 
        }
    }
}

sudoku::sudoku(const sudoku& orig) {
    // initializes copy board
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            sudokuGrid[i][j] = orig.sudokuGrid[i][j];
        }
    }
}

sudoku::~sudoku() {
}

sudoku::indexForward() { // moves the current index forward
    if(indexCol == 8) {
        indexRow++;
        indexCol = 0;
    } else {
        indexCol++;
    }
}

sudoku::generateCol(int initCol) {
    // fills column array with values from that column of sudokuGrid
    for(int i = 0; i < 9; i++) {
        column[i] = sudokuGrid[i][initCol];
    }
}

sudoku::generateRow(int initRow) {
    // fills row array with values from that row of sudokuGrid
    for(int i = 0; i < 9; i++) {
        row[i] = sudokuGrid[i][initRow];
    }
}

sudoku::generateBox(int initRow, int initCol) {
    /* Box numbers as follows:
    *  0 1 2
    *  3 4 5
    *  6 7 8
    */
    int boxNumber;
    if(initCol < 3) {
        if(initRow < 3) {
            boxNumber = 0;
        } else if (initRow > 2 && initRow < 6) {
            boxNumber = 1;
        } else {
            boxNumber = 2;
        }
    }
    if(initCol > 2 && initCol < 6) {
        if(initRow < 3) {
            boxNumber = 3;
        } else if (initRow > 2 && initRow < 6) {
            boxNumber = 4;
        } else {
            boxNumber = 5;
        }
    }
    if(initCol > 5) {
        if(initRow < 3) {
            boxNumber = 6;
        } else if (initRow > 2 && initRow < 6) {
            boxNumber = 7;
        } else {
            boxNumber = 8;
        }
    }
    switch(boxNumber) {
        case 0: 
            box = {sudokuGrid[0][0], sudokuGrid[0][1], sudokuGrid[0][2], 
                   sudokuGrid[1][0], sudokuGrid[1][1], sudokuGrid[1][2],
                   sudokuGrid[2][0], sudokuGrid[2][1], sudokuGrid[2][2] 
            }; break;
        case 1: 
            box = {sudokuGrid[0][3], sudokuGrid[0][4], sudokuGrid[0][5], 
                   sudokuGrid[1][3], sudokuGrid[1][4], sudokuGrid[1][5],
                   sudokuGrid[2][3], sudokuGrid[2][4], sudokuGrid[2][5] 
            }; break;
        case 2: 
            box = {sudokuGrid[0][6], sudokuGrid[0][7], sudokuGrid[0][8], 
                   sudokuGrid[1][6], sudokuGrid[1][7], sudokuGrid[1][8],
                   sudokuGrid[2][6], sudokuGrid[2][7], sudokuGrid[2][8] 
            }; break;
        case 3: 
            box = {sudokuGrid[3][0], sudokuGrid[3][1], sudokuGrid[3][2], 
                   sudokuGrid[4][0], sudokuGrid[4][1], sudokuGrid[4][2],
                   sudokuGrid[5][0], sudokuGrid[5][1], sudokuGrid[5][2] 
            }; break;
        case 4: 
            box = {sudokuGrid[3][3], sudokuGrid[3][4], sudokuGrid[3][5], 
                   sudokuGrid[4][3], sudokuGrid[4][4], sudokuGrid[4][5],
                   sudokuGrid[5][3], sudokuGrid[5][4], sudokuGrid[5][5] 
            }; break;
        case 5: 
            box = {sudokuGrid[3][6], sudokuGrid[3][7], sudokuGrid[3][8], 
                   sudokuGrid[4][6], sudokuGrid[4][7], sudokuGrid[4][8],
                   sudokuGrid[5][6], sudokuGrid[5][7], sudokuGrid[5][8] 
            }; break;
        case 6: 
            box = {sudokuGrid[6][0], sudokuGrid[6][1], sudokuGrid[6][2], 
                   sudokuGrid[7][0], sudokuGrid[7][1], sudokuGrid[7][2],
                   sudokuGrid[8][0], sudokuGrid[8][1], sudokuGrid[8][2] 
            }; break;
        case 7: 
            box = {sudokuGrid[6][3], sudokuGrid[6][4], sudokuGrid[6][5], 
                   sudokuGrid[7][3], sudokuGrid[7][4], sudokuGrid[7][5],
                   sudokuGrid[8][3], sudokuGrid[8][4], sudokuGrid[8][5] 
            }; break;
        case 8: 
            box = {sudokuGrid[6][6], sudokuGrid[6][7], sudokuGrid[6][8], 
                   sudokuGrid[7][6], sudokuGrid[7][7], sudokuGrid[7][8],
                   sudokuGrid[8][6], sudokuGrid[8][7], sudokuGrid[8][8] 
            }; break;
        default:
            cout << "Box numbers are 0 through 8." << endl;
    }
}

sudoku::solve(int solution) { // replaces current answer with provided answer
    sudokuGrid[indexRow][indexCol] = solution;
}

sudoku::generatePossible(int initRow, int initCol) {
    sudoku.generateBox(initRow, initCol); // generate box of provided index
    sudoku.generateCol(initCol); // generate column of provided index
    sudoku.generateRow(initRow); // generate row of provided index
    for(int i = 0; i < 9; i++) {
        if(box[i] != 0) { // if any of the spaces of the box aren't empty
            possible[box[i] - 1] = 1; // mark the corresponding spot in the possibility array as full
        }
        if(column[i] != 0) { // if any of the spaces of the column aren't empty
            possible[column[i] - 1] = 1; // mark the corresponding spot in the possibility array as full
        }
        if(row[i] != 0) { // if any of the spaces of the row aren't empty
            possible[row[i] - 1] = 1; // mark the corresponding spot in the possibility array as full
        }
    }
}