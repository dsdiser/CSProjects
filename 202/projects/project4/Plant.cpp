#include "Plant.h"

/*****************************************
 ** File:    Plant.cpp
 ** Project: CMSC 202 Project 4, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    4/16/17
 ** Section: 21
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Plant class for project 4
 ** this class serves as a base class for various other
 ** classes in the project
 **
 **
 ********************************************/

//Plant
//Cannot be called, virtual
Plant::Plant(){
}

//~Plant
//Cannot be called, virtual
Plant::~Plant(){
}

//GetIsDiseased
//returns m_isDiseased
bool Plant::GetIsDiseased(){
  return m_isDiseased;
}

//GetIsAlive
//returns m_isAlive
bool Plant::GetIsAlive(){
  return m_isAlive;
}

//GetSize
//returns m_size
int Plant::GetSize(){
  return m_size;
}

//SetSize(int)
//m_size is set
void Plant::SetSize(int size){
  m_size = size;
}

//SetIsAlive(bool)
//m_isAlive is set
void Plant::SetIsAlive(bool isAlive){
  m_isAlive = isAlive;
}

//SetIsDiseased(bool)
//m_isDiseased is set
void Plant::SetIsDiseased(bool isDiseased){
  m_isDiseased = isDiseased;
}



