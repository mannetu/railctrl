#ifndef TURNOUT_H
#define TURNOUT_H


#include <iostream>
#include "IComponent.h"

class Turnout : public IComponent
{
  public:
  Turnout(int address, IBusInterface *busInterface)
    : IComponent(address, busInterface) {};

  bool update() override;
};

bool Turnout::update()
{
  std::cout << "Turnout!!" << '\n';
  return 0;
}

#endif
