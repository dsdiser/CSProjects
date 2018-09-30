  // Daniel Diseroad
  // CMSC 341 Project 1
  // CBofCB.cpp
  // 9/13/17

using namespace std;
#include <stdexcept>
#include "CBofCB.h"

// default constructor
CBofCB::CBofCB(){
  m_obSize = 1;
  m_oldest = 0;
  m_newest = 0;
  m_buffers[0] = new InnerCB();
}

// copy constructor
CBofCB::CBofCB(const CBofCB& other){
  m_obSize = other.m_obSize;
  m_oldest = other.m_oldest;
  m_newest = other.m_newest;
  for(int i = 0; i < m_obCapacity; i++){
    InnerCB currentCopy = other.*m_buffers[i];
    *m_buffers[i] = currentCopy;
  }
}

// destructor
CBofCB::~CBofCB(){
  delete [] m_buffers;
}

// add item to this data structure
void CBofCB::enqueue(int data){
  int oldCBCapacity = 0;
  if(isFull())
    throw overflow_error;
  try{
    *m_buffers[m_newest].enqueue(data);
  }catch(overflow_error err){
    oldCBCapacity = *m_buffers[m_newest].capacity();
    m_newest += 1;
    if(m_newest >= m_obCapacity)
      m_newest = 0;
    m_buffers[m_newest] = new InnerCB(oldCBSize * 2);
    *m_buffer[m_newest].enqueue(data);
  }
}

// remove item from this data structure
int CBofCB::dequeue(){
  int dequeuedValue = 0;
  if(isEmpty())
    throw underflow_error;
  try{
    dequeuedValue = *m_buffers[m_oldest].dequeue();
  }catch(underflow_errow err){
    if(!(isEmpty())){
      delete m_buffers[m_oldest];
      m_oldest += 1;
      if(m_oldest >= m_obCapacity)
	m_oldest = 0;
    }
  }
  return dequeuedValue;
}

// returns true if cannot add more items
bool CBofCB::isFull(){
  if(*m_buffers[m_oldest].isFull() and *m_buffers[m_newest].isFull() 
     and m_obSize == m_obCapacity)
    return true;
  return false;
}

// returns true if no items stored in data structure
bool CBofCB::isEmpty(){
  if(*m_buffers[m_oldest].isEmpty())
    return true;
  return false;
}

// number of items in the data structure as a whole.
// Note: not the number of InnerCB's
int CBofCB::size(){
  int totalItems = 0;
  for(int i = 0; i < m_obCapacity; i++){
    totalItems += *m_buffers[i].size();
  }
  return totalItems;
}

// overloaded assignment operator
const CBofCB::CBofCB& operator=(const CBofCB& rhs){
  if(this == &rhs)
    return *this;
  delete [] m_buffers;
  InnerCB * m_buffers[m_obCapacity];
  m_obSize = rhs.m_obSize;
  m_oldest = rhs.m_oldest;
  m_newest = rhs.m_newest;
  for(int i = 0; i < m_obCapacity; i++)
    *m_buffers[i] = rhs.*m_buffers[i];
  return *this;
}

// debugging function, prints out contents of data structure
void CBofCB::dump(){
  for(int i = 0; i < m_obCapacity; i++)
    *m_buffers[i].dump();
}
