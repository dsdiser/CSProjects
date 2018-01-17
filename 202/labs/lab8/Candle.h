#ifndef CANDLE_H
#define CANDLE_H

#include <string>
#include <iostream>
using namespace std;

class Candle {
 public:
  Candle(string name, double burnRate); //Constructor

  string GetName(); //Getter for name
  void SetName(string name); //Setter for name
  double GetBurnRate(); //Getter for burn rate
  void SetBurnRate(double burnRate); //Setter for burnrate
  string GetLit(); //Returns if the candle is lit or not
  void SetLit(bool isLit); //Toggles if the candle is lit or not

 protected:
  string m_name;
  bool m_isLit;
  double m_burnRate;
};

#endif
