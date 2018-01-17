#include "Candle.h"

Candle::Candle(string name, double burnRate) {
  m_name = name;
  m_burnRate = burnRate;
  m_isLit = false;
}

string Candle::GetName() {
  return m_name;
}

double Candle::GetBurnRate() {
  return m_burnRate;
}

void Candle::SetName(string name) {
  m_name = name;  
}

void Candle::SetBurnRate(double burnRate){
  m_burnRate = burnRate;
}

string Candle::GetLit() {
if(m_isLit == true)
	return "Yes";
return "No";
}

void Candle::SetLit(bool isLit) {
  m_isLit = isLit;
}


