
#include <iostream>
#include "IBusInterface.h"
#include "BusHandler.h"
#include "IComponent.h"

void BusHandler::sendMessage(const BusMessage &msg)
{
  m_interface->sendMessage(msg);
}

void BusHandler::update(const BusMessage &msg)
{
  notifyComponents(msg);
}

void BusHandler::notifyComponents(const BusMessage &msg)
{
  int address = int(msg.id);
  auto itr = observer.find(address);
  if (itr != observer.end())
  {
    std::cout << "BusHandler: Notifiying component with address: "<< address << '\n';
    (itr->second)->update(msg);
  }
  else
    std::cout << "BusHandler: Component not found" << '\n';
}

void BusHandler::listComponents()
{
  std::cout << "BusHandler: Registered Components: \n";
  for (auto itr = observer.begin(); itr != observer.end(); ++itr)
    (itr->second)->ping();
}

void BusHandler::registerComponent(IComponent *component)
{
  observer.insert({component->getAddress(), component});
}
