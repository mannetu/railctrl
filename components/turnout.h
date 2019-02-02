#ifndef TURNOUT_H
#define TURNOUT_H


#include <iostream>
#include "IComponent.h"

class Turnout : public IComponent
{
  public:
  Turnout(int address, BusHandler* busHandler)
    : IComponent(address, busHandler) {};

  bool update(const BusMessage &msg) override;
};

bool Turnout::update(const BusMessage &msg)
{
  std::cout << "Turnout!!" << '\n';
  return 0;
}

#endif
