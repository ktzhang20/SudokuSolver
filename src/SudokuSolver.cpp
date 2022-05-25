#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
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

void printSudoku(int grid[9][9]){
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

void createSudoku(int grid[9][9]){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    unsigned num = chrono::system_clock::now().time_since_epoch().count();
    shuffle(arr.begin(), arr.end(), default_random_engine(num)); 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int k = rand() % arr.size();
            grid[i][j] = arr.at(k);
            arr.erase(arr.begin()+k);

        }
    }
    arr = {1,2,3,4,5,6,7,8,9};
    for(int i = 3; i < 6; i++){
        for(int j = 3; j < 6; j++){
            int k = rand() % arr.size();
            grid[i][j] = arr.at(k);
            arr.erase(arr.begin()+k);

        }
    }
    arr = {1,2,3,4,5,6,7,8,9};
    for(int i = 6; i < 9; i++){
        for(int j = 6; j < 9; j++){
            int k = rand() % arr.size();
            grid[i][j] = arr.at(k);
            arr.erase(arr.begin()+k);

        }
    }
}

void addBlanks(int grid[9][9], int difficulty){
    int zeroes[9] = {0,0,0,0,0,0,0,0,0};
    int diff = difficulty;
    while(difficulty > 0){
        int i = rand() % 9;
        int j = rand() % 9;
        if(grid[i][j] != 0 && zeroes[grid[i][j]] < ceil(diff/6)){
            zeroes[grid[i][j]]++;
            grid[i][j] = 0;
            difficulty--;
        }
    }
}





int main(){
    int i = 1;
    while(i == 1){
        srand(time(NULL));
        int grid[9][9] = {{0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0}};
        createSudoku(grid);
        if(SudokuSolver(grid)){       
            int arr[5]= {20,30,40,50,60}; 
            cout << "Choose your difficulty: 0-4 from easy to hard" << endl;
            int difficulty = 0;
            cin >> difficulty;
            difficulty = arr[difficulty];
            addBlanks(grid, difficulty);
            printSudoku(grid);
        }
        else{
            cout << "not a valid sudoku" << endl;
        }
        cout << "Would you like to play again? 1 for yes and 0 for no." << endl;
        cin >> i;
    }
}
/*
    Difficulty Scale:
        0 Easiest - 61 squares filled in
        1 Easy    - 51 squares filled in
        2 Medium  - 41 squares filled in
        3 Hard    - 31 squares filled in
        4 Hardest - 21 squares filled in
    Should I regulate how many squares are filled in to make it more fair? 
        As in if I have 20 squares filled in and 9 numbers, should I make it so each number has at least 2?
        Let's make it more fair:
            Have an array of length 9. Increment the index if we remove a number.
                If the index has 3 or greater, skip that index.
                repeat until x number of squares filled in: given in input.
*/