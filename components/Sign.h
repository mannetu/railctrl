#ifndef SIGN_H
#define SIGN_H

#include <iostream>
#include "IComponent.h"
struct BusMessage;

class Sign : public IComponent
{
  public:
  Sign(std::string label, int address)
    : IComponent(label, address) {};

  bool update(const BusMessage &msg) override;
  void ping() override;
};


#endif
