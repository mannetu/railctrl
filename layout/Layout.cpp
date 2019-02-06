
#include <iostream>
#include "Layout.h"
#include "Module.h"
#include "BusHandler.h"


Layout::Layout(BusHandler *busHandler) : m_busHandler(busHandler)
{};

bool Layout::setup()
{
  addModule();
  return 0;
}

bool Layout::addModule()
{
  Module *newModule = new Module(m_busHandler);
  newModule->load("module01config");
  vModule.push_back(newModule);
  return 0;
}

bool Layout::pingComponents()
{
  for (size_t i = 0; i < vModule.size(); i++)
  {
    vModule.at(i)->pingComponents();
  }
  return 0;
}
