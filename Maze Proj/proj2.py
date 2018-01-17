# File: proj2.py
# Author: Daniel Diseroad
# Date: 12/1/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program solves a given maze through recursion
# Collaboration:
# Collaboration was not allowed on this assignment.

RIGHT,BOTTOM,LEFT,TOP = 0,1,2,3
LINE,OPEN = "1","0"

# readMaze() forms a text file representing a maze into a usable list
# Input: a file; contains maze
# Output: 3 lists; representing the entire maze, the number of rows and columns, and the
#         finish square.
def readMaze(fileName):
    mazeFile = open(fileName,"r")
    mazeRow,maze = [],[]
    rowsColumns = mazeFile.readline().split()
    finish = mazeFile.readline().split()
    counter = 0
    for line in mazeFile:
        mazeRow.append(line.split())
        counter+=1
        #adds the row of squares to the overall maze list and resets the row.
        if(counter == int(rowsColumns[1])):
            maze.append(mazeRow)
            mazeRow = []
            counter = 0
    return maze, rowsColumns,finish

# searchMaze() searches the maze for a possible solution.
# Input: a file containing the maze, integers representing where the current square is 
#        on the board, a list representing the finishing square,
#        and a list representing the path the maze is taking.
# Output: a list containing the correct solution path or None if there isn't a solution.
def searchMaze(maze,row,col,finish,path):
    square = maze[row][col]
    #if the finish square is found, return the path
    if row == int(finish[0]) and col == int(finish[1]):
        path.append((row,col))
        return path
    #if the square is boxed in, returns none
    elif(square[TOP]==LINE)and(square[LEFT]==LINE)and(square[RIGHT]==LINE)and(square[BOTTOM]==LINE):
        return None
    else:
        #checks to see if you can move in the maze, recursive
        if (square[RIGHT]==OPEN) and ((row,col+1) not in path):
            path.append((row,col))
            if searchMaze(maze,row,col+1,finish,path):
                return path
            #if the current stack doesn't lead into an answer, delete
            #the last value of the path.
            path.remove(path[-1])
        if (square[BOTTOM]==OPEN) and ((row+1,col) not in path):
            path.append((row,col))
            if searchMaze(maze,row+1,col,finish,path):
                return path
            path.remove(path[-1])
        if (square[LEFT]==OPEN) and ((row,col-1) not in path):
            path.append((row,col))
            if searchMaze(maze,row,col-1,finish,path):
                return path
            path.remove(path[-1])
        if (square[TOP]==OPEN) and ((row-1,col) not in path):
            path.append((row,col))
            if searchMaze(maze,row-1,col,finish,path):
                return path
            path.remove(path[-1])
        return None

def main():
    fileName = input("Please enter the filename of the maze: ")
    maze, rowsColumns, finish = readMaze(fileName)
    rowPrompt="Invalid, enter a number between 0 and " + rowsColumns[0] + " (inclusive): "
    columnPrompt="Invalid, enter a number between 0 and" + rowsColumns[1] + " (inclusive): "
    #input validation for row and column start
    rowStart = int(input("Please enter the starting row: "))
    while rowStart > int(rowsColumns[0]) or rowStart < 0:
        rowStart = int(input(rowPrompt))
    columnStart =  int(input("Please enter the starting column: "))
    while columnStart > int(rowsColumns[1]) or columnStart < 0:
        columnStart = int(input(columnPrompt))
    startPoint = [rowStart,columnStart]
    #calls recursive function and prints the result
    path = []
    path = searchMaze(maze,rowStart,columnStart,finish,path)
    if path == None:
        print("No solution found!")
    else:
        print("Here's the solution!")
        for i in path:
            print(i)

main()
