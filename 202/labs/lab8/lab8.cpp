#include "Candle.h"
#include "Scented.h"
#include "Birthday.h"

//As a reminder, child classes will do one of three things: use, extend, or replace a parent function

int main()
{
  //Instantiates one of each type of candles
  Candle can1("Taper", 0.05); //Uses the candle constructor (Parent Class)
  Birthday birth1("Sparkle", 0.1, true); //Uses the birthday constructor (Child Class)
  Scented scent1("Yankee Candle", 0.03, "Hotdogs"); //Uses the scented constructor (Child Class)

  //Working with a regular candle
  cout << "For Candle:" << endl; //Parent Class
  cout << "Name: " << can1.GetName() << endl; //Parent Class
  cout << "Flame: " << can1.GetLit() << endl; //Parent Class

  cout << "Changing the Candle's name..." << endl; //Parent Class
  can1.SetName("Jar"); //Parent Class
  cout << "New Name: " << can1.GetName() << endl; //Parent Class

  //Working with a Birthday Candle
  cout << endl;
  cout << "For Birthday:" << endl;
  cout << "Name: " << birth1.GetName() << endl; //Uses Parent Class - example of using
  cout << "Is Extinguishable?: " << birth1.GetIsNoExtinguish() << endl; //Uses Child Class - example of extending
  cout << "Flame: " << birth1.SetLit(true) << endl; //Uses Child Class - example of replacing

  cout << "Everyone sings to you and you try to put out the birthday candle!" << endl;
  birth1.SetLit(false); //Uses Child Class - example of replacing
  if(birth1.GetLit() == "Yes") ////Uses Parent Class - example of using
	cout << "The birthday candle is still lit." << endl;

  //Working with a Scented Candle
  cout << endl;
  cout << "For Scented:" << endl;
  cout << "Name: " << scent1.GetName() << endl; //Uses Parent Class - example of using
  cout << "Flame: " << scent1.GetLit() << endl; //Uses Parent Class - example of using
  cout << "Flavor: " << scent1.GetFlavor() << endl; //Uses Child Class - example of extending
  
  cout << "Lighting the scented candle..." << endl;
  scent1.SetLit(true); //Uses Child Class - example of replacing
  
  cout << "Changing the scented candle's flavor to Candy Corn." << endl;
  scent1.SetFlavor("Candy Corn"); //Uses Child Class - example of extending
  scent1.SetLit(true); //Uses Child Class - example of replacing
	
  return 0;
}
