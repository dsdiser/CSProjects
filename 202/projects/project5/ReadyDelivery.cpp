#include "ReadyDelivery.h"

/*****************************************
 ** File:    ReadyDelivery.cpp
 ** Project: CMSC 202 Project 5, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    5/2/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the ReadyDelivery class for project 5
 ** this class uses input files and makes truck, delivery, and item
 ** objects
 **
 **
 ********************************************/

//ReadyDelivery()
//Populates three vectors
ReadyDelivery::ReadyDelivery(){
  m_truckFile = "";
  m_deliveryFile = "";
  m_itemFile = "";
}

//ReadyDelivery(string, string, string)
//Populates three vectors
ReadyDelivery::ReadyDelivery(string truckFile, string deliveryFile, string itemFile){
  m_truckFile = truckFile;
  m_deliveryFile = deliveryFile;
  m_itemFile = itemFile;
  LoadTruck();
  LoadDelivery();
  LoadItem();
  cout << "Start Time: 0" << endl;
}

//LoadTruck
//Builds a vector of delivery trucks
//Trucks: Holds items
void ReadyDelivery::LoadTruck(){
  ifstream input;
  //opening file
  input.open(m_truckFile.c_str());
  string line,name = "";
  int capacity = 0;
  stringstream ss;
  //gets line of input file
  while(getline(input,line)){
    //uses sstream to get the variables needed
    ss << line;
    ss >> name >> capacity;
    ss.clear();
    ss.str("");
    //adds the truck to the vector
    m_truck.push_back(Truck<Item,MAX_CAPACITY>(name,capacity));
  }
  input.close();
  cout << "Trucks Loaded: " << m_truck.size() << endl;
}

//LoadDelivery
//Builds a vector of deliveries
void ReadyDelivery::LoadDelivery(){
  ifstream input;
  //opening file
  input.open(m_deliveryFile.c_str());
  string line,name = "";
  int numDelivery, time = 0;
  stringstream ss;
  vector<Delivery> delivery;
  //gets line of input file
  while(getline(input,line)){
    //uses string stream to parse the string into its parts
    ss << line;
    ss >> name >> numDelivery >> time;
    ss.clear();
    ss.str("");
    //adds the delivery to the vector
    delivery.push_back(Delivery(name,numDelivery,time));
  }
  input.close();
  //updating member variable
  m_delivery = delivery;
  cout << "Deliveries Loaded: " << m_delivery.size() << endl;
}

//LoadItem
//Builds a vector of items
void ReadyDelivery::LoadItem(){
  ifstream input;
  //opening file
  input.open(m_itemFile.c_str());
  string line,name = "";
  float weight = 0.0;
  stringstream ss;
  vector<Item> item;
  //gets line of input file
  while(getline(input,line)){
    //uses string stream to parse the string into its parts
    ss << line;
    ss >> name >> weight;
    ss.clear();
    ss.str("");
    //adds the item to the vector
    item.push_back(Item(name,weight));
  }
  input.close();
  //updating member variable
  m_item = item;
  cout << "Items Loaded: " << m_item.size() << endl;
}

//GetTruck
//Returns a vector of all trucks
vector< Truck<Item, MAX_CAPACITY> >& ReadyDelivery::GetTruck(){
  return m_truck;
}

//GetDelivery
//Returns a vector of all deliveries
vector<Delivery> ReadyDelivery::GetDelivery(){
  return m_delivery;
}

//GetItem
//Returns a vector of all items
vector<Item> ReadyDelivery::GetItem(){
  return m_item;
}
