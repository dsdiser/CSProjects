#ifndef SCENTED_H
#define SCENTED_H
#include "Candle.h"

class Scented : public Candle {
 public:
  Scented(string name, double burnRate, string flavor);
  string GetFlavor(); 
  void SetFlavor(string flavor);
  void SetLit(bool boolean);
 private:
  string m_flavor;

};

#endif
