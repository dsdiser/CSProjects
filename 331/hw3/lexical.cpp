using namespace std;
#include <iostream>
#include <string>
#include <fstream>

int main(){
  ifstream file;
  file.open("insertFile.txt");
  char value = '0';
  bool isDecimal = false;
  bool isOctal = false;
  bool isHex = false;
  bool isUnknown = true;
  file.get(value);
  if(value == '+' or value == '-')
    file.get(value);
  if(value == '0')
    isHex, isOctal = true;
  else
    isDecimal = true;
  file.get(value);
  if(value == 'x' or value == 'X'){
    isOctal = false;
    isDecimal = false;
  }
  while(file.get(value)){
    switch(value){
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
      isDecimal = false;
      isHex = false;
      break;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      break;
    case '8':
    case '9':
      isOctal = false;
      break;
    default:
      isDecimal = false;
      isHex = false;
      isOctal = false;
      break;
    }
  }
  if(isDecimal)
    cout << "Decimal" << endl;
  else if(isHex)
    cout << "Hexadecimal" << endl;
  else if(isOctal)
    cout << "Octal" << endl;
  else if(isUnknown)
    cout << "NONSENSE" << endl;
  file.close();
  return 0;
}
