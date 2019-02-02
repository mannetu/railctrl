#ifndef IBUSINTERFACE_H
#define IBUSINTERFACE_H

/*
Interface class for low-level bus controllers
(e.g. CAN bus)
*/

#include <cstdint>

class BusHandler;

struct BusMessage
{
  int id = 0;
  int data[8] = {0,0,0,0,0,0,0,0}; // cout type with "+0"
};

class IBusInterface
{
  public:
  virtual bool receiveMessage(BusMessage &msg) = 0;
  virtual bool sendMessage(const BusMessage &msg) = 0;
  virtual ~IBusInterface() {};
  void setBusHandler(BusHandler *busHandler) {m_busHandler = busHandler;};
  private:
  BusHandler *m_busHandler;
};


#endif
