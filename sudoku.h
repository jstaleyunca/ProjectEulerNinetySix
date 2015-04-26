/* 
 * File:   sudoku.h
 * Author: John
 *
 * Created on March 31, 2015, 3:33 PM
 */

#ifndef SUDOKU_H
#define	SUDOKU_H
#include <array>

using namespace std; 

class sudoku {
public:
    sudoku(int puzzle[9][9]);
    sudoku(const sudoku& orig);
    virtual ~sudoku();
    
    void indexForward(); // moves the current index forward
    void generateCol(int initCol); // fills column array with values from provided column
    void generateRow(int initRow); // fills row array with values from provided row
    // Fills box array with values from box determined by row and col 
    void generateBox(int initRow, int initCol);
    void generatePossible(int initRow, int initCol);
    void solve(int solution); // replaces number in current index with provided number
    
private:
    
    int indexRow; // a number between 0 and 8 that represents the current index's row
    int indexCol; // a number between 0 and 8 that represents the current index's col
    int sudokuGrid[9][9]; // represents the board
    int possible[9]; // possibility array 
    int box[9]; // array that holds the values of a 3x3 box in sudokuGrid
    int column[9]; // array that represents a column in sudokuGrid
    int row[9]; // array that represents a row in sudokuGrid
    
};

#endif	/* SUDOKU_H */

