#include <iostream>

using namespace std;

double calcAvg(int scores[], int length);
void printGrade(double average);
int main()
{
  const int LENGTH = 3;
  int scores[LENGTH];
  int score = 0;
  for(int i = 0; i<LENGTH;i++)
    {
      cout << "Enter your score:" << endl;
      cin >> score;
      scores[i] = score;
    }
  double average = calcAvg(scores,LENGTH);
  cout << "Your average is: " << average << endl;
  printGrade(average);
  return 0;
}

double calcAvg(int scores[], int length)
{
  int total = 0;
  for(int i = 0; i<length;i++)
    {
      total += scores[i];
    }
  double average = total / length;
  return average;
}

void printGrade(double average)
{
  int roundAvg = average / 10;
  switch(roundAvg)
    {
    case 10:
      cout << "You earned an A" << endl;
      break;
    case 9:
      cout << "You earned an A." << endl;
      break;
    case 8:
      cout << "You earned a B." << endl;
      break;
    case 7:
      cout << "You earned a C." << endl;
      break;
    case 6:
      cout << "You earned a D." << endl;
      break;
    case 5:
      cout << "You earned a F." << endl;
      break;
    case 4:
      cout << "You earned a F." <<endl;
      break;
    case 3:
      cout << "You earned a F." << endl;
      break;
    case 2:
      cout << "You earned a F." << endl;
      break;
    case 1:
      cout << "You earned a F." << endl;
      break;
    case 0:
      cout << "You earned a F." << endl;
      break;
    default:
      cout << "Error." << endl;
    }
}
