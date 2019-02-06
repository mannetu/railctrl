#ifndef IBUSINTERFACE_H
#define IBUSINTERFACE_H

/*
Interface class for low-level bus controllers
(e.g. CAN bus)
*/

#include <cstdint>

struct BusMessage;
class BusHandler;

class IBusInterface
{
  public:
  virtual bool sendMessage(const BusMessage &msg) = 0;
  virtual      ~IBusInterface() {};
          void setBusHandler(BusHandler *busHandler) {m_busHandler = busHandler;};

  protected:
  BusHandler*  m_busHandler;

  public:
  // will be changed to protected once called by concrete Interface
  // on receiving message
  virtual bool notifyBusHandler(BusMessage &msg) = 0;
};


#endif
