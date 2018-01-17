#include "Fruit.h"

/*****************************************
 ** File:    Fruit.cpp
 ** Project: CMSC 202 Project 4, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    4/16/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Fruit class for project 4
 ** this class serves as an assistant to the tree class
 ** 
 **
 **
 ********************************************/

//Fruit()
//fruit object with random color
Fruit::Fruit(){
  m_color = "red";
}

//GetColor()
//returns own color
string Fruit::GetColor(){
  return m_color;
}
