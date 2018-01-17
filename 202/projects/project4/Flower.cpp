#include "Flower.h"

/*****************************************
 ** File:    Flower.cpp
 ** Project: CMSC 202 Project 4, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    4/16/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Flower class for project 4
 ** this class serves as a child class for the plant class
 ** with implementations of virtual functions
 **
 **
 ********************************************/

//Flower
//Default constructor
Flower::Flower(){
  SetSize(0);
  SetIsDiseased(false);
  SetIsAlive(true);
  m_numPetals = 3;
  m_color = "None";
  m_isFlowering = false;
  srand(time(NULL));
}

//Plant(int, string)
//Constructor with custom petals and color
Flower::Flower(int numPetals, string color){
  SetSize(0);
  SetIsDiseased(false);
  SetIsAlive(true);
  m_numPetals = numPetals;
  m_color = color;
  m_isFlowering = false;
}

//die
//Sets isAlive to false and numPetals to 0
void Flower::die(){
  cout << "The flower dies." << endl;
  SetIsAlive(false);
  m_numPetals = 0;
}

//virtual tick
//A month passes is the flower's life
void Flower::tick(){
  //if it has been a month since the flower blossomed, it will drop its petals
  if(m_isFlowering and GetIsAlive() and GetSize() == 4){
    cout << "The flower drops its petals" << endl;
  }
  //makes sure the flower dies when it should
  else if(GetSize() == 5 and GetIsAlive())
    die();
  //if the flower is size 3 and has petals, it will flower
  if(GetSize() == 3 and m_numPetals >= 1)
    m_isFlowering = true;
  //if the plant isn't diseased, it will grow
  if(!(GetIsDiseased()))
    SetSize(GetSize() + 1);
  //resets isDiseased
  SetIsDiseased(false);
  //if the flower is old enough to die
  //finds a truely random number to get a 20% chance the plant will be diseased
  int random = rand() % 5 + 1;
  if(random == 1)
    SetIsDiseased(true);
}

//Title: operator<< (Overloaded << operator)
//Pre: Flower
//Post: Inserts the stream information about the flower
ostream& Flower::operator<<(ostream& os){
  //if the flower is already dead
  if(!(GetIsAlive())){
    os << "Flower: Dead\n";
    return os;
  }
  //if the flower is still growing
  string size = "(Fully Mature : ";
  //switch statement for the size of the flower
  switch(GetSize()){
  case 1:
    size = "(Seedling : ";
    break;
  case 2:
    size = "(Medium-Sized : ";
    break;
  }
  //flowering, alive, and diseased
  string flowering = "Not Flowering : ";
  if(m_isFlowering)
     flowering = "Flowering : ";
  string alive = "Alive : ";
  string diseased = "Not Diseased)";
  if(GetIsDiseased())
    diseased = "Diseased)";
  os << "Flower: " << size << alive << flowering << diseased << endl;
  return os;
}
