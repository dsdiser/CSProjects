#include "Vegetable.h"

/*****************************************
 ** File:    Plant.cpp
 ** Project: CMSC 202 Project 4, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    4/16/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Vegetable class for project 4
 ** this class serves as a child class for the plant class
 ** with implementations of virtual functions
 **
 **
 ********************************************/

//Vegetable
//Default constructor
Vegetable::Vegetable(){
  SetSize(0);
  SetIsDiseased(false);
  SetIsAlive(true);
  m_color = "none";
  srand(time(NULL));
}

//Vegetable(string)
//Constructor looking for vegetable color
Vegetable::Vegetable(string color){
  SetSize(0);
  SetIsDiseased(false);
  SetIsAlive(true);
  m_color = color;
  srand(time(NULL));
}

//die
//Vegetable isAlive = false
void Vegetable::die(){
  SetIsAlive(false);
}

//harvest
//Harvest the vegetables and calls die
void Vegetable::harvest(){
  cout << "The vegetable has been harvested" << endl;
  die();
}

//tick
//Goes through a month in the vegetable's life, includes the possibility of disease
void Vegetable::tick(){
  if(GetSize() == 5 and GetIsAlive())
    harvest();
  //if the plant isn't diseased, it will grow
  if(!(GetIsDiseased()))
    SetSize(GetSize() + 1);
  //resets isDiseased
  SetIsDiseased(false);
  //finds a truely random number to get a 20% chance the plant will be diseased
  int random = rand() % 5 + 1;
  if(random == 1)
    SetIsDiseased(true);
}

//operator << (Overloaded << operator)
//Inserts into the stream the vegetable's information
ostream& Vegetable::operator<<(ostream& os){
  //if the vegetable has already been harvested
  if(!(GetIsAlive())){
    os << "Vegetable: Harvested\n";
    return os;
  }
  //if the vegetable is still growing
  string harvestable = "Not Harvestable : ";
  if(GetSize() == 5)
    harvestable = "Harvestable : ";
  string alive = "(Alive : ";
  string diseased = "Not Diseased)";
  if(GetIsDiseased())
    diseased = "Diseased)";
  os << "Vegetable: " << alive << harvestable << diseased << endl;
  return os;
}
