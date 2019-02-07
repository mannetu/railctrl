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
    newComponent = nullptr;
    newComponent = componentFactory.getComponent(
      vComponents.at(i).type,
      vComponents.at(i).label,
      vComponents.at(i).address);

    if (!newComponent) throw std::runtime_error("Module::load\n");
    newComponent->setBusHandler(m_busHandler);
    m_busHandler->registerComponent(newComponent);
    vModuleComponents.push_back(newComponent);
  }
  return 0;
}

bool Module::pingComponents()
{
  for (size_t i = 0; i < vModuleComponents.size(); i++)
    vModuleComponents.at(i)->ping();
  return 0;
}
