import random
import time
import math
import numpy



def EmptyBoxes(grid, row, col):
    for row in range(0, 9):
        for col in range (0, 9):
            if grid[row][col] == 0:
                return True
    return False

def inBox(grid, row, col, num):
    for i in range(0,3):
        for j in range(0,3):
            if(grid[row+i][col+j] == num):
                return True
    return False            


def inRow(grid, row, num):
    for col in range(0,9):
        if grid[row][col] == num:
            return True
    return False

def inCol(grid, col, num):
    for row in range(0,9):
        if grid[row][col] == num:
            return True
    return False






def isValid(grid,row,col,num):
    return not inBox(grid, row - row%3, col - col%3, num) and not inRow(grid, row ,num) and not inCol(grid, col, num) and grid[row][col] == 0
           

def SudokuSolver(grid):
    row,col = 0,0
    for row in range(0, 9):
        for col in range (0, 9):
            if grid[row][col] == 0:
                break
        if grid[row][col] == 0:
            break
    if(row == 8 and col == 8 and grid[row][col] != 0):
        return True

    for i in range(1,10):
        if isValid(grid,row,col,i):
            grid[row][col] = i
            if SudokuSolver(grid):
                return True
            grid[row][col] = 0
    return False

def createSudoku(grid):
    arr = [1,2,3,4,5,6,7,8,9]
    random.shuffle(arr)
    for i in range(0,3):
        for j in range(0,3):
            k = random.randint(0, len(arr)-1)
            grid[i][j] = arr[k]
            arr.remove(arr[k])
    arr = [1,2,3,4,5,6,7,8,9]
    random.shuffle(arr)
    for i in range(3,6):
        for j in range(3,6):
            k = random.randint(0, len(arr)-1)
            grid[i][j] = arr[k]
            arr.remove(arr[k])
    arr = [1,2,3,4,5,6,7,8,9]
    random.shuffle(arr)
    for i in range(6,9):
        for j in range(6,9):
            k = random.randint(0, len(arr)-1)
            grid[i][j] = arr[k]
            arr.remove(arr[k])
    
def addBlanks(grid, difficulty):
    zeroes = [0,0,0,0,0,0,0,0,0,0]
    diff = difficulty
    while(difficulty > 0):
        i = random.randint(0,8)
        j = random.randint(0,8)
        if grid[i][j] != 0 and zeroes[grid[i][j]] < math.ceil(diff/6):
            zeroes[grid[i][j]] += 1
            grid[i][j] = 0
            difficulty -= 1

def printSudoku(grid):
    print(numpy.matrix(grid))


i = 1
while i == 1:
    random.seed(time.time())
    rows,cols = (9,9)
    grid = numpy.zeros((9,9))
    grid = grid.astype(int)
    createSudoku(grid)
    printSudoku(grid)
    if SudokuSolver(grid):
        arr = [20,30,40,50,60]
        difficulty =  int(input("Choose your difficulty from 0 to 4"))
        difficulty = arr[difficulty]
        addBlanks(grid,difficulty)
        printSudoku(grid)
        if SudokuSolver(grid):
            printSudoku(grid)
