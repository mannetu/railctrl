
#include <iostream>
#include "IBusInterface.h"
#include "BusHandler.h"
#include "IComponent.h"

void BusHandler::sendMessage(const BusMessage &msg)
{
  m_interface->sendMessage(msg);
}

void BusHandler::notifyComponent(const BusMessage &msg)
{
  int address = msg.id;
  std::cout << msg.id+0 << '\n';
  auto itr = observer.find(address);
  if (itr == observer.end()) {
    std::cout << "not found" << '\n';
  } else {
    std::cout << "found" << '\n';
  }
}

void BusHandler::listComponents()
{
  std::cout << "registered Components: \n";
  for (auto itr = observer.begin(); itr != observer.end(); ++itr)
  {
    (itr->second)->ping(itr->first);
  }
}

void BusHandler::registerComponent(IComponent *component)
{
  observer.insert({component->getAddress(), component});
}
