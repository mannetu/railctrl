#ifndef BUSHANDLER_H
#define BUSHANDLER_H

#include "IBusInterface.h"

class BusHandler
{
  public:
  void sendMessage(const BusMessage &msg);
  void setInterface(IBusInterface *interface) {m_interface = interface;}

  private:
  IBusInterface *m_interface;

};

#endif
