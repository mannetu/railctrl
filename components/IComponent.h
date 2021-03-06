#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <string>
#include <iostream>

#include "BusHandler.h"
#include "BusMessage.h"

class IComponent
{
  public:
  IComponent(std::string label, int address)
    : m_label(label),  m_address(address) {};

  virtual ~IComponent() {};

  void setBusHandler(BusHandler* busHandler) {m_busHandler = busHandler;};
  int getAddress() {return m_address;}
  virtual bool update(const BusMessage &msg) = 0;
  virtual void ping() = 0;
  virtual void toggle() {};

  protected:
  BusHandler*  m_busHandler;
  std::string  m_label;
  int          m_address;
  bool         sendMessage(BusMessage msg) {m_busHandler->sendMessage(msg); return 0;}
};




#endif
