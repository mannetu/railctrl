/*
Compile from directory railctrl with

g++ ./src/main.cpp ./module/Moduleloader.cpp -I ./bus/ -I ./components/ -I ./module/ --std=c++11

*/

#include "string"
#include "Moduleloader.h"
#include "BusHandler.h"

int main(int argc, char const *argv[])
{
  BusHandler *busHandler = new BusHandler();

  ModuleLoader *moduleLoader = new ModuleLoader(busHandler);
  moduleLoader->getModuleComponents("module01config");

  return 0;
}
