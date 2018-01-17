// Daniel Diseroad
// CMSC 341 Project 1
// InnerCB.cpp
// 9/11/17

using namespace std;
#include "InnerCB.h"
#include <stdexcept>
#include <iostream>

// Constructor, default size is 10.
InnerCB::InnerCB(int n){
  m_capacity = n;
  m_size = 0;
  m_start = 0;
  m_end = 0;
  m_buffer = new int[m_capacity];
}

// Copy constructor
InnerCB::InnerCB(const InnerCB& other){
  m_capacity = other.m_capacity;
  m_size = other.m_size;
  m_start = other.m_start;
  m_end = other.m_end;
  m_buffer = new int[m_capacity];
  for(int i = 0; i < m_capacity; i++){
    m_buffer[i] = other.m_buffer[i];
  }
}

// Destructor
InnerCB::~InnerCB(){
  delete [] m_buffer;
  m_buffer = NULL;
}

// Add item to circular buffer
void InnerCB::enqueue(int data){
  cout << "something???" << endl;
  if(m_size == m_capacity){
    throw overflow_error("No room");
    cout << "enqueue" << endl;
  }
  else if(m_end >= m_capacity)
    m_end = 0;
  m_buffer[m_end] = data;
  m_end += 1;
  m_size += 1;
  cout << "enqueue" << endl;
}

// Remove item from circular buffer
int InnerCB::dequeue(){
  int oldItem = 0;
  oldItem = m_buffer[m_start];
  m_buffer[m_start] = 0;
  m_start +=1;
  if(m_start >= m_capacity)
    m_start = 0;
  m_size -= 1;
  if(isEmpty())
    throw underflow_error("Empty buffer");
  return oldItem;
}

// True if no space left in buffer
bool InnerCB::isFull(){
  if(m_size == m_capacity)
    return true;
  return false;
}

// True if buffer holds no items
bool InnerCB::isEmpty(){
  if(m_size == 0)
    return true;
  return false;
}

// return maximum number of items this buffer can hold
int InnerCB::capacity(){
  return m_capacity;
}

// return number of items currently held in the buffer
int InnerCB::size(){
  return m_size;
}

// overloaded assignment operator
const InnerCB& InnerCB::operator=(const InnerCB& rhs){
  if(this == &rhs)
    return *this;
  delete [] m_buffer;
  m_buffer = new int[rhs.m_capacity];
  m_size = rhs.m_size;
  m_capacity = rhs.m_capacity;
  m_start = rhs.m_start;
  m_end = rhs.m_end;
  for(int i = 0; i < m_capacity; i++)
    m_buffer[i] = rhs.m_buffer[i];
  return *this;
}

// debugging function. Prints out contents.
void InnerCB::dump(){
  cout << "InnerCB dump(): m_size = " << size() << endl;
  int currIndex = m_start;
  while(m_start != m_end){
    cout << "[" << currIndex << "] " << m_buffer[currIndex] << ", ";
    m_start += 1;
    if (m_start >= m_capacity)
      m_start = 0;
  }
  cout << endl;
}
