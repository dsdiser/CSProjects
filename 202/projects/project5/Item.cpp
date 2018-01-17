#include "Item.h"

/*****************************************
 ** File:    Item.cpp
 ** Project: CMSC 202 Project 5, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    5/1/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Item class for project 5
 ** this class assists with the project's function
 ** by making an item
 **
 **
 ********************************************/

//Item() Default Constructor
//Creates an item
Item::Item(){
  m_name = "default";
  m_weight = 1.00;
}

//Item(name, weight) Overloaded Constructor
//Creates an item
Item::Item(string iName, float iWeight){
  m_name = iName;
  m_weight = iWeight;
}

//GetName
//Returns name
string Item::GetName() const{
  return m_name;
}

//GetWeight
//Returns weight
float Item::GetWeight() const{
  return m_weight;
}
