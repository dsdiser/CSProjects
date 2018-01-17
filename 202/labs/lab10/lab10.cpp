#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
  // Create IntArray objects and call methods here...
  IntArray ia(10);
  IntArray ie(0);
  IntArray test(-1,12);
  test.Append(1666666666666);
  ia.Append(0);
  ia.Get(11);
  ia.Get(-1);
  ia.Remove(32);
  ia.Contains(32,-1);
  test.Product(ia);
  ia.Sum(ie);
  ia.Product(test);
  ie.AddToAll(2);
  ie.Scale(7);
  ie.Contains(3,3);
  ia.Contains(2,300);
  ie.Clear();
  // Print out the number of errors/edge cases found
  cout << endl << endl << IntArray::GetProgress() << endl;
    
  return 0;
}
