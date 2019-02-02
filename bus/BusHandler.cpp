
#include <iostream>
#include "BusHandler.h"

void BusHandler::sendMessage(const BusMessage &msg)
{
  m_interface->sendMsg(msg);
}

void BusHandler::notifyComponent(const BusMessage &msg)
{
  std::cout << "registered Components: \n";
  for (auto itr = observer.begin(); itr != observer.end(); ++itr)
  {
    std::cout << itr->first << '\t' << itr->second << '\n';
  }
}

void BusHandler::registerComponent(IComponent *component)
{
  observer.insert({component->getAddress(), component});
}
