/*****************************************
 ** File:    proj1.cpp
 ** Project: CMSC 202 Project 1, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    2/10/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu 
 **
 ** This file contains the game "Manhunt," where an
 ** investigator tries to find a fugitive from the
 ** law. The game has the ability to read from a file
 ** and includes the use of arrays.
 **
 ***********************************************/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

const int ROWS_COLUMNS = 10; //number of rows and columns there are in the map.
const int INVALID = 11; //an invalid number for most of the while loop conditions.
const int MIN_POSITION =  0; //The minimum position the pieces can be in
const int MAX_POSITION = 9; ////The maximum position the pieces can be in

//-------------------------------------------------------
// Name: startMenu
// PreCondition: none
// PostCondition: The program is either loading or creating a map or quitting
//---------------------------------------------------------
void startMenu();
//-------------------------------------------------------
// Name: newMap
// PreCondition: none
// PostCondition: A map has been created
//---------------------------------------------------------
void newMap();
//-------------------------------------------------------
// Name: printMap
// PreCondition: none
// PostCondition: A map has been created
//---------------------------------------------------------
void printMap(char board[][ROWS_COLUMNS]);
//-------------------------------------------------------
// Name: loadFile
// PreCondition: none
// PostCondition: A map has been loaded
//---------------------------------------------------------
void loadFile();
//-------------------------------------------------------
// Name: mainMenu
// PreCondition: A map has been created
// PostCondition: The user has won the game or has quit, ending the program
//---------------------------------------------------------
void mainMenu(char board[][ROWS_COLUMNS],int investPositionX,int investPositionY,
	      int targetPositionX, int targetPositionY);
//-------------------------------------------------------
// Name: checkSearch
// PreCondition: The user has inputted a direction to go
// PostCondition: Returns a boolean marking whether the user can move there or not
//---------------------------------------------------------
bool checkSearch(int investPositionX, int investPositionY);
//-------------------------------------------------------
// Name: checkWin
// PreCondition: The user has moved a direction
// PostCondition: Returns a boolean marking whether the user has won or not
//---------------------------------------------------------
bool checkWin(int investPositionX, int investPositionY,int targetPositionX,
	      int targetPositionY);
//-------------------------------------------------------
// Name: recommendation
// PreCondition: The user has moved a direction and they have not won yet
// PostCondition: Outputs a direction which will lead them to finding the target
//---------------------------------------------------------
void recommendation(int investPositionX, int investPositionY,int targetPositionX,
		     int targetPositionY);

int main() 
{
  startMenu();
  return 0;
}

// startMenu
// First function of the program, leads into either loadFile, newMap, or exiting the program
void startMenu()
{
//Beginning prompt
  cout << "Manhunt" << endl;
  cout << "What would you like to do?\n1. Load a simulation from file" << endl;
  cout << "2. Start a new simulation\n3. Exit" << endl;
  int choice = 0;
//Validating user input
  while(choice<1 or choice>3)
  {
      cout << "Enter 1 - 3:" << endl;
      cin >> choice;
      if (cin.peek() == '\n')
	cin.ignore();
  }
//Cases lead to different function calls, either loading from a file, making a new map, or
//quitting the program
  switch(choice)
  {
    case 1:
      loadFile();
      break;
    case 2:
      newMap();
      break;
    case 3:
      cout << "Giving up so soon?\nGoodbye." << endl;
      break;
  }
}

// newMap
// Called by startMenu, creates a map and calls mainMenu
void newMap()
{
//Creates map of underscores in a 2D array
  char board[ROWS_COLUMNS][ROWS_COLUMNS];
  for(int i=0; i<ROWS_COLUMNS; i++)
    for(int j = 0; j<ROWS_COLUMNS; j++)
      board[i][j] = '_';
//Initialization for variables for investigator and target position
  int xInvest = INVALID;
  int yInvest = INVALID;
  int xTarget = INVALID;
  int yTarget = INVALID;
//Input for positions of the investigator and target and input validation
  while((xInvest > MAX_POSITION or xInvest < MIN_POSITION) or (yInvest > MAX_POSITION or 
	 yInvest <  MIN_POSITION) or (xTarget > MAX_POSITION or xTarget < MIN_POSITION) or 
	 (yTarget > MAX_POSITION or yTarget < MIN_POSITION))
  {
    cout << "What is the X axis of the investigator?:" << endl;
    cin >> xInvest;
    cout << "What is the Y axis of the investigator?:" << endl;
    cin >> yInvest;
    cout << "What is the X axis of the target?:" << endl;
    cin >> xTarget;
    cout << "What is the Y axis of the target?:" << endl;
    cin >> yTarget;
  }
//Inputs the target and investigator positions into the board
  board[yInvest][xInvest] = 'I';
  board[yTarget][xTarget] = 'T';
//Starts the main menu function with the board and investigator position
  mainMenu(board,xInvest,yInvest,xTarget,yTarget);
}

// printMap
// called by mainMenu, prints out the map and omits the location of the target
void printMap(char board[][ROWS_COLUMNS])
{
//Prints out each char in array one by one, 
//making a new line when the row is done
  for(int i = 0; i<ROWS_COLUMNS; i++)
  {
    for(int j = 0; j<ROWS_COLUMNS;j++)
//Prints out a "_" instead of a T so the user doesn't know where the target is
      if(board[i][j] != 'T')
	cout << board[i][j] << " ";
      else
	cout << '_' << " ";
    cout << endl;
  }
}

// loadFile
// Called by startMenu, gets and creates a new map from numbers in a text file
void loadFile()
{
//Initializes inputstream and asks the user for the name of the text file
  ifstream inputStream;
  string fileName;
  cout << "What is the name of the file?" << endl;
  getline(cin,fileName);
  inputStream.open(fileName.c_str());
  int xInvest, yInvest, xTarget, yTarget;
//Gathers the x and y coordinates of the investigator and target
  inputStream >> xInvest;
  inputStream >> yInvest;
  inputStream >> xTarget;
  inputStream >> yTarget;
//Makes the new board and inputs the targets
  char board[ROWS_COLUMNS][ROWS_COLUMNS];
  for(int i=0; i<ROWS_COLUMNS; i++)
    for(int j = 0; j<ROWS_COLUMNS; j++)
      board[i][j] = '_';
//Places icons where the investigator and target are
  board[yInvest][xInvest] = 'I';
  board[yTarget][xTarget] = 'T';
//Starts the main menu function with the board and investigator position
  cout << "Map loaded" << endl;
  inputStream.close();
  mainMenu(board,xInvest,yInvest,xTarget,yTarget);
}

// mainMenu
// Called by most of the functions. The main bulk of the program, calling functions and 
// updating the map until the user wins or quits
void mainMenu(char board[][ROWS_COLUMNS],int investPositionX, int investPositionY,
	      int targetPositionX, int targetPositionY)
{
  while(true)
  {
    printMap(board);
//Prints out menu
    cout << "What would you like to do?" << endl;
    cout << "1. Search North\n2. Search East\n3. Search South\n4. Search West" << endl;
    cout << "5. See Map\n6. Exit" << endl;
    int choice = 0;
//Validation of input
    while(choice<1 or choice>6)
    {
      cout << "Enter 1 - 6:" << endl;
      cin >> choice;
      if (cin.peek() == '\n')
	cin.ignore();
    }
//Cases lead to the same function but different parameters
    switch(choice)
    {
    case 1:
//Makes the investigator go north and updates the map
      if(checkSearch(investPositionX,investPositionY-1))
      { 
	board[investPositionY][investPositionX] = '*';
	investPositionY -=1;
	board[investPositionY][investPositionX] = 'I';
      }
      break;
    case 2:
//Makes the investigator go east and updates the map
      if(checkSearch(investPositionX+1,investPositionY))
      {
	board[investPositionY][investPositionX] = '*';
	investPositionX +=1;
	board[investPositionY][investPositionX] = 'I';
      }
      break;
    case 3:
//Makes the investigator go south and updates the map
      if(checkSearch(investPositionX,investPositionY+1))
      {
	board[investPositionY][investPositionX] = '*';
	investPositionY +=1;
	board[investPositionY][investPositionX] = 'I';
      }
      break;
    case 4:
//Makes the investigator go west and updates the map
      if(checkSearch(investPositionX-1,investPositionY))
      {
	board[investPositionY][investPositionX] = '*';
	investPositionX -=1;
	board[investPositionY][investPositionX] = 'I';
      }
      break;
    case 5:
//Prints the map again
      printMap(board);
      break;
    case 6:
//Exits the program
      cout << "Giving up so soon?\nGoodbye." << endl;
      exit(1);
      break;
    }
//Determines if the investigator found the target and either exits or continues the program
    if (checkWin(investPositionX,investPositionY,targetPositionX,targetPositionY))
    {
      cout << "You found the target." << endl;
      exit(1);
    }
    recommendation(investPositionX,investPositionY,targetPositionX,targetPositionY);
  }
}

// checkWin
// Called by mainMenu, determines whether the user has won or not
bool checkWin(int investPositionX, int investPositionY,int targetPositionX,
	      int targetPositionY)
{
  if((investPositionX==targetPositionX) and (investPositionX==investPositionY))
    return true;
  return false;
}

// checkSearch
// Called by mainMenu, determines whether the space the user wants to go is out of bounds
bool checkSearch(int investPositionX, int investPositionY)
{
//Checks to see if the user wants the investigator to go out of the map
  if((investPositionX>9 or investPositionX<0)or(investPositionY>9 or investPositionY<0))
  {
    cout << "You cannot go this direction." << endl;
    return false;
  }
  return true;
}

// recommendation
// Called by mainMenu, recommends which direction the investigator should go
void recommendation(int investPositionX, int investPositionY,int targetPositionX,
		    int targetPositionY)
{
//Uses the difference between the investigator's x or y position and the x or y position
//of the target to determine what course the investigator should take. Determines based on 
//x position first, then y. 
  if(investPositionX > targetPositionX)
    cout << "Try Searching West" << endl;
  else if(investPositionX < targetPositionX)
    cout << "Try Searching East" << endl;
  else if(investPositionY < targetPositionY)
    cout << "Try Searching South" << endl;
  else if(investPositionY > targetPositionY)
    cout << "Try Searching North" << endl;
}
