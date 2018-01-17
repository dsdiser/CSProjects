/*There are a number of optional functions in Truck.h. 
This is because you may want to implement the management of the trucks in a variety of ways. 
Trucks are kind of complex so it is up to you as to how you want to implement them. 
If you don't use a function, just stub it out and include a quick comment.
 */

#ifndef TRUCK_H
#define TRUCK_H

#include "Item.h"
#include "Tqueue.h"
#include "Delivery.h"

#include <vector>
using namespace std;

template <class T, int N>
class Truck {
 public:
  //Name: Truck(string, int) Overloaded constructor.
  //Precondition: Requires truck file has been loaded
  //Postcondition: Builds a new templated truck
  Truck(string inName, int capacity);

  //Name: Destructor
  //Precondition: Requires truck file has been loaded
  //Postcondition: Destroys everything in truck
  ~Truck();

  //Name: GetItem (optional)
  //Precondition: Requires that the truck's item queue has been populated
  //Postcondition: Templated accessor for this truck's cargo
  //Tqueue<T,N> GetItem() const;
  //NOT USED

  //Name: GetItemAt (optional)
  //Precondition: Requires that the truck's item queue has been populated
  //Postcondition: Templated accessor for this truck's cargo at a specific location
  // const T& GetItemAt(int index) const;
  //NOT USED

  //Name: AddItem (optional)
  //Precondition: Requires that the trucks have been loaded
  //Postcondition: Adds item into this truck
  void AddItem(T& inputObject);

  //Name: DeliverItemFromTruck (optional)
  //Precondition: Requires that the trucks have been loaded
  //Postcondition: Delivers item from this truck to customer
  void DeliverItemFromTruck();  

  //Name: AddDelivery (optional)
  //Precondition: Requires that all deliveries have been input and trucks
  //Postcondition: Used to add deliveries for specific trucks
  void AddDelivery(Delivery&);

  //Name: CompleteDelivery (optional)
  //Precondition: Requires that deliveries have been assigned to this truck
  //Postcondition: Removes current deliveries from this truck
  void CompleteDelivery();

  //Name: GetDeliveryAt (optional)
  //Precondition: Requires that this truck has at least 1 delivery assigned to it
  //Postcondition: Used to return a specific delivery
  //Delivery& GetDeliveryAt(int index);
  //NOT USED
  
  //Name: GetDelivery (optional)
  //Precondition: Requires deliveries have been asssigned to this truck
  //Postcondition: Used to return the entire vector of deliveries
  //vector<Delivery> GetDelivery() const;
  //NOT USED

  //Name: GetTime (optional)
  //Precondition: None
  //Postcondition: Used to return current time for a specific truck
  int GetTime(); 

  //Name: SetTime (optional)
  //Precondition: None
  //Postcondition: Used to set time for a specific truck
  void SetTime(int time);

  //Name: GetCapacity (optional)
  //Precondition: Requires that the trucks have been loaded
  //Postcondition: Used to access the capacity of a truck
  int GetCapacity() const;

  //Name: GetName (optional)
  //Precondition: Requires that the trucks have been loaded
  //Postcondition: Used to access the name of a truck
  string GetName() const;

private:
  string m_name;
  int m_capacity;
  int m_time;
  vector<Delivery> m_curDelivery;
  Tqueue<T,N> m_item;
};

template <class T, int N>

//Truck(string, int)
//Builds a new templated truck
Truck<T,N>::Truck(string inName, int capacity){
  m_name = inName;
  m_capacity = capacity;
  m_time = 0;
}

template <class T, int N>
//Destructor
//Destroys everything in truck
Truck<T,N>::~Truck(){
}

template <class T, int N>
//AddItem (optional)
//Adds item into this truck
void Truck<T,N>::AddItem(T& inputObject){
  m_item.enqueue(inputObject);
}

template <class T, int N>
//DeliverItemFromTruck (optional)
//Delivers item from this truck to customer
void Truck<T,N>::DeliverItemFromTruck(){
  T item;
  m_item.dequeue(item);
}

template <class T, int N>
//AddDelivery (optional)
//Used to add deliveries for specific trucks
void Truck<T,N>::AddDelivery(Delivery& delivery){
  m_curDelivery.push_back(delivery);
}

template <class T, int N>
//CompleteDelivery (optional)
//Removes current deliveries from this truck
void Truck<T,N>::CompleteDelivery(){
  int totalItems = 0;
  //prints out information
  cout << endl << "**Truck Name: " << m_name << " **" << endl;
  for(unsigned int i = 0; i < m_curDelivery.size(); i++){
    cout <<"***********Delivery " << i+1 << "*************" << endl
	 << "Delivery Time: " << (m_time += m_curDelivery.at(i).GetRTMinute()) 
	 << endl << "Delivery for: " << m_curDelivery.at(i).GetName() << endl
	 << "Delivered: " << m_curDelivery.at(i).GetNumItem() << endl;
    totalItems += m_curDelivery.at(i).GetNumItem();
  } 
  m_curDelivery.clear();
  //deliver items using function
  for(int i = 0; i < totalItems; i++)
    DeliverItemFromTruck();
}

template <class T, int N>
//GetTime (optional)
//Used to return current time for a specific truck
int Truck<T,N>::GetTime(){
  return m_time;
}

template <class T, int N>
//SetTime (optional)
//Used to set time for a specific truck
void Truck<T,N>::SetTime(int time){
  m_time = time;
}

template <class T, int N>
//GetCapacity (optional)
//Used to access the capacity of a truck
int Truck<T,N>::GetCapacity() const{
  return m_capacity;
}

template <class T, int N>
//GetName (optional)
//Used to access the name of a truck
string Truck<T,N>::GetName() const{
  return m_name;
}
#endif
