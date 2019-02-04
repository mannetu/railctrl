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
  void ping() override;
  void toggle() override;
};

bool Turnout::update(const BusMessage &msg)
{
  std::cout << "Turnout: Updating with address: " << msg.id+0 << '\n';
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Data " << i << " :" << msg.data[i] << '\n';
  }
  return 0;
}

void Turnout::ping()
{
  std::cout << "Ping: Turnout mit address: " << m_address << '\n';
}

void Turnout::toggle()
{
  BusMessage msg;
  msg.id = m_address;
  msg.data[0] = 1000;
  sendMessage(msg);
};

#endif
