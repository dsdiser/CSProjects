#include "Garden.h"

/*****************************************
 ** File:    Garden.cpp
 ** Project: CMSC 202 Project 4, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    4/16/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Garden class for project 4
 ** this class serves as the mainframe of the program and 
 ** holds all of the plant objects.
 **
 **
 ********************************************/

//Title: Garden() Constructor
//Pre: Garden
//Post: Garden object with no plants
Garden::Garden(){
  vector<Plant*> garden;
  m_garden = garden;
  m_gardenSize = 0;
  m_month = 0;
}

//~Garden()
//Garden object (and plants) are destroyed
Garden::~Garden(){
  if(m_gardenSize > 0){
    Plant* plant = NULL;
    //for loop that clears all the memory from the garden vector
    for(int i = 0 ; i < m_gardenSize; i++){
      plant = m_garden.at(i);
      delete plant;
    }
    //sets the pointer to NULL
    plant = NULL;
  }
  //clears vector and resets month
  m_garden.clear();
  m_month = 0;
}

//addPlant(int, int)
//Adds plants to the garden vector
void Garden::addPlant(int type, int quantity){
  //Switch statement for every type of plant
  //The for loop inside each plant dynamically allocates that plant and inserts
  //it into the garden vector
  switch(type){
  case 1:
    for(int i = 0; i < quantity; i++){
      m_garden.push_back(new Flower());
      m_gardenSize++;
    }
    break;
  case 2:
    for(int i = 0; i < quantity; i++){
      m_garden.push_back(new Vegetable());
      m_gardenSize++;
    }
    break;
  case 3:
    for(int i = 0; i < quantity; i++){
      m_garden.push_back(new Tree());
      m_gardenSize++;
    }
    break;
  }
}

//tick(int)
//Calls tick for each item in the garden for the duration passed to it
void Garden::tick(int tickCount){
  for(int i = 0; i < tickCount; i++)
    tick();
}

//tick(1)
//Calls tick for each item in the garden for exactly one month
void Garden::tick(){
  Plant* plantPtr = NULL;
  cout << "MONTH " << m_month+1 << endl;
  for(int i = 0; i < m_gardenSize; i++){
    plantPtr = m_garden.at(i);
    cout << i+1 << ": ";
    plantPtr -> tick();
    *plantPtr << cout;
  }
  m_month += 1;
}

//getSize
//Returns m_gardenSize
int Garden::getSize(){
  return m_gardenSize;
}

//getMonths
//Returns m_month
int Garden::getMonths(){
  return m_month;
}
