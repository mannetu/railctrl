#ifndef ICOMPONENT_H
#define ICOMPONENT_H


#include <iostream>
#include "IBusInterface.h"


class IComponent
{
  public:
  IComponent(int address, IBusInterface *busInterface)
  {
    m_address = address;
    m_busInterface = busInterface;
  };
  int getAddress() {return m_address;}
  bool sendMessage(BusMessage msg) {m_busInterface->sendMsg(msg); return 0;}

  virtual bool update() = 0;

  private:
  IBusInterface *m_busInterface;
  int m_address = 0;
};




#endif
