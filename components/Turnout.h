#ifndef TURNOUT_H
#define TURNOUT_H

#include <iostream>
#include "IComponent.h"

struct BusMessage;

class Turnout : public IComponent
{
  public:
  Turnout(std::string label, int address)
    : IComponent(label, address) {};

  bool update(const BusMessage &msg) override;
  void ping() override;
  void toggle() override;
};

#endif
