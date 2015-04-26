/* 
 * File:   main.cpp
 * Author: John
 *
 * Created on March 16, 2015, 4:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream file("sudokuTest.txt");
    unsigned char ch = 0;
    int sudokuPuzzle[9][9]; 
    
    // initialize sudoku puzzle
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            sudokuPuzzle[row][col] = 0;
        }
    }
    
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            // read in values
            file >> ch;
            sudokuPuzzle[row][col] = ch - '0'; 
            // print values for testing
            if(col == 8) { 
                cout << sudokuPuzzle[row][col] << endl; 
            } else {
                cout << sudokuPuzzle[row][col];
            }
        }
    }
}