#include "Delivery.h"
/*****************************************
 ** File:    Delivery.cpp
 ** Project: CMSC 202 Project 5, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    5/1/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Delivery class for project 5
 ** this class assists with the project's function
 ** 
 **
 **
 ********************************************/

//Delivery Constructor
//Creates a delivery
Delivery::Delivery(){
  m_name = "Default";
  m_numItem = 1;
  m_rtMinute = 10;
}

//Delivery(name, numItem, rtMinute) Constructor
//Creates a delivery
Delivery::Delivery(string name, int numItem, int rtMinute){
  m_name = name;
  m_numItem = numItem;
  m_rtMinute = rtMinute;
}

//GetName
//returns m_name
string Delivery::GetName() const{
  return m_name;
}

//GetNumItem
//returns m_numItem
int Delivery::GetNumItem() const{
  return m_numItem;
}

//GetRTMinute
//returns m_rtMinute
int Delivery::GetRTMinute() const{
  return m_rtMinute;
}
