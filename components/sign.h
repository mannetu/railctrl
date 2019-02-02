#ifndef SIGN_H
#define SIGN_H


#include <iostream>
#include "IComponent.h"

class Sign : public IComponent
{
  public:
  Sign(int address, IBusInterface *busInterface)
    : IComponent(address, busInterface) {};

  bool update() override;
};

bool Sign::update()
{
  std::cout << "Sign!!" << '\n';
  return 0;
}

#endif
