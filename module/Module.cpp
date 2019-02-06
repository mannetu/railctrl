
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
  ModuleLoader *moduleLoader = new ModuleLoader(busHandler);

  std::vector<ComponentImport> v_componentImport;
  moduleLoader->getComponents("module01config", v_componentImport);

  for (int i = 0; i < v_componentImport.size(); i++)
  {
    std::cout << v_componentImport.at(i).type << " / " << v_componentImport.at(i).label
      << " / " << v_componentImport.at(i).address << '\n';

    addComponent(v_componentImport.at(i).type, v_componentImport.at(i).label, v_componentImport.at(i).address)

  }

  return 0;
}

bool Module::addComponent(std::string type, std::string label, int address)
{

  IComponent *newComponent;
  if (type == "turnout") newComponent = new Turnout(label, address, m_busHandler);
  if (type == "sign")    newComponent = new Sign(label, address, m_busHandler);

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
