//File: SqList.cpp
//Daniel Diseroad

using namespace std;
#include "SqList.h"
#include <iostream>
#include <list>
#include <stdexcept>
#include <math.h>

typedef list<Int341> InnerList;
typedef list<InnerList> OuterList;

//Default Constructor
SqList::SqList(){
  m_numItems = 0;
  InnerList temp;
  L.push_back(temp);
}

//Copy Constructor
SqList::SqList(const SqList& other){
  //sets member variable equal
  m_numItems = other.m_numItems;
  //uses assign function to copy lists
  OuterList::const_iterator begin = other.L.begin();
  OuterList::const_iterator end = other.L.end();
  L.assign(begin,end);
}

//Finds the index of an element passed in
int SqList::indexOf(const Int341& data){
  //loops through and returns the index where the Int341 data is stored
  int index = 0;
  for(OuterList::iterator i = L.begin(); i != L.end(); ++i){
    for(InnerList::iterator j = i->begin(); j != i->end(); ++j){
      if(data.m_data == j->m_data)
	return index;
      index++;
    }
  }
  return -1;
}

//Gets the number of elements of the square list
int SqList::numItems(){
  return m_numItems;
}

//Fixes the order of the square list
void SqList::consolidate(){
  int newListSize = 0;
  OuterList::iterator j = L.begin();
  InnerList::iterator add;
  InnerList temp;
  for(OuterList::iterator i = L.begin(); i != L.end(); ++i){
    //if the list found is empty
    if(i->empty()){
      j = ++i;
      --i;
      L.erase(i);
      i=j;
    }
    else{
      //find if two adjacent lists are short
      j = i;
      advance(j,1);
      //if the size of i is short, if the list to the right is not the end of the
      //list, and if the size of j is short as well
      if(i->size() <= (sqrt(m_numItems)/2) and j != L.end()){ 
	if(j->size() <= (sqrt(m_numItems)/2)){
	  i->splice(i->end(),*j);
	  L.erase(j);
	}
      }
      //if the size of i is too long, split it into two lists
      else if(i->size() > (2*sqrt(m_numItems))){
	//calculate the size of the new list
	newListSize = (int)i->size() / 2;
	//add a new list to the overall list, then splice values into it
	L.insert(i,temp);
	add = i->begin();
	advance(add,newListSize);
	//sets an iterator to the new list added
	j = --i;
	++i;
	//adds values to the new list
	j->splice(j->begin(),*i,i->begin(),add);
	//j->insert(j->begin(),i->begin(),add);
	i->erase(i->begin(),add);
      }
    }
  }
}

//Removes an element from a given position
Int341 SqList::remove(int pos){
  bool foundIndex = false;
  OuterList::iterator i = L.begin();
  //bounds checking
  if((pos < 0) or (pos > m_numItems-1))
    throw out_of_range("out of range index");
  //calls removeFirst or removeLast if they are relevant
  if(pos == 0)
    return removeFirst();
  else if(pos == m_numItems-1)
    return removeLast();
  //loops through to find position then erases the value
  else{
    Int341 temp;
    while(i != L.end() and !(foundIndex)){
      pos -= i->size();
      if(pos < 0){
        foundIndex = true;
        pos += i->size();
	InnerList::iterator j = i->begin();
	//advances to the position to be removed, makes a new one to be returned,
	//and eraces it
	advance(j, pos);
	temp = *j;
	i->erase(j);
	m_numItems -= 1;
      }
      ++i;
    }
    consolidate();
    return temp;
  }

}

//Removes an element from the first position
Int341 SqList::removeFirst (){
  Int341 temp = L.front().front();
  L.front().pop_front();
  m_numItems -=1;
  consolidate();
  return temp;
}

//Removes an element from the last position
Int341 SqList::removeLast (){
  Int341 temp = L.back().back();
  L.back().pop_back();
  m_numItems -= 1;
  consolidate();
  return temp;
}

//Add an element in the position passed in
void SqList::add(int pos, const Int341& data){
  bool foundIndex = false;
  OuterList::iterator i = L.begin();
  //bounds checking
  if((pos < 0) or (pos > m_numItems))
    throw out_of_range("out of range index");
  //calls addFirst or addLast if they are relevant
  if(pos == 0)
    addFirst(data);
  else if(pos == m_numItems)
    addLast(data);
  else{
    //loops through to find the position then inserts the data
    while(i != L.end() and !(foundIndex)){
      pos -= i->size();
      if(pos < 0){
	foundIndex = true;
	pos += i->size();
	InnerList::iterator j = i->begin();
	//finds the point to add at and inserts the Int341
	advance(j, pos);
	i->insert(j,data);
	m_numItems += 1;
      }
      ++i;
    }
  consolidate();
  }
}

//Adds an element to the first position
void SqList::addFirst (const Int341& x){
  //cout << "Adding first: " << m_numItems <<  endl;
  L.front().push_front(x);
  m_numItems += 1;
  consolidate();
}

//Adds an element to the last position in the list
void SqList::addLast (const Int341& x){
  L.back().push_back(x);
  m_numItems += 1;
  consolidate();
}

//Overloaded assignment operator
const SqList& SqList::operator=(const SqList& rhs){
  //set member variables
  m_numItems = rhs.m_numItems;
  //previous values are cleared by assign function
  //take values from rhs and put them into lhs using assign function
  OuterList::const_iterator begin = rhs.L.begin();
  OuterList::const_iterator end = rhs.L.end();
  L.assign(begin,end);
  return *this;
}

//Overloaded [] operator
Int341& SqList::operator[](int pos){
  if((pos < 0) or (pos > m_numItems))
    throw out_of_range("out of range index");
  for(OuterList::iterator i = L.begin(); i != L.end(); ++i){
    pos -= i->size();
    if(pos < 0){
      pos += i->size();
      InnerList::iterator j = i->begin();
      advance(j, pos);
      return *j;
    }
  }
  return L.front().front();
}

//Debugging function, prints out all of the values in squarelist
void SqList::dump(){
  cout << "----- SqList dump() -----" << endl << "number of items = "
       << m_numItems << endl << "-------------------------" << endl;
  //iterates through and prints out the data of each int341
  int index = 0;
  for(OuterList::iterator i = L.begin(); i != L.end(); ++i){
    cout << "[" << index << "] " << " (" << i->size() << ") : ";
    for(InnerList::iterator j = i->begin(); j != i->end(); ++j){
      cout << j->m_data << " ";
    }
    cout << endl;
    index++;
  }
}
