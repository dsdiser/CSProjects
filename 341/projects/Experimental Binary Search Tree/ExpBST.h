#ifndef EXPBST_H
#define EXPBST_H

#include <cstring>

//node struct, includes constructors for just a value(root) or a specific node
struct Node{
  int value;
  int height;
  int size;
  Node *left;
  Node *right;
  //various constructors
  Node(){
    this->value = 0;
    this->left = NULL;
    this->right = NULL;
    this->size = 1;
    this->height = 0;
  }
  Node(int val){
    this->value = val;
    this->left = NULL;
    this->right = NULL;
    this->size = 1;
    this->height = 0;
  }
  Node(int val, int height){
    this->value = val;
    this->height = height;
    this->size = 0;
    this->left = NULL;
    this->right = NULL;
  }
};

class ExpBST{
 private:
  Node* m_head;
  Node** m_rebalanceArray;
  int m_rebalanceArrayLen;
  static int m_maxRebalanceDepth;
  static int m_minHeight;
  static float m_rebalanceFactor;
  static int m_numRebalance;
  static int m_failedRebalance;
  static int m_exceedHeight;
  
  //assists the copy constructor
  Node* copyHelper(const Node* copy);
  //insert function helper
  bool insertHelper(int key, Node*& currNode);
  //remove function helper
  bool removeHelper(int key, Node*& currNode);
  //clear function
  void makeEmpty(Node*& header);
  //findHelper
  bool findHelper(int key, Node*& currNode);
  //inorderHelper
  void inorderHelper(Node*& currNode);
  //findMax
  Node* findMax(Node*& currNode);
  //locateHelper
  bool locateHelper(const char *position, int& key, int index, Node* currNode);
  //makes an array for rebalancing nodes
  void rebalanceArrayMaker(int depth, Node*& currNode);
  //assists rebalance in finding which node should be the root and what the height
  //would be
  int shortestBST(int begin, int end);
  //
  void rebalanceBootstrap(Node*& currNode);
  
 public:
  //default constructor
  ExpBST();
  //specific constructor
  ExpBST(int depth, int minHeight, float factor);
  //copy constructor
  ExpBST(const ExpBST& other);
  //destructor
  ~ExpBST();
  //insert function
  void insert (int key);
  //remove function
  bool remove(int key);
  //find a specific node
  bool find(int key);
  //locates whether there is a node in the position and if so, stores the key 
  bool locate(const char *position, int& key);
  //rebalances the tree recursively
  Node* rebalance(int begin, int end, int bestRoot);
  // tree has no nodes
  bool empty() const;
  //height of overall tree
  int  height() const;
  //returns number of nodes in the tree
  int  size() const;
  //return depth
  int getMaxRebalanceDepth() const;
  //returns height  
  int getMinRebalanceHeight() const;
  //returns adjusted member variable
  float getRebalanceFactor() const;
  //returns the total number of calls to rebalance since beginning of program or
  //since it was reset
  int getNumRebalance() const;
  //returns the total number of calls to rebalance which does not give a shorter 
  //subtree
  int getFailedRebalance() const;
  //returns total number of calls to rebalance that resulted in a subtree that is
  //too tall
  int getExceedsHeight() const;
  //resets numRebalance,failedRebalance,and exceedHeight
  void resetStats();
  //prints out an inorder walk of the ExpBST and information about it's nodes
  void inorder() ;
  //overloaded assignment operator
  const ExpBST& operator=(const ExpBST& rhs) ;

};

#endif
