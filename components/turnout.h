#ifndef TURNOUT_H
#define TURNOUT_H


#include <iostream>
#include "IComponent.h"

class Turnout : public IComponent
{
  public:
  Turnout(int address, BusHandler* busHandler)
    : IComponent(address, busHandler) {};

  bool update() override;
};

bool Turnout::update()
{
  std::cout << "Turnout!!" << '\n';
  return 0;
}

#endif
