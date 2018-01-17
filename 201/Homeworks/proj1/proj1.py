# File: proj1.py
# Author: Daniel Diseroad
# Date: 11/3/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program allows two users to play the game Connect Four
# Collaboration:
# Collaboration was not allowed on this assignment.

COLUMN_ROW = 5
COLUMN_START = 1
PLAYER_1 = "x"
PLAYER_2 = "o"
EMPTY = "-"
RUN = "y"
STOP = "n"
WIN = 4

# aboveFive() prompts the user for the column and row length and validates that it is over 5
# Input: none
# Output: two ints; the row and column length
def aboveFive():
    promptRow = "Please choose the number of rows. \nPlease " \
        "enter a number" +" greater than or equal to "+ str(COLUMN_ROW)+ ": " 
    promptColumn = "Please choose the number of columns.\n" \
        "Please enter a number"+" greater than or " \
        "equal to "+ str(COLUMN_ROW)+ ": "
    row = int(input(promptRow))
    while row<COLUMN_ROW:
        row = int(input(promptRow))
    column = int(input(promptColumn))
    while column<COLUMN_ROW:
        column = int(input(promptColumn))

    return row,column

# boardMaker() creates a board for the players to play on.
# Input: two ints; row and column number
# Output: a list; represents the board
def boardMaker(row, column):
    board = []
    space = []
    for i in range(row):
        board.append([EMPTY])
        for j in range(column-1):
            board[i].append(EMPTY)
    return board

# boardUpdate() updates the board based on the player's move and prints the current board
# Input: an int representing the column number, a string representing what to put on the 
#        board, and a list with the board itself
# Output: a list; representing the current board or a num; representing the column is full.
def boardUpdate(columnNum,player,board):
    columnNum=int(columnNum)
    for i in range(len(board)-1,-1,-1):
        if board[i][columnNum-1]==EMPTY:
            board[i][columnNum-1]=player
            row,column = i,columnNum-1
            break
    print(boardPrinter(board))
    return board

# boardPrinter() prints out the current board
# Input: a list; representing the board
# Output: a print statement with the board layout
def boardPrinter(board):
    string = ""
    totalString=""
    for i in range(len(board)):
        for j in range(len(board[i])):
            string = string +" "+board[i][j]
            if len(string)==(len(board[i])*2):
                totalString=totalString+"\n"+string
                string = ""
    return totalString

# columnCheck() checks to see if the column selected by the user is full or is out of range
# Input: an int representing the column number and a list with the board itself
# Output: a boolean; representing whether the test passed or not
def columnCheck(columnNum,board,numOfColumns):
    counter = 0
    if(columnNum<1 or columnNum>numOfColumns):
        return False
    for i in range(len(board)):
        if board[i][columnNum-1] != EMPTY:
            counter+=1
    if (counter == len(board)):
        return False
    else:
        return True

# winLoseDraw() checks to see if the game is over.
# Input: a list with the board itself and an int representing the number of columns
# Output: a boolean; representing whether the game is over or not
def winLoseDraw(board,numOfColumns,player):
    counter=0
    playerN = ""
    if(player == PLAYER_1):
        player = PLAYER_2
        playerN = "Player 2"
    else:
        player = PLAYER_1
        playerN = "Player 1"
#tests to see if a player won horizontally
    for i in range(len(board)):
        counter=0
        for j in range(len(board[i])):
            if(board[i][j]==player):
                counter+=1
                if(counter==WIN):
                    print("The horizontal winner is",playerN)
                    return True
            else:
                counter=0
    counter=0
#tests to see if a player won vertically
    verticalMarks = []
    for i in range(len(board[0])):
        for j in range(len(board)):
            verticalMarks.append(board[j][i])
        for i in verticalMarks:
            if(i==player):
                counter+=1
                if(counter==WIN):
                    print("The vertical winner is",playerN)
                    return True
            else:
                counter=0
        verticalMarks = []
    counter=0
    verticalMarks = []
#diagonal check
    for i in range(len(board)):
        for j in range(len(board[i])):
            for w in range(WIN):
                if((i+w)<= len(board)-1) and ((j+w)<=len(board[i])-1):
                    if board[i+w][j+w]==player:
                        counter+=1
                        if counter==WIN:
                            print("The diagonal winner is",playerN)
                            return True
                    else:
                        counter=0
                else:
                    counter=0
            counter = 0
            for w in range(WIN):
                if ((i+w)<= len(board)-1) and ((j-w)>=0):
                    if board[i+w][j-w]==player:
                        counter+=1
                        if counter==WIN:
                            print("The diagonal winner is",playerN)
                            return True
                    else:
                        counter=0
                else:
                    counter = 0
#draw check
    counter=0
    for i in range(numOfColumns):
        if(columnCheck((i+1),board,numOfColumns)==False):
            counter+=1
    if(counter==numOfColumns):
        print("There was a draw!")
        return True
    return False
    
# playerTurn() goes through a player's turn, validating their choices and calling functions
#               to update the board or save
# Input: a string representing the current player, the board, an int representing the 
#        total columns, and a list containing valid inputs for the column number
# Output: a list representing the updated board
def playerTurn(player,board,numColumn,validNums):
    if(player==PLAYER_1):
        print("Player 1 what is your choice?")
    else:
        print("Player 2 what is your choice?")
    prompt = "Please choose a column to place your " \
        "piece in ("+str(COLUMN_START)+" - "+str(numColumn)+") " \
        "or s to save: "
    counter=0
    while True:
        userNum = input(prompt)
        if userNum==validNums[0]:
            #call save function
            openSave(1,board,player)
        else:
            #make sure the input is valid and use it, or reprompt.
            for i in range(len(validNums)):
                if validNums[i] == userNum:
                    counter+=1
            if(columnCheck(int(userNum),board,numColumn)==True) and counter==1:
                board = boardUpdate(userNum,player,board)
                break
            else:
                if int(userNum)>0 and int(userNum)<len(board[0])+1:
                    print("That column is full.")
        counter = 0
    return board

# openSave() either opens a game already saved by the user, or creates a new save.
# Input: an int representing whether the program should open (0) or save (1)
#        a list representing the board, and a string representing the current player.
# Output: a list representing the board and a letter representing the current player,
#         or none
def openSave(decision,board,player):
    if(decision == 0):
        fileName = input("Enter the name of the file you wish to open. ")
        boardFile = open(fileName,"r")
        #opens file and processes it into a list.
        allLines = boardFile.readlines()
        boardRow=[]
        board = []
        for i in allLines:
            boardRow = i.strip().split(" ")
            board.append(boardRow)
        #gets the player whose turn is it from the saved file
        player = board[-1:]
        player = player[0][0]
        board= board[:len(board)-1]
        remover = [""]
        board.remove(remover)
        boardFile.close()
        return board,player
    else:
        #save function, uses board printer to input into the file.
        fileName = input("What game file would you like to save to? ")
        boardFile = open(fileName,"w")
        boardFile.write(boardPrinter(board).strip(" "))
        boardFile.write("\n"+player)
        boardFile.close()
        print("File saved")
        return None

def main():
    run = RUN
    print("Welcome to Connect Four\nThis game is for two players.")
    decision = ""
    player = PLAYER_1
    board = []
    newGame = True
    while decision != "y" and decision != "n":
        decision = input("Would you like to load a game (y/n)? ")
    if decision == "y":
        board,player = openSave(0,board,player)
        newGame = False
        #number of rows and columns
        row,column = len(board), len(board[0])
#runs the bulk of the program, calling functions and changing player turns as needed
    while run == RUN:
        if newGame == True:
            row,column = aboveFive()
            board = boardMaker(row, column)
        print(boardPrinter(board))
        validNums = ["s"]
        for i in range(1,column+1):
            validNums.append(str(i))
        while winLoseDraw(board,column,player)==False:
            board = playerTurn(player,board,column,validNums)
            #Changes player turns
            if(player == PLAYER_1):
                player = PLAYER_2
            else:
                player = PLAYER_1
        player = PLAYER_1
        #sees if the player would like to play again
        run = input("Would you like to play again (y/n)? ")
        while run!= RUN and run!= STOP:
            run = input("Would you like to play again (y/n)? ")
        newGame = True
main()
