#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;

bool EmptyBoxes(int grid[9][9], int& row, int& col);

bool isValid(int grid[9][9], int row, int col, int num);

bool SudokuSolver(int grid[9][9]){
    int row, col;
    if(!EmptyBoxes(grid, row, col)){
        return true;
    }
    for(int i = 1; i < 10; i++){
        if(isValid(grid, row, col, i)){
            grid[row][col] = i;
            if(SudokuSolver(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;


}
// to find where the row and col begins, we know that the left hand positions of each box are:
// (0,0) (3,0) (6,0)
// (0,3) (3,3) (6,3)
// (0,6) (3,6) (6,6)
// therefore, if say I have (2,8), that would be in the 0,6 box: therefore I would do row - row % 3 (if I had like 4, then that would equal 3). for col it would be col - col % 3
bool inBox(int grid[9][9], int row, int col, int num){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i+row][j+col] == num){
                return true;
            }
        }
    }
    return false;
    
}

bool inRow(int grid[9][9],int row, int num){
    for(int col = 0; col < 9; col++){
        if(grid[row][col] == num){
            return true;
        }
    }
    return false;
}

bool inCol(int grid[9][9], int col, int num){
    for(int row = 0; row < 9; row++){
        if(grid[row][col] == num){
            return true;
        }
    }
    return false;
}


// create hash map of row and col
// if there's a duplicate in either row and col, return false
// otherwise return true;
bool isValid(int grid[9][9], int row, int col, int num){ 
    return (!inBox(grid, row - row%3, col - col%3, num) &&
            !inRow(grid, row, num) &&
            !inCol(grid, col, num) &&
            grid[row][col] == 0);
}



bool EmptyBoxes(int grid[9][9], int&row, int& col){
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(grid[row][col] == 0){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int grid[9][9] = {{4,0,9,2,7,0,0,0,0},
                      {0,0,0,4,0,0,0,3,0},
                      {0,1,6,0,8,0,0,0,7},
                      {0,0,0,6,0,9,0,2,0},
                      {8,0,4,5,0,1,7,6,3},
                      {2,6,5,7,0,8,4,0,9},
                      {1,0,0,0,6,0,0,0,0},
                      {0,4,2,0,0,0,3,8,0},
                      {0,0,0,8,0,0,1,0,4}};
    if(SudokuSolver(grid)){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 8; j++){
                cout << grid[i][j]<< " | ";
            }
            cout << grid[i][8];
            cout << endl;
            for(int j = 0; j < 7; j++){
                cout << "-----";
            }
            cout << endl;
        }
    }
    else{
        cout << "not a valid sudoku" << endl;
    }
}

/*
    how should I create my own sudokus?
    Do I do the method where you create a solved sudoku puzzle (essentially same logic as solving one, u just put random numbers until it becomes solved)


*/