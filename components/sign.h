#ifndef SIGN_H
#define SIGN_H


#include <iostream>
#include "IComponent.h"

class Sign : public IComponent
{
  public:
  Sign(int address, BusHandler* busHandler)
    : IComponent(address, busHandler) {};

  bool update(const BusMessage &msg) override;
};

bool Sign::update(const BusMessage &msg)
{
  std::cout << "Sign!!" << '\n';
  return 0;
}

#endif
