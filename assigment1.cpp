// Faizan Imtiaz Cheema
// 241605093
// C++ Assignment 1

#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

int grid[ROWS][COLS];
void placeRandomTile() {
    int rowIndex = rand() % ROWS;
    int colIndex = rand() % COLS;

    if(grid[rowIndex][colIndex] != 0) {
        placeRandomTile();
    }
    else {
        int tileValue = 2 * (rand() % 2 + 1);
        grid[rowIndex][colIndex] = tileValue;
    }
}

void initGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
    placeRandomTile();
    placeRandomTile();
}


void printGrid() {
    cout << endl;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
}


bool isGameOver() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if (grid[i][j] == 2048){
                cout << "Game Won" << endl;
                return true;
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 0) {
                return false;
            }
            if(i < ROWS-1 && grid[i][j] == grid[i+1][j]) {
                return false;
            }
            if(j < COLS-1 && grid[i][j] == grid[i][j+1]) {
                return false;
            }
        }
    }
    return true;
}
