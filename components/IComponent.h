#ifndef ICOMPONENT_H
#define ICOMPONENT_H


#include <iostream>

#include "BusHandler.h"
//class BusHandler;

class IComponent
{
  public:
  IComponent(int address, BusHandler* busHandler)
    : m_busHandler(busHandler), m_address(address) {};

  int getAddress() {return m_address;}
  bool sendMessage(BusMessage msg) {m_busHandler->sendMessage(msg); return 0;}

  virtual bool update(const BusMessage &msg) = 0;
  virtual void ping(int address) = 0;

  private:
  BusHandler *m_busHandler;
  int m_address = 0;
};




#endif
