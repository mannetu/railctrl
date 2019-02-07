//  Module.cpp
//
//
//

#include <iostream>
#include "Module.h"
#include "BusMessage.h"
#include "IComponent.h"
#include "ComponentFactory.h"
#include "BusHandler.h"
#include "Moduleloader.h"

Module::Module(BusHandler *busHandler) : m_busHandler(busHandler)
{}

bool Module::load(std::string configFile)
{
  ModuleLoader moduleLoader = ModuleLoader();
  std::vector<ComponentImport> vComponents;
  moduleLoader.getComponents(configFile, vComponents);

  ComponentFactory componentFactory = ComponentFactory();
  IComponent *newComponent = nullptr;

  for (size_t i = 0; i < vComponents.size(); i++)
  {
    newComponent = componentFactory.getComponent(
      vComponents.at(i).type,
      vComponents.at(i).label,
      vComponents.at(i).address);

    newComponent->setBusHandler(m_busHandler);
    turnoutsVector.push_back(newComponent);
    m_busHandler->registerComponent(newComponent);
  }
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
