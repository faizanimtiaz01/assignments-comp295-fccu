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


void shift(char input) {
    if(input == 'W' || input == 'w'){
        for(int j = 0; j < COLS; j++) {
            for(int i = 0; i < ROWS-1; i++) {
                if(grid[i][j] == 0) {
                int k = i+1;
                while(k < ROWS && grid[k][j] == 0) {
                    k++;
                }
                if(k < ROWS) {
                    grid[i][j] = grid[k][j];
                    grid[k][j] = 0;
                }
            }
        }
    }
    }
    
    else if (input == 'S' || input == 's'){
        for(int j = 0; j < COLS; j++) {
            for(int i = ROWS-1; i > 0; i--) {
                if(grid[i][j] == 0) {
                int k = i-1;
                while(k >= 0 && grid[k][j] == 0) {
                    k--;
                }
                if(k >= 0) {
                grid[i][j] = grid[k][j];
                grid[k][j] = 0;
                    
                }
                    
                }
            }
        }
        
    }
    
    else if (input == 'A' || input == 'a'){
        for(int i = 0; i < ROWS;i++){
            for(int j = 0; j < COLS-1; j++) {
                if(grid[i][j] == 0) {
                int k = j+1;
                while(k < COLS && grid[i][k] == 0) {
                    k++;
                }
                if(k < COLS) {
                grid[i][j] = grid[i][k];
                grid[i][k] = 0;
                }
                
            }
            
        }
            
        }
    }
    else{
        for(int i = 0; i < ROWS; i++) {
            for(int j = COLS-1; j > 0; j--) {
                if(grid[i][j] == 0) {
                int k = j-1;
                while(k >= 0 && grid[i][k] == 0) {
                    k--;
                    
                }
                if(k >= 0) {
                    grid[i][j] = grid[i][k];
                    grid[i][k] = 0;
                    
                }
                
            }
            
        }
        
    }
    }
}

void merge(char input) {
    if(input == 'W' || input == 'w'){
        for(int j = 0; j < COLS; j++) {
            int writeIndex = 0;
        for(int i = 0; i < ROWS; i++) {
            if(grid[i][j] != 0) {
                if(writeIndex > 0 && grid[writeIndex-1][j] == grid[i][j]) {
                    grid[writeIndex-1][j] *= 2;
                    grid[i][j] = 0;
                    
                } else {
                    grid[writeIndex][j] = grid[i][j];
                    if(i != writeIndex) {
                        grid[i][j] = 0;
                        
                    }
                    writeIndex++;
                    
                }
                
            }
            
        }
        
    }
}

        
    else if(input == 'A' || input == 'a'){
        for(int i = 0; i < ROWS; i++) {
            int writeIndex = 0;
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] != 0) {
                    if(writeIndex > 0 && grid[i][writeIndex-1] == grid[i][j]) {
                        grid[i][writeIndex-1] *= 2;
                        grid[i][j] = 0;
                        
                    } else {
                        grid[i][writeIndex] = grid[i][j];
                        if(j != writeIndex) {
                            grid[i][j] = 0;
                            
                        }
                        writeIndex++;
                        
                    }
                    
                }
                
            }
            
        }
        
    }

    