#include <cstdlib>
#include <iostream>
using namespace std ;

void printRandom(int C[], int n, int seed) {
  srand(seed) ;
  int numDisplayed = 0;
  // fill in your code here
  while(numDisplayed != n){
    int r = rand() % n;
    if(C[r] != 0){
      cout << C[r] << " ";
      C[r] = 0;
      numDisplayed += 1;
    }
  }
  cout << endl;
}


int main() {
  int A[10], B[10] ;

  A[0] =  21 ;
  A[1] = -34 ;
  A[2] =   2 ;
  A[3] = -42 ;
  A[4] =  89 ;
  A[5] =  24 ;
  A[6] =  11 ;
  A[7] =   4 ;
  A[8] =  13 ;
  A[9] = -18 ;

  for (int i=0 ; i < 10 ; i++) {
    B[i] = A[i] ;
  }
  printRandom(B,10,38173410) ;

  for (int i=0 ; i < 10 ; i++) {
    B[i] = A[i] ;
  }
  printRandom(B,10,83103131) ;

  for (int i=0 ; i < 10 ; i++) {
    B[i] = A[i] ;
  }
  printRandom(B,10,77192102) ;

  return 0 ;
}
