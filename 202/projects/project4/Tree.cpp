#include "Tree.h"

/*****************************************
 ** File:    Tree.cpp
 ** Project: CMSC 202 Project 4, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    4/16/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Tree class for project 4
 ** this class serves as a child class for the plant class
 ** with implementations of virtual functions
 **
 **
 ********************************************/

//Tree () Constructor
// Tree object
Tree::Tree(){
  SetSize(0);
  SetIsDiseased(false);
  SetIsAlive(true);
  vector<Fruit*> fruit;
  m_fruit = fruit;
  srand(time(NULL));
}

//~Tree
//Destroys tree and fruit
Tree::~Tree(){
  ClearFruit();
}

//die
//A tree can die after 120 months
void Tree::die(){
  SetIsAlive(false);
}

//ClearFruit
//Clears all fruit from the tree
void Tree::ClearFruit(){
  if(m_fruit.size() > 0){
    Fruit* fruit = NULL;
    //for loop that clears all the memory from the fruit vector
    for(unsigned int i = 0; i < m_fruit.size(); i++){
      fruit = m_fruit.at(i);
      delete fruit;
    }
    fruit = NULL;
  }
  m_fruit.clear();
}

//tick(Plant::EVENT)
//A month passes in the tree's life
void Tree::tick(){
  //If the plant is bigger than 36, alive, and not diseased, it will grow fruit
  if(GetSize() >= 36 and GetIsAlive() and !(GetIsDiseased()))
    m_fruit.push_back(new Fruit());
  if(GetSize() == 120)
    die();
  //if the plant isn't diseased, it will grow
  if(!(GetIsDiseased()))
    SetSize(GetSize() + 1);
  //resets isDiseased
  SetIsDiseased(false);

  //finds a truely random number to get a 20% chance the plant will be diseased
  int random = rand() % 5 + 1;
  if(random == 1 and GetIsAlive())
    SetIsDiseased(true);
}

//ostream &operator>>(std::ostream&)
//Inserts into the ostream& the tree's information
ostream& Tree::operator<<(ostream& os){
  string size;
  string fruiting = "Not Fruiting : ";
  //determining age of tree
  if(GetSize() < 12)
    size = "(Seedling : ";
  else if(GetSize() >= 12 and GetSize() < 24)
    size = "(Sapling : ";
  else if(GetSize() >=24 and GetSize() < 36)
    size = "(Pole : ";
  else if(GetSize() >= 36){
    size = "(Mature : ";
    fruiting = "Fruiting : ";
      }
  //determines whether the tree is living or not
  string alive = "Not Alive : ";
  if(GetIsAlive())
    alive = "Alive : ";
  string diseased = "Not Diseased)";
  if(GetIsDiseased())
    diseased = "Diseased)";
  os << "Tree: " << size << alive << fruiting << diseased << endl;
  return os;

}
