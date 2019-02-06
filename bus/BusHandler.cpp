
#include <iostream>
#include "BusMessage.h"
#include "BusHandler.h"
#include "IBusInterface.h"
#include "IComponent.h"

//------------------------------------------------------------------
// public
//------------------------------------------------------------------
void BusHandler::registerComponent(IComponent *component)
{
  observer.insert({component->getAddress(), component});
}

//------------------------------------------------------------------
void BusHandler::listComponents()
{
  std::cout << "BusHandler: Registered Components: \n";
  for (auto itr = observer.begin(); itr != observer.end(); ++itr)
    (itr->second)->ping();
}

//------------------------------------------------------------------
void BusHandler::sendMessage(const BusMessage &msg)
{
  m_interface->sendMessage(msg);
}

//------------------------------------------------------------------
void BusHandler::update(const BusMessage &msg)
{
  notifyComponents(msg);
}

//------------------------------------------------------------------
// private
//------------------------------------------------------------------
void BusHandler::notifyComponents(const BusMessage &msg)
{
  int address = int(msg.id);
  auto itr = observer.find(address);
  if (itr != observer.end())
  {
    std::cout << "BusHandler: Notifiying component with address: "
              << address << '\n';
    (itr->second)->update(msg);
  }
  else
    std::cerr << "BusHandler: Component not found" << '\n';
}
