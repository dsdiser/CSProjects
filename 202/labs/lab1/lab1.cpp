#include <iostream>
#include <string>
using namespace std;

int main()
{
  string drink;
  int numDrink = 0;
  cout << "How many drinks do you have?" << endl;
  cin >> numDrink;
  if (cin.peek() == '\n')
    cin.ignore();
  cout << "What kind of drink?" << endl;
  getline(cin,drink);
  for(int count = numDrink;count > 0; count--)
    {
      cout << count << " bottles of " << drink << " on the wall." << endl;
      cout << count << " bottles of " << drink << "." << endl;
      cout << "Take one down, pass it around." << endl;
      if(count != 1)
	cout << count-1 << " bottles of " << drink << " on the wall." << endl;
    }
  cout << "No bottles of " << drink << " on the wall." << endl;
  return 0;
}
