//  Module.cpp
//
//
//

#include <iostream>
#include "Module.h"
#include "BusHandler.h"
#include "Moduleloader.h"
//#include "IBusInterface.h" // for class BusMessage??
#include "BusMessage.h"
#include "IComponent.h"
#include "ComponentFactory.h"

Module::Module(BusHandler *busHandler) : m_busHandler(busHandler)
{}

bool Module::load(std::string configFile)
{
  ModuleLoader moduleLoader = ModuleLoader();
  std::vector<ComponentImport> v_componentImport;
  moduleLoader.getComponents(configFile, v_componentImport);
  for (size_t i = 0; i < v_componentImport.size(); i++)
  {
    addComponent(v_componentImport.at(i).type, v_componentImport.at(i).label,
      v_componentImport.at(i).address);
  }
  return 0;
}

bool Module::addComponent(std::string type, std::string label, int address)
{
  ComponentFactory componentFactory = ComponentFactory();
  IComponent *newComponent = nullptr;
  newComponent = componentFactory.getComponent(type, label, address);
  newComponent->setBusHandler(m_busHandler);

  turnoutsVector.push_back(newComponent);
  m_busHandler->registerComponent(newComponent);
  return 0;

}

bool Module::pingComponents()
{
  for (size_t i = 0; i < turnoutsVector.size(); i++)
    turnoutsVector.at(i)->ping();

  for (size_t i = 0; i < signsVector.size(); i++)
    signsVector.at(i)->ping();

  return 0;
}
