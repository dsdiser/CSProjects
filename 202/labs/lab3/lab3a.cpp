#include <iostream>
#include <string>

using namespace std;
void quaff(int &hitPoint);

int main()
{
  int hitPoint = 10;
  string userInput;
  cout << "You have " << hitPoint << " hit points." << endl;
  cout << "What would you like to do?" << endl;
  getline(cin, userInput);
  if(userInput == "quaff potion")
    {
    quaff(hitPoint);
    cout << "You have quaffed the potion!" << endl;
    }
  cout << "You have " << hitPoint << " hit points." << endl;
  return 0;
}

void quaff(int &hitPoint)
{
  hitPoint += 2;
}
