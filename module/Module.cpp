
#include <iostream>
#include "Module.h"
#include "BusHandler.h"
#include "IBusInterface.h" // for class BusMessage??
#include "IComponent.h"
#include "Turnout.h"
#include "Sign.h"

Module::Module(BusHandler *busHandler) : m_busHandler(busHandler)
{
  putTogether();
}

bool Module::putTogether()
{
// >> for testing------------------
  addComponent("turnout");
  addComponent("sign");
// --------------------------<<<<<

  return 0;
}

bool Module::addComponent(std::string component)
{

  IComponent *newComponent;
  if (component == "turnout") newComponent = new Turnout(3, m_busHandler);
  if (component == "sign")    newComponent = new Sign(5, m_busHandler);

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

bool Module::pingComponents()
{
  for (int i = 0; i < turnoutsVector.size(); i++)
  {
    turnoutsVector.at(i)->ping();
  }
  for (int i = 0; i < signsVector.size(); i++)
  {
    signsVector.at(i)->ping();
  }
  return 0;
}
