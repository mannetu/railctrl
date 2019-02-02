#ifndef BUSHANDLER_H
#define BUSHANDLER_H

#include <map>

struct BusMessage;
class  IBusInterface;
class  IComponent;

class BusHandler
{
  public:
  // Set concrete BusInterface object
  void setInterface(IBusInterface *interface) {m_interface = interface;}
  // Send message into physical bus
  void sendMessage(const BusMessage &msg);
  // Register component so that it can be notified once message arrives on bus
  void registerComponent(IComponent*);
  // Prints out list of registered components
  void listComponents();
  // Notifies the component object registered with address
  void notifyComponent(const BusMessage &msg);

  private:
  IBusInterface *m_interface;
  std::map<int,IComponent*> observer;
};

#endif
