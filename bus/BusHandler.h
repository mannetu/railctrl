#ifndef BUSHANDLER_H
#define BUSHANDLER_H

#include <map>
#include "IBusInterface.h"


class IComponent
{
  public:
  IComponent(int address) {m_address = address;}
  int getAddress() {return m_address;}

  private:
  int m_address = 0;
};


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
