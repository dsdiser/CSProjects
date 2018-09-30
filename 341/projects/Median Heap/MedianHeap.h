
using namespace std;

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

template<typename T>
class Heap{
 public:
  //default constructor
  Heap();
  //overloaded constructor
  Heap(bool (*compare)(const T&, const T&), int cap = 50);
  //copy constructor
  Heap(const Heap<T>& otherH);
  //destructor
  ~Heap();
  //assignment operator
  const Heap<T>& operator=(const Heap<T>& rhs);
  //size getter funct
  int size();
  //capacity getter funct
  int capacity();
  //insert function
  void insert(const T& item);
  //gets root of heap
  T getRoot();
  //removes the roop of the heap
  T deleteRoot();
  //delete function
  bool deleteItem(T& givenItem, bool (*equalTo) (const T&, const T&) ) ;
  //percolate up function for heap
  void percolateUp(int hole, const T& item);
  //percolate down function for heap
  void percolateDown(int hole);
  //locate function
  T locate(int pos);
  //dump funct
  void dump();
  //finds the min or max of the medianheap
  T findMinOrMax();
  
 private:
  bool (*comp)(const T&, const T&);
  T* m_array;
  int m_capacity;
  int m_size;		
};

//default constructor
template<typename T>
Heap<T>::Heap(){
  m_capacity = 52;
  m_size = 0;
  m_array = new T[m_capacity];
  m_array[0] = T();
}

//basic constuctor 
template<typename T>
Heap<T>::Heap(bool (*compare)(const T&, const T&), int cap){
  comp = compare;
  m_capacity = cap+1;
  m_size = 0;
  m_array = new T[cap+1];
  m_array[0] = T();
}

//copy constructor
template<typename T>
Heap<T>::Heap(const Heap<T>& otherH){
  comp = otherH.comp;
  m_capacity = otherH.m_capacity;
  m_size = otherH.m_size;
  m_array = new T[m_capacity];
  m_array[0] = T();
  //copies data to current heap
  for(int i = 1; i < m_size+1; i++){
    m_array[i] = T(otherH.m_array[i]);
  }
}

//destructor
template<typename T>
Heap<T>::~Heap(){
  delete [] m_array;
  m_array = NULL;
}

//overloaded assignment operator
template<typename T>
const Heap<T>& Heap<T>::operator=(const Heap<T>& rhs){
  //clears previous data
  delete [] m_array;
  comp = rhs.comp;
  m_capacity = rhs.m_capacity;
  m_size = rhs.m_size;
  m_array = new T[m_capacity];
  m_array[0] = T();
  for(int i = 1; i < m_size+1; i++)
    m_array[i] = rhs.m_array[i];
  return *this;
}

//size getter function
template<typename T>
int Heap<T>::size(){
  return m_size;
}

//capacity getter function
template<typename T>
int Heap<T>::capacity(){
  return m_capacity;
}

//insert function based on function pointer
template<typename T>
void Heap<T>::insert(const T& item){
  if(m_size == m_capacity){
    cout << "too big" << endl;
    return;
  }
  // Percolate up
  int hole = ++m_size;
  percolateUp(hole, item);
}

//percolate up
template<typename T>
void Heap<T>::percolateUp(int hole, const T& item){
  for( ; hole > 1 and (comp(item, m_array[hole / 2])); hole /= 2 ){
    // swap, from child to parent
    m_array[hole] = m_array[hole / 2];
  }
  //moves item to correct spot
  m_array[hole] = item;
}

//gets the root of the min or max heap
template<typename T>
T Heap<T>::getRoot(){
  if(m_array != NULL)
    return m_array[1];
  return T();
}

//deletes the root of the min or max heap
template<typename T>
T Heap<T>::deleteRoot(){
  if(m_size == 0)
    return T();
  T temp = m_array[1];
  //m_size -= 1;
  m_array[1] = m_array[m_size--];
  //calls percolate to fix the heap
  percolateDown(1);
  return temp;
}

//deletes the item passed in using the function pointer passed in 
template<typename T>
bool Heap<T>::deleteItem(T& givenItem, bool (*equalTo) (const T&, const T&) ){
  if(m_size == 0)
    throw out_of_range("delete item");
  //searches the array and deletes if it finds the item 
  for(int i = 1; i < m_size+1; i++){
    if(equalTo(m_array[i],givenItem)){
	givenItem = m_array[i];
	m_array[i] = m_array[m_size--];
	//adjusts the array accordingly
	percolateDown(i);
	percolateUp(i,m_array[i]);
	return true;
    }
  }
  return false;
}

//adjusts the array after deletion of an item
template<typename T>
void Heap<T>::percolateDown(int hole){
  //cout << "percolating down" << endl;
  int child;
  T tmp = m_array[hole];
  //for loops through children
  for( ; hole * 2 <= m_size; hole = child ){
    child = hole * 2;
    if(child != m_size and (comp(m_array[child+1], m_array[child])))
      child++;
    if(comp(m_array[child], tmp))
      m_array[hole] = m_array[child];
    else 
      break;
  }
  m_array[hole] = tmp; 
}

//finds an item in the array using the position
template<typename T>
T Heap<T>::locate(int pos){
  if((pos > m_size+1) or (pos < 1))
    throw out_of_range("index out of range");
  return m_array[pos];
}

//finds the min if it is a max heap or finds the max if it is the min heap
template<typename T>
T Heap<T>::findMinOrMax(){
  if(m_size == 0)
    return T();
  T temp = m_array[1];
  //searches the array
  for(int i = 1; i < m_size+1; i++){
    if((comp(temp, m_array[i]))){
      temp = m_array[i];
    }    
  }
  return temp;
}

//gives output for the array, dumps data
template<typename T>
void Heap<T>::dump(){
  cout << "size = " << m_size << ", capacity = " << m_capacity << endl;
  for(int i = 1; i < m_size+1; i++)
    cout << "Heap[" << i << "] = (" << m_array[i] << ")" << endl;
}

#endif

#ifndef MEDIANHEAP_H
#define MEDIANHEAP_H
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

//medianHeap class
template<typename T>
class MedianHeap{
 public:
  //basic constructor
  MedianHeap(bool (*lt)(const T&, const T&), bool (*gt)(const T&, const T&), int cap=100);
  //copy constructor
  MedianHeap(const MedianHeap<T>& otherH) ;
  //destructor
  ~MedianHeap();
  //assignment operator
  const MedianHeap<T>& operator=(const MedianHeap<T>& rhs)  ;
  //getter for size
  int size();
  //getter for capacity
  int capacity();
  //insert function
  void insert(const T& item);
  //gets median of medianHeap
  T getMedian();
  //gets minimum of medianHeap
  T getMin();
  //gets maximum of medianHeap
  T getMax();
  //deletes item
  bool deleteItem(T& givenItem, bool (*equalTo) (const T&, const T&) ) ;
  //dump function
  void dump();
  //getter of maxHeap size
  int maxHeapSize();
  //getter of minHeap size
  int minHeapSize();
  //locates value in maxHeap
  T locateInMaxHeap(int pos);
  //locates value in minHeap
  T locateInMinHeap(int pos); 
 private:
  bool (*lessThan)(const T&, const T&) ;
  bool (*greaterThan)(const T&, const T&) ; 
  Heap<T> minHeap;
  Heap<T> maxHeap;
  int m_size;
  int m_capacity;
  T m_min;
  T m_max;
};

//basic constructor for medianHeap
template <typename T>
MedianHeap<T>::MedianHeap( bool (*lt) (const T&, const T&), bool (*gt) (const T&, const T&), int cap){
  lessThan = lt;
  greaterThan = gt;
  m_capacity = cap;
  m_size = 0;
  int sizeHeap = m_capacity;
  if(sizeHeap % 2 == 1)
    sizeHeap++;
  //makes heaps based on correct comparison operator
  minHeap = Heap<T>(lt, sizeHeap/2);
  maxHeap = Heap<T>(gt, sizeHeap/2);
}

//copy constructor
template <typename T>
MedianHeap<T>::MedianHeap(const MedianHeap<T>& otherH){
  lessThan = otherH.lessThan;
  greaterThan = otherH.greaterThan;
  m_capacity = otherH.m_capacity;
  m_size = otherH.m_size;
  //uses heap's copy constructor
  minHeap = Heap<T>(otherH.minHeap);
  maxHeap = Heap<T>(otherH.maxHeap);
  m_min = otherH.m_min;
  m_max = otherH.m_max;
}

//destructor ~not needed~
template <typename T>
MedianHeap<T>::~MedianHeap(){
  //delete minHeap;
  //delete maxHeap;
}

//overloaded assignment operator
template <typename T>
const MedianHeap<T>& MedianHeap<T>::operator=(const MedianHeap<T>& rhs){
  lessThan = rhs.lessThan;
  greaterThan = rhs.greaterThan;
  m_capacity = rhs.m_capacity;
  m_size = rhs.m_size;
  //makes use of heap class' assignment operator
  minHeap = rhs.minHeap;
  maxHeap = rhs.maxHeap;
  m_min = rhs.m_min;
  m_max = rhs.m_max;
  return *this;
}

//size getter 
template <typename T>
int MedianHeap<T>::size(){
  return m_size;
}

//capacity getter
template <typename T>
int MedianHeap<T>::capacity(){
  return m_capacity;
}

//insert function
template <typename T>
void MedianHeap<T>::insert(const T& item){
  if(m_size == m_capacity){
    throw out_of_range("insert");
    return;
  }
  //if the medianHeap is empty
  if(m_size == 0){
    maxHeap.insert(item);
    m_size++;
    m_min = item;
    m_max = item;
    return;
  }
  //track where the item should go and insert it into the correct heap
  if(lessThan(item, getMedian())){
    //balances two heaps to correctly make medianHeap
    if(maxHeap.size()+1 > minHeap.size()+1){
      minHeap.insert(maxHeap.deleteRoot());
    }
    maxHeap.insert(item);
    m_size++;
  }
  else if(greaterThan(item, getMedian())){
    //balances two heaps to correctly make medianHeap
    if(minHeap.size()+1 > maxHeap.size()+1){
      maxHeap.insert(minHeap.deleteRoot());
    }
    minHeap.insert(item);
    m_size++;
  }
  else{
    if(maxHeap.size()+1 > minHeap.size()+1){
      minHeap.insert(maxHeap.deleteRoot());
    }
    maxHeap.insert(item);
    m_size++;
  }
  //update min and max if needed
  if(greaterThan(item, m_max))
    m_max = item;
  if(lessThan(item, m_min))
    m_min = item;
}
  
//gets the median of the medianHeap
template <typename T>
T MedianHeap<T>::getMedian(){
  if(minHeap.size() > maxHeap.size()){
    return minHeap.locate(1);
  }
  else{
    return maxHeap.locate(1);
  }
}

//gets the member variable min
template <typename T>
T MedianHeap<T>::getMin(){
  return m_min;
}

//gets the member variable max
template <typename T>
T MedianHeap<T>::getMax(){
  return m_max;
}

//delete function
template <typename T>
bool MedianHeap<T>::deleteItem(T& givenItem, bool (*equalTo) (const T&, const T&) ){
  if(m_size == 0)
    throw out_of_range("deleteItem");
  //attempt to delete out of both heaps if needed
  bool deleted = maxHeap.deleteItem(givenItem, equalTo);
  if(!(deleted))
    deleted = minHeap.deleteItem(givenItem, equalTo);
  //possibly rebalance the two heaps if needed based off sizes
  if(maxHeap.size() > minHeap.size()+1 and deleted){
    minHeap.insert(maxHeap.deleteRoot());
  }
  if(minHeap.size() > maxHeap.size()+1 and deleted){
    maxHeap.insert(minHeap.deleteRoot());
  }
  //cout << "max size : " << maxHeap.size() << " min size: " << minHeap.size() << endl;
  //updates size if an item has been deleted
  if(deleted){
    m_size--;
    //special conditions to update min and max 
    if(minHeap.size() == 0 and maxHeap.size() != 0){
      m_min = maxHeap.getRoot();
      m_max = m_min;
    }
    else if(minHeap.size() != 0 and maxHeap.size() == 0){
      m_min = minHeap.getRoot();
      m_max = m_min;
    }
    else if(m_size == 0)
      m_max,m_min = T();
    else if(equalTo(givenItem,m_min))
      m_min = maxHeap.findMinOrMax();
    else if(equalTo(givenItem,m_max))
      m_max = minHeap.findMinOrMax();
  }
  return deleted;
}

//dump function
template <typename T>
void MedianHeap<T>::dump(){
  cout << "----------------Max Heap---------------" << endl;
  maxHeap.dump();
  cout << "----------------Min Heap---------------" << endl;
  minHeap.dump();
  cout << "-----------------------------------" << endl << endl;
  cout << "min = " << m_min << endl;
  cout << "median = " << getMedian() << endl;
  cout << "max = " << m_max << endl;
}

//gets size of maxHeap
template <typename T>
int MedianHeap<T>::maxHeapSize(){
  return maxHeap.size();
}

//gets size of minHeap
template <typename T>
int MedianHeap<T>::minHeapSize(){
  return minHeap.size();
}

//locates in maxHeap
template <typename T>
T MedianHeap<T>::locateInMaxHeap(int pos){
  return maxHeap.locate(pos);
}

//locates in minHeap
template <typename T>
T MedianHeap<T>::locateInMinHeap(int pos){
  return minHeap.locate(pos);
}


#endif
