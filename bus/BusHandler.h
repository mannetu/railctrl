#ifndef BUSHANDLER_H
#define BUSHANDLER_H

#include <map>
#include "IBusInterface.h"
#include "IComponent.h"

class BusHandler
{
  public:
  void sendMessage(const BusMessage &msg);
  void notifyComponent(const BusMessage &msg);
  void setInterface(IBusInterface *interface) {m_interface = interface;}
  void registerComponent(IComponent*);

  private:
  IBusInterface *m_interface;
  std::map<int,IComponent*> observer;
};

#endif
