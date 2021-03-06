
#include "ExpBST.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int ExpBST::m_maxRebalanceDepth;
int ExpBST::m_minHeight;
float ExpBST::m_rebalanceFactor;
int ExpBST::m_numRebalance;
int ExpBST::m_failedRebalance;
int ExpBST::m_exceedHeight;

//default constructor
ExpBST::ExpBST(){
  m_maxRebalanceDepth = 3;
  m_minHeight = 5;
  m_rebalanceFactor = 2;
  m_numRebalance = 0;
  m_failedRebalance = 0;
  m_exceedHeight = 0;
  m_head = NULL;
  m_rebalanceArray = new Node*[int(pow(2,(m_maxRebalanceDepth+1))-1)];
  m_rebalanceArrayLen = 0;
}

//specific constructor
ExpBST::ExpBST(int depth, int minHeight, float factor){
  m_maxRebalanceDepth = depth;
  m_minHeight = minHeight;
  m_rebalanceFactor = factor;
  m_numRebalance = 0;
  m_failedRebalance = 0;
  m_exceedHeight = 0;
  m_head = NULL;
  m_rebalanceArray = new Node*[int(pow(2,(m_maxRebalanceDepth+1))-1)];  
  m_rebalanceArrayLen = 0;
}

//copy constructor
ExpBST::ExpBST(const ExpBST& other){
  m_head = copyHelper(other.m_head);
  m_maxRebalanceDepth = other.m_maxRebalanceDepth;
  m_minHeight = other.m_minHeight;
  m_rebalanceFactor = other.m_rebalanceFactor;
  m_rebalanceArray = new Node*[int(pow(2,(m_maxRebalanceDepth+1))-1)];
  m_rebalanceArrayLen = other.m_rebalanceArrayLen;
}

//assists the copy constructor using recursion
Node* ExpBST::copyHelper(const Node* copy){
  if(copy == NULL)
    return NULL;
  Node *copiedNode = new Node(copy->value);
  copiedNode->size = copy->size;
  copiedNode->height = copy->height;
  //recursive calls to copy left and right children
  copiedNode->left = copyHelper(copy->left);
  copiedNode->right = copyHelper(copy->right);
  return copiedNode;
}

//destructor
ExpBST::~ExpBST(){
  makeEmpty(m_head);
  m_head = NULL;
  //clears out rebalance array correctly
  delete [] m_rebalanceArray;
  m_rebalanceArray = NULL;
}

//recursively deconstructs the tree
void ExpBST::makeEmpty(Node*& head){
  if(head != NULL){
    // delete both children, then currNode
    makeEmpty(head->left);
    makeEmpty(head->right);
    delete head;
    // set currNode to NULL after deletion
    head = NULL;
  }
}

//insert function
void ExpBST::insert (int key){
  insertHelper(key,m_head);
}


//insert helper function
//Pre: insert was called
//Post: returns true if the item passed is a duplicate, false otherwise
bool ExpBST::insertHelper(int key, Node*& currNode){
  bool isDuplicate = true;
  //if the head is empty
  if(m_head == NULL){
    m_head = new Node(key);
    return false;
  }
  else if(currNode == NULL){ // no node here (make a new leaf)
    currNode = new Node(key,0);
    isDuplicate = false;
  }
  // value in CURRENT root < new value
  else if( key < currNode->value ) {
    isDuplicate = insertHelper(key, currNode->left);
  }
  // value in CURRENT root  > new value
  else if( key > currNode->value  ) {
    isDuplicate = insertHelper(key, currNode->right);
  }
  //duplicate value
  else if(key == currNode->value)
    return true;
  //updates the height and size of the node on traceback
  if(!isDuplicate){
    currNode->size += 1;
    //updates the height based on various conditions and whether or not the height
    //should be updated
    Node* potential = (currNode->left != NULL) ? currNode->left : currNode->right;
    if(currNode->left != NULL and currNode->right != NULL)
      currNode->height = max(currNode->left->height, currNode->right->height)+1;
    else if(potential != NULL)
      currNode->height = potential->height + 1;
    else
      currNode->height = 0;
  }
  //decides whether to rebalance or not
  if(float(currNode->height) > (m_rebalanceFactor*log2(currNode->size))and 
     currNode->height >= m_minHeight and !isDuplicate){
    rebalanceBootstrap(currNode);
  }
  return isDuplicate;
}


//remove function
bool ExpBST::remove(int key){
  //calls the helper function
  return removeHelper(key,m_head); 
}

//removeHelper function
//pre:
//post: returns false if no value was deleted
bool ExpBST::removeHelper(int key, Node*& currNode){
  bool hasRemoved;
  //check if need to update for 2 children, automatically need to update for 0 or 1 children
  if(currNode == NULL) 
    return false; // item not found; return false
  // continue to traverse until we find the element
  else if(key < currNode->value)
    hasRemoved = removeHelper(key, currNode->left);
  else if(currNode->value < key)
    hasRemoved = removeHelper(key, currNode->right);
  else if(currNode->left != NULL and currNode->right != NULL ){ // two children 
    // find left’s highest value
    currNode->value =  findMax(currNode->left)->value;
    //now delete that found value 
    hasRemoved = removeHelper(currNode->value, currNode->left);
  }
  else{ // zero or one child
    Node *oldNode = currNode;
    // ternary operator
    currNode = (currNode->left != NULL) ? currNode->left : currNode->right;
    //replace the currentNode then delete it
    delete oldNode;
    if(currNode != NULL)
      currNode->size += 1;
    hasRemoved = true;
  }
  //update heights on traceback
  if(currNode != NULL and hasRemoved){
    Node* potential = (currNode->left != NULL) ? currNode->left : currNode->right;
    currNode->size -= 1;
    //updates height based off various conditions
    if(currNode->left != NULL and currNode->right != NULL)
      currNode->height = max(currNode->left->height, currNode->right->height)+1;
    else if(potential != NULL)
      currNode->height = potential->height + 1;
    else
      currNode->height = 0;

    //determine whether to rebalance or not on traceback
    if(currNode->height > (m_rebalanceFactor*log2(currNode->size))and
       currNode->height >= m_minHeight and hasRemoved )
      rebalanceBootstrap(currNode);
  }
  return hasRemoved;
}

//findMax
Node* ExpBST::findMax(Node*& currNode){
  // empty tree
  if (currNode == NULL) 
    return NULL;
  // no further nodes to the right
  if (currNode->right == NULL) 
    return currNode; 
  else 
    return findMax(currNode->right); 
}


//find a specific node
bool ExpBST::find(int key){
  return findHelper(key, m_head);
}

//helps to find specific node using recursion
bool ExpBST::findHelper(int key, Node*& currNode){
  if(currNode == NULL ) 
    return false;
  // our value is lower than the current node's
  else if(key < currNode->value)
    return findHelper( key, currNode->left );
  // our value is higher than the current node's
  else if(currNode->value < key)
    return findHelper( key, currNode->right );
  else
    return true; // Match
}

//locates whether there is a node in the position and if so, stores the key
//and returns true, otherwise returns false
bool ExpBST::locate(const char *position, int& key){
  return locateHelper(position,key, 0, m_head);
}

//helps to locate the node and get the key using recursion
bool ExpBST::locateHelper(const char *position,int& key,int index,Node* currNode){
  //checks if the node is empty, not found
  if(currNode == NULL)
    return false;
  //base case if the index is equal to the length of the array, position is found
  else if (strlen(position) == index){
    key = currNode->value;
    return true;
  }
  //if the next position is to the left
  else if(position[index] == 'L'){
    //recursion call
    return locateHelper(position,key,index+1,currNode->left);
  }
  //if the next position is to the right
  else if(position[index] == 'R'){
    //recursion call
    return locateHelper(position,key,index+1,currNode->right);
  }
}

//creates the array to be passed into shortest BST in order to assist with 
//rebalancing
void ExpBST::rebalanceArrayMaker(int depth, Node*& currNode){
  if (depth > getMaxRebalanceDepth())
    return;
  else if(currNode == NULL){
    m_rebalanceArray[m_rebalanceArrayLen] = NULL;
    m_rebalanceArrayLen += 1;
    return;
  }
  /* first recur on left child */ 
  rebalanceArrayMaker(depth+1, currNode->left);
  m_rebalanceArray[m_rebalanceArrayLen] = currNode;
  m_rebalanceArrayLen += 1;
  /* now recur on right child */
  rebalanceArrayMaker(depth+1, currNode->right);
  return ;
}

void ExpBST::rebalanceBootstrap(Node*& currNode){
  int prevHeight = currNode->height;
  m_rebalanceArrayLen = 0;
  //creates array to use for rebalancing nodes
  rebalanceArrayMaker(0, currNode);
  //finds the best root for the new subtree then creates the new subtree
  int possibleRoot = shortestBST(0, m_rebalanceArrayLen-1);
  currNode = rebalance(0,m_rebalanceArrayLen-1,possibleRoot);
  //updates postrebalance statistics
  m_numRebalance += 1;
  if(currNode->height >= prevHeight)
    m_failedRebalance += 1;
  if(currNode->height > (m_rebalanceFactor*log2(currNode->size)))
    m_exceedHeight += 1;
}

//assists rebalance in finding what the height of the best node would be
int ExpBST::shortestBST(int begin, int end){
  //base case
  if(begin >= end){
    return end;
  }
  int bestLeft = 0, bestRight = 0, bestRoot = 0;
  int height = -1, tempHeight = 0, leftHeight = -1, rightHeight = -1;
  for(int i = begin; i <= end; i++){
    if(i%2 == 1){
      //finds the best possible child for left and right subtree in the array
      bestLeft = shortestBST(begin,i-1);
      bestRight = shortestBST(i+1,end);
      //finds the heights of the two children
      if(m_rebalanceArray[bestLeft] != NULL)
	leftHeight = m_rebalanceArray[bestLeft]->height;
      if(m_rebalanceArray[bestRight] != NULL)
	rightHeight = m_rebalanceArray[bestRight]->height;
      if(height == -1){
	//finds the height of the current root
	height = max(leftHeight,rightHeight) + 1;
	bestRoot = i;
      }
      //compares the heights for all the possible roots and chooses the best one
      else{
      //finds the height of the current root
	tempHeight = max(leftHeight,rightHeight) + 1;
	if(height > tempHeight){
	  height = tempHeight;
	  bestRoot = i;
	}
      }
    }
  }
  //cout << "returning height " << height << endl;
  m_rebalanceArray[bestRoot]->height = height;
  return bestRoot;
}

//rebalances the tree recursively, creating the tree using shortestBST
Node* ExpBST::rebalance(int begin, int end, int bestRoot){
  //base case
  if(begin >= end)
    return m_rebalanceArray[begin];
  //recursively create the left subtree from the left child of the root
  m_rebalanceArray[bestRoot]->left = rebalance(begin,bestRoot-1,shortestBST(begin,bestRoot-1));
  //recursively create the right subtree from the right child of the root
  m_rebalanceArray[bestRoot]->right = rebalance(bestRoot+1,end,shortestBST(bestRoot+1,end));
  //change sizes and heights based on various conditions
  if(m_rebalanceArray[bestRoot]->left == NULL 
     and m_rebalanceArray[bestRoot]->right == NULL){
    m_rebalanceArray[bestRoot]->height = 0;
     m_rebalanceArray[bestRoot]->size = 1;
  }
  else if(m_rebalanceArray[bestRoot]->left != NULL and m_rebalanceArray[bestRoot]->right != NULL){
    m_rebalanceArray[bestRoot]->height = max(m_rebalanceArray[bestRoot]->left->height, m_rebalanceArray[bestRoot]->right->height)+1;
     m_rebalanceArray[bestRoot]->size =  m_rebalanceArray[bestRoot]->left->size +  m_rebalanceArray[bestRoot]->right->size + 1;
  }
  else{
    Node* onlyNode = ( m_rebalanceArray[bestRoot]->left != NULL) ?  m_rebalanceArray[bestRoot]->left :  m_rebalanceArray[bestRoot]->right;
    m_rebalanceArray[bestRoot]->height = onlyNode->height+1;
     m_rebalanceArray[bestRoot]->size = onlyNode->size+1;
  }
  return m_rebalanceArray[bestRoot];
}

// tree has no nodes
bool ExpBST::empty() const {
  if(m_head == NULL)
    return true;
  return false;
}

//height of overall tree
int ExpBST::height() const {
  if(m_head == NULL)
    return -1;
  return m_head->height;
}

//returns number of nodes in the tree
int ExpBST::size() const {
  if(m_head == NULL)
    return 0;
  return m_head->size;
}

//return depth
int ExpBST::getMaxRebalanceDepth() const{
  return m_maxRebalanceDepth;
}

//returns height
int ExpBST::getMinRebalanceHeight() const{
  return m_minHeight;
}

//returns adjusted member variable
float ExpBST::getRebalanceFactor() const{
  return m_rebalanceFactor;
}

//returns the total number of calls to rebalance since beginning of program or
//since it was reset
int ExpBST::getNumRebalance() const{
  return m_numRebalance;
}

//returns the total number of calls to rebalance which does not give a shorter
//subtree
int ExpBST::getFailedRebalance() const{
  return m_failedRebalance;
}

//returns total number of calls to rebalance that resulted in a subtree that is
//too tall
int ExpBST::getExceedsHeight() const{
  return m_exceedHeight;
}

//resets numRebalance,failedRebalance,and exceedHeight
void ExpBST::resetStats(){ 
}

//prints out an inorder walk of the ExpBST and information about it's nodes
void ExpBST::inorder(){
  inorderHelper(m_head);
}

//uses recursion to print out the inorder walk
void ExpBST::inorderHelper(Node*& currNode){
  if (currNode == NULL)
    return;
  cout << "(";
  /* first recur on left child */
  inorderHelper(currNode->left);
  /* then print the data of node */
  cout << currNode->value << ":" << currNode->height << ":" << currNode->size ;  
  /* now recur on right child */
  inorderHelper(currNode->right);
  cout << ")";
}

//overloaded assignment operator
const ExpBST& ExpBST::operator=(const ExpBST& rhs){
  //deletes old data first
  makeEmpty(m_head);
  delete [] m_rebalanceArray;
  m_rebalanceArray = NULL;
  //assign values from rhs to lhs
  m_head = copyHelper(rhs.m_head);
  m_maxRebalanceDepth = rhs.m_maxRebalanceDepth;
  m_minHeight = rhs.m_minHeight;
  m_rebalanceFactor = rhs.m_rebalanceFactor;
  m_rebalanceArray = new Node*[int(pow(2,(m_maxRebalanceDepth+1))-1)];
  m_rebalanceArrayLen = rhs.m_rebalanceArrayLen;
}
