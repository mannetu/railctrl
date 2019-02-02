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
  void ping(int address) override;
};

bool Sign::update(const BusMessage &msg)
{
  std::cout << "Sign: Updating with address: " << msg.id+0 << '\n';
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Data " << i << " :" << msg.data[i] << '\n';
  }
  return 0;
}

void Sign::ping(int address) {std::cout << "Sign mit address: " << address << '\n';}

#endif
