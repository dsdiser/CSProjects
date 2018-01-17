// File: driver.cpp
// Daniel Diseroad 
// 10/31/17


#include <cmath>
#include <cstdlib>
#include <iostream>
#include "ExpBST.h"
using namespace std;

void report(const ExpBST& T) {


  cout << "***** ExpBST Report\n" ;

  cout << "   size = " << T.size() << endl ;
  cout << "   height = " << T.height() << endl ;
  cout << "   height/log(size) = " << ( (float) T.height() ) / log2(T.size()) << endl ;
    
  cout << "   numRebalance = " << T.getNumRebalance() << endl ;
  cout << "   failedRebalance = " << T.getFailedRebalance() << endl ;
  cout << "   exceedsHeight = " << T.getExceedsHeight() << endl ;

  cout << "   maxRebalanceDepth = " << T.getMaxRebalanceDepth() << endl ;
  cout << "   minRebalanceHeight = " << T.getMinRebalanceHeight() << endl ;
  cout << "   rebalanceFactor = " << T.getRebalanceFactor() << endl ;

}



int main() {

  ExpBST T(3, 3, 2.0) ;
  int n = 100000;
  for(int w = 1 ; w < 2 * n ; w++) {
    T.insert(w) ;
  }

  for (int w = n/2 ; w < n + n/2 ; w++) {
    T.remove(w) ;
  }
  int m = 100;
  int k = 564;
  for (int j = 0 ; j < k ; j++) {
    
    int base = 4 * j * m ;

    for(int k = base ; k < base + 4 * m ; k++) {
      T.insert(k) ;
    }

    for (int k = base + m ; k < base + 2 * m ; k++) {
      T.remove(k) ;
    }
  }
  report(T);
}
