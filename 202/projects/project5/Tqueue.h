#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor - Not used but required for project 5
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  void dequeue(T &); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve front (does not remove it)
  void queueFront(T &);    // Retrieve front (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: isFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int isFull(); //Returns 1 if queue is full else 0
  //Name: Overloaded assignment operator - Not used but required for project 5
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****

template <class T, int N>
//Tqueue - Default Constructor
//Creates a queue using dynamic array
Tqueue<T,N>::Tqueue(){
  m_data = new T[N];
  m_front = 0;
  m_back = 0;
}

template <class T, int N>
//Copy Constructor
//Copies an existing Tqueue
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ){
  m_front = x.m_front;
  m_back = x.m_back;
  //creates a deep copy of the passed in m_data
  T* tempArr = new T[N];
  if(m_back > 0)
    delete [] m_data;
  //creating copy and setting old to new copy
  for(int i = 0; i < m_back+1; i++)
    tempArr[i] = x.m_data[i];
  m_data = tempArr;
}

template <class T, int N>
//Destructor
//Destructs existing Tqueue
Tqueue<T,N>::~Tqueue(){
  delete [] m_data;
  m_data = NULL;
}

template <class T, int N>
//enqueue
//Adds item to back of queue
void Tqueue<T,N>::enqueue(T data){
  if(isFull()){
    cout << "Queue is full" << endl;
    return;
  }
  //adding item to back of queue and making the back larger
  m_data[m_back] = data;
  m_back += 1;
}

template <class T, int N>
//dequeue
//Removes item from front of queue
void Tqueue<T,N>::dequeue(T &){
  T* data = new T[N];
  //populating the new array then deleting the old one
  for(int i = 0; i < m_back; i++)
    data[i] = m_data[i+1];
  m_back -= 1;
  delete [] m_data;
  //setting old array to new array
  m_data = data;
}

template <class T, int N>
//queueFront
//Retrieve front (does not remove it)
void Tqueue<T,N>::queueFront(T &data){
  data = m_data[m_front];
}

template <class T, int N>
//isEmpty
//Returns 1 if queue is empty else 0
int Tqueue<T,N>::isEmpty(){
  if(m_back == m_front)
    return 1;
  return 0;
}

template <class T, int N>
//isFull
//Returns 1 if queue is full else 0
int Tqueue<T,N>::isFull(){
  if(m_back+1 == N){
    cout << "full " << endl;
    return 1;
  }
  return 0;
}

template <class T, int N>
//Overloaded assignment operator - Not used but required for project 5
//Sets one Tqueue to same as a second Tqueue using =
Tqueue<T,N>& Tqueue<T,N>::operator=( Tqueue<T,N> y){
  cout << "assignment operator" << endl;
  m_front = y.m_front;
  m_back = y.m_back;
  //creates a deep copy of the passed in m_data
  T* tempArr = new T[m_back];
  for(int i = 0; i < m_back; i++)
    tempArr[i] = y.m_data[i];
  delete [] m_data;
  //clears old array and is set to the new array
  m_data = tempArr;
  return *this;
}


#endif
