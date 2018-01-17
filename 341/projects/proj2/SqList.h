// File: SqList.h
//
// UMBC Fall 2017 CMSC 341 Project 2
//

using namespace std;
#ifndef _SQLIST_H_
#define _SQLIST_H_
#include "Int341.h"
#include <list>

class SqList {

 public:
  //Default Constructor
  //Pre: no SqList object
  //Post: new SqList object created
  SqList();

  //Copy Constructor
  //Pre: Other SqList exists
  //Post: other is copied to new SqList
  SqList(const SqList& other);
  
  //Finds the index of an element passed in
  //Pre: SqList exists
  //Post: return an integer representing the position
  int indexOf(const Int341& data) ;
  
  //Gets the number of elements of the square list
  //Pre: SqList exists
  //Post: returns number of elements
  int numItems() ;
  
  //Fixes the order of the square list
  //Pre: SqList exists and add or remove of some type is called
  //Post: list is ordered and square 
  void consolidate();

  //Removes an element from a given position
  //Pre: SqList exists
  //Post: element is removed and the Int341 value is returned
  Int341 remove(int pos);

  //Removes an element from the first position
  //Pre: SqList exists
  //Post: element is removed and the Int341 value is returned
  Int341 removeFirst ();

  //Removes an element from the last position
  //Pre: SqList exists
  //Post: element is removed and the Int341 value is returned
  Int341 removeLast ();

  //Add an element in the position passed in
  //Pre: SqList exists
  //Post: New element is added from given position
  void add(int pos, const Int341& data);

  //Adds an element to the first position
  //Pre: SqList exists
  //Post: New element is added to the front of the SqList
  void addFirst (const Int341& x) ;

  //Adds an element to the last position in the list
  //Pre: SqList exists
  //Post: New element is added to the end of the SqList
  void addLast (const Int341& x) ;

  //Overloaded assignment operator
  //Pre: SqList exists
  //Post: Data from rhs now is in lhs SqList
  const SqList& operator=(const SqList& rhs);

  //Overloaded [] operator
  //Pre: SqList exists
  //Post: Returns value by reference of the position passed
  Int341& operator[](int pos);

  //Debugging function, prints out all of the values in squarelist
  //Pre:  SqList exists
  //Post: cout statements
  void dump() ;

  //Debug function
  void inspector() ;
 
 private:
  list<list <Int341> > L;
  int m_numItems;
};
#endif
