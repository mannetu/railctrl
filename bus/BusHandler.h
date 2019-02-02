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
  // Register component so that it can be notified once message arrives on bus
  void registerComponent(IComponent*);
  // Prints out list of registered components
  void listComponents();

  // Send message into physical bus
  void sendMessage(const BusMessage &msg);
  // Called by bus interface when new message arrives on physical bus
  void update(const BusMessage &msg);

  private:
  IBusInterface *m_interface;
  std::map<int,IComponent*> observer;

  // Notify the component object registered under the address
  void notifyComponents(const BusMessage &msg);
};

#endif
