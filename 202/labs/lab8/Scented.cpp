#include "Scented.h"

Scented::Scented(string name, double burnRate, string flavor )
  : Candle(name, burnRate)
{
  m_flavor = flavor;
  m_isLit = false;
}

string Scented::GetFlavor(){
  return m_flavor;
}

void Scented::SetFlavor(string flavor){
  m_flavor = flavor;
}

void Scented::SetLit(bool boolean){
  cout << "The delicious smell of " << m_flavor << " wafts from the scented candle." << endl;
  m_isLit = boolean;
}
