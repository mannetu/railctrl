
#include <iostream>
#include "Module.h"
#include "BusHandler.h"
#include "IBusInterface.h" // wegen BusMessage class auslagern
#include "IComponent.h"
#include "Turnout.h"
#include "Sign.h"

Module::Module(BusHandler *busHandler) : m_busHandler(busHandler)
{
  putTogetherModule();
}

bool Module::putTogetherModule()
{
  addComponent("turnout", "Bahnhof");
  addComponent("sign", "Tunnel");
  return 0;
}

bool Module::addComponent(std::string component, std::string name)
{
  int address = 32;
  IComponent *newComponent;
  if (component == "turnout") newComponent = new Turnout(address, m_busHandler);
  if (component == "sign")    newComponent = new Sign(address, m_busHandler);

  if (newComponent != nullptr)
  {
    turnoutsVector.push_back(newComponent);
    m_busHandler->registerComponent(newComponent);
    return 0;
  }
  else
  {
    std::cerr << "Error: Component to add not available" << '\n';
    return 1;
  }

}
