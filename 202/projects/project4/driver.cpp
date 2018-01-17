#include "driver.h"

/*****************************************
 ** File:    driver.cpp
 ** Project: CMSC 202 Project 4, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    4/16/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the driver file for project 4
 ** this file serves as the director of the program.
 ** 
 **
 **
 ********************************************/

int main(){
  Garden garden = Garden();
  cout << "Welcome to the Garden" << endl;
  manageMenu(garden);
  return 0;
}

//menu
//Displays the first menu (1. Plant Single Item to 4. Exit)
void menu(){
  cout << "\n1. Plant Single Item\n2. Plant Many of the Same"
       << " Item\n3. Plant a Full Garden\n4. Exit\nEnter 1-4:" << endl;
}

//manageMenu(Garden)
//Manages user input and calls corresponding function
void manageMenu(Garden& garden){
  bool entry = true;
  int decision = 0;
  menu();
  decision = 0;
  while((decision < 1) or decision > 4)
    cin >> decision;
  switch(decision){
  case 1:
    singleGarden(garden);
    break;
  case 2:
    singleGarden(garden,2);
    break;
  case 3:
    manyGarden(garden);
    break;
  case 4:
    entry = false;
    break;
  }
}

//Title: singleGarden(Garden)
//Pre: Garden - 1 for single plant, >1 for multiple plants
//Asks user what type of plant and quantity of plants then calls addPlant and
//simulateTime
void singleGarden(Garden& garden, int quantity){
  plantMenu();
  //decision on what plant to plant
  int plantDecision = 0;
  while(plantDecision < 1 or plantDecision > 3)
    cin >> plantDecision;
  //if the argument states that the user wants to plant multiple, ask them how
  //many plants they want to plant
  if(quantity > 1){
    quantity = 0;
    cout << "How many would you like to plant?" << endl;
    while(quantity < 1)
      cin >> quantity;
  }
  //gets how many months they want to simulate
  garden.addPlant(plantDecision, quantity);
  simulateTime(garden);
}

//Title: manyGarden(Garden)
//Pre: Garden
//Asks user how many of each plant to plant (Flower, Vegetable, Tree)
//Post: Calls addPlant and then simulateTime
void manyGarden(Garden& garden){
  //Flower decision
  cout << "How many flowers would you like to plant?" << endl;
  int decision = -1;
  while(decision < 0){
      cin >> decision;
    }
    if(decision > 0)
      garden.addPlant(1,decision);
  //Vegetable decision
    cout << "How many vegetables would you like to plant?" << endl;
    decision = -1;
    while(decision < 0){
      cin >> decision;
    }
    if(decision > 0)
      garden.addPlant(2,decision);
  //Tree decision and simulateTime
    cout << "How many trees would you like to plant?" << endl;
    decision = -1;
    while(decision < 0){
      cin >> decision;
    }
    if(decision > 0)
      garden.addPlant(3,decision);
  simulateTime(garden);  
}

//Title: plantMenu
//Pre: None
//Post: Displays the menu of different types of plants (Flower, Vegetable, Tree)
void plantMenu(){
  cout << "What would you like to plant?\n1. Flower\n2. Vegetable\n3. Tree\n";
}

//Title: simulateTime(Garden)
//Pre: Garden with plants and asks user how many months to simulate
//Post: Calls the garden.tick and passes it the number of months
void simulateTime(Garden& garden){
  cout << "How many months would you like to simulate?:" << endl;
  int monthDecision = 0;
  while(monthDecision < 1)
    cin >> monthDecision;
  garden.tick(monthDecision);
}
