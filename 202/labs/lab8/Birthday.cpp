#include "Birthday.h"

Birthday::Birthday(string name,
                 double burnRate,
                 bool isNoExtinguish)
  : Candle(name, burnRate)
{
  m_isNoExtinguish = isNoExtinguish;
}

bool Birthday::GetIsNoExtinguish()
{
  return m_isNoExtinguish;
}

void Birthday::SetIsNoExtinguish(bool isNoExtinguish){
  m_isNoExtinguish = isNoExtinguish;
}

string Birthday::SetLit(bool isLit)
{
  if (m_isNoExtinguish){
    cout << "You cannot blow the birthday candle out!" << endl;
    m_isLit = false;
    return "Yes";
  }
  else {
    m_isLit = true;
    return "No";
  }
}
