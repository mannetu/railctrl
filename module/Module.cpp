
#include <iostream>
#include "Module.h"
#include "BusHandler.h"
#include "Moduleloader.h"
#include "IBusInterface.h" // for class BusMessage??
#include "IComponent.h"
#include "Turnout.h"
#include "Sign.h"

Module::Module(BusHandler *busHandler) : m_busHandler(busHandler)
{}

bool Module::load(std::string configFile)
{
  ModuleLoader *moduleLoader = new ModuleLoader();

  std::vector<ComponentImport> v_componentImport;
  moduleLoader->getComponents(configFile, v_componentImport);

  for (size_t i = 0; i < v_componentImport.size(); i++)
  {
    addComponent(v_componentImport.at(i).type, v_componentImport.at(i).label, v_componentImport.at(i).address);
  }

  return 0;
}

bool Module::addComponent(std::string type, std::string label, int address)
{
  IComponent *newComponent = nullptr;
  if (type == "Turnout") newComponent = new Turnout(label, address, m_busHandler);
  if (type == "Sign")    newComponent = new Sign(label, address, m_busHandler);

  if (newComponent != nullptr)
  {
    turnoutsVector.push_back(newComponent);
    m_busHandler->registerComponent(newComponent);
    return 0;
  }
  else
  {
    std::cerr << "Error: Component type -" << type << "- is unknown" << '\n';
    return 1;
  }

}

bool Module::pingComponents()
{
  for (size_t i = 0; i < turnoutsVector.size(); i++)
  {
    turnoutsVector.at(i)->ping();
  }
  for (size_t i = 0; i < signsVector.size(); i++)
  {
    signsVector.at(i)->ping();
  }
  return 0;
}
