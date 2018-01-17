#ifndef BIRTHDAY_H
#define BIRTHDAY_H
#include "Candle.h"

class Birthday : public Candle {
 public:
  Birthday(string name,
          double burnRate,
          bool isNoExtinguish);

  bool GetIsNoExtinguish();
  void SetIsNoExtinguish(bool isNoExtinguish);
  string SetLit(bool isLit);

 protected:
  bool m_isNoExtinguish; //Special type of birthday candle that will not go out
};

#endif
