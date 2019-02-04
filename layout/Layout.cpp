
#include <iostream>
#include "Layout.h"
#include "Module.h"
#include "BusHandler.h"


Layout::Layout(BusHandler *busHandler) : m_busHandler(busHandler)
{
  addModule();
};

bool Layout::setup(std::string configFile)
{
  //load config_File and parse to setup modules containing components
  return 0;
}

bool Layout::addModule()
{
// >> for testing------------------
  Module *module01 = new Module(m_busHandler);
  vModule.push_back(module01);
// --------------------------<<<<<

  return 0;
}

bool Layout::pingComponents()
{
  for (int i = 0; i < vModule.size(); i++)
  {
    vModule.at(i)->pingComponents();
  }
  return 0;
}
