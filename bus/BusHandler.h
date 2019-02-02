#ifndef BUSHANDLER_H
#define BUSHANDLER_H

#include <map>

struct BusMessage;
class  IBusInterface;
class  IComponent;

class BusHandler
{
  public:
  // Set concrete BusInterface object used by BusHandler
  // to send messages into physical bus
  void setInterface(IBusInterface *interface) {m_interface = interface;}

  // Register component so that it can be notified once message arrives on bus
  void registerComponent(IComponent*);

  // Prints out list of registered components
  void listComponents();

  // Sends a message into physical bus
  void sendMessage(const BusMessage &msg);

  // Sends a message to the BusHandler (e.g. called by IBusInterface
  // once a new message arrives)
  void update(const BusMessage &msg);

  private:
  // BusInterface controling the physical bus
  IBusInterface *m_interface;

  // Container registering component information as (address, 'ptr to object')
  std::map<int,IComponent*> observer;

  // Notifies the component object registered under the address
  void notifyComponents(const BusMessage &msg);
};

#endif
