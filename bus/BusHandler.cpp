
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

}

void BusHandler::listComponents()
{
  std::cout << "registered Components: \n";
  for (auto itr = observer.begin(); itr != observer.end(); ++itr)
  {
    std::cout << itr->first << '\t';
    (itr->second)->update();
  }
}

void BusHandler::registerComponent(IComponent *component)
{
  observer.insert({component->getAddress(), component});
}
