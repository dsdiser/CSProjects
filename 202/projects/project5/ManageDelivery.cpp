#include "ManageDelivery.h"

/*****************************************
 ** File:    ReadyDelivery.cpp
 ** Project: CMSC 202 Project 5, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    5/5/17
 ** Section: 22
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the ManageDelivery class for project 5
 ** this class contains the main functions and use of this 
 ** project
 **
 **
 ********************************************/

//Constructor
//Populates member variables
ManageDelivery::ManageDelivery(vector< Truck <Item, MAX_CAPACITY> > truck,
			       vector< Delivery > delivery,
			       vector< Item > item){
  m_truck = truck;
  m_delivery = delivery;
  m_item = item;
  StartDelivery();
}

//StartDelivery
//Loads items into a truck
void ManageDelivery::StartDelivery(){
  int curDeliverySize = 0;
  int truckNum = 0;
  
  //while loop to get all deliveries assigned to a truck
  while(m_delivery.size() > 0){
    m_truck[truckNum].SetTime(m_truck[truckNum].GetTime()+10);
    //while the truck can hold another delivery
    while((curDeliverySize+m_delivery[0].GetNumItem()) 
	  <= m_truck[truckNum].GetCapacity() 
	  and !(m_delivery.size() == 0)){
      curDeliverySize += m_delivery[0].GetNumItem();
      //add delivery to truck
      m_truck[truckNum].AddDelivery(m_delivery[0]);
      //erase delivery from overall delivery vector      
      m_delivery.erase(m_delivery.begin());
    }
    //adding items to truck's queue and away from the overall item vector
    cout << "\n****Loading Truck (" << m_truck[truckNum].GetName() 
	 << ")*****" << endl;
    //m_truck[truckNum].SetTime(m_truck[truckNum].GetTime()+10);
    //printing out info and adding
    for(int i = 0; i < curDeliverySize; i++){
      cout << m_item[0].GetName() << " loaded into " 
	   << m_truck[truckNum].GetName() << endl;
      m_truck[truckNum].AddItem(m_item[0]);
      m_item.erase(m_item.begin());
    }
    DeliverItem(truckNum);
    curDeliverySize = 0;
    //resets time and truck number to the next truck to make deliveries
    truckNum = (truckNum + 1) % m_truck.size();
  }
  if(m_delivery.size() == 0 and (m_truck.size() > 1)){
    cout << "\n****Loading Truck (" << m_truck[truckNum].GetName()
         << ")*****" << endl << endl;
    cout << "**Truck Name: " << m_truck[truckNum].GetName() << "**" << endl
	 << "No deliveries" << endl;
  }
  //displays items not included in deliveries
  DisplayItemLeft();
}

//DeliverItem
//Outputs the delivery information including truck name and item
void ManageDelivery::DeliverItem(int j){
  m_truck[j].CompleteDelivery();
}

//DisplayItemLeft
//Outputs (cout) each item not loaded into a delivery
void ManageDelivery::DisplayItemLeft(){
  //determines whether the items need to be printed out or not
  cout << "\n*****Items Left After Deliveries*****" << endl;
  if(m_item.size() == 0)
    cout << "No remaining items" << endl;
  else{
    for(unsigned int i = 0; i < m_item.size(); i++){
      cout << "Item " << i+1 << " - Name: " << m_item[i].GetName() 
	   << " - Weight: " << m_item[i].GetWeight() << endl;
    }
  }
}
