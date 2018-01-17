#include <iostream>
using namespace std ;

//
// implement the initialize() function here
//
void initialize(int *&ptr, int num){
  ptr = new int[num];
  for(int i = 0; i < num; i++)
    ptr[i] = i;
}

int main() {
  int *ptr ;
  int n = 10 ;

  initialize(ptr,n) ;

  for (int i=0 ; i < n ; i++) {
    cout << "ptr[" << i << "] = " << ptr[i] << endl  ;
  }

  int sum = 0 ;
  for (int i=0 ; i < n ; i++) {
    sum += ptr[i] ;
  }
  cout << "Sum = " << sum << endl ;

  delete [] ptr ;

  int *ptr2 ;
  initialize(ptr2,15) ;

  sum = 0 ;
  for (int i=0 ; i < 15 ; i++) {
    sum += ptr2[i] ;
  }
  cout << "Sum = " << sum << endl ;

  delete [] ptr2 ;
}
