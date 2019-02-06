/*
Compile from directory railctrl with

g++ ./src/main.cpp ./module/Moduleloader.cpp -I ./bus/ -I ./components/ -I ./module/ --std=c++11

*/

#include <iostream>
#include "string"
#include "Moduleloader.h"
#include "BusHandler.h"

int main(int argc, char const *argv[])
{
  BusHandler *busHandler = new BusHandler();

  ModuleLoader *moduleLoader = new ModuleLoader(busHandler);

  std::vector<ComponentImport> v_componentImport;
  moduleLoader->getComponents("module01config", v_componentImport);



  for (int i = 0; i < v_componentImport.size(); i++)
  {
    std::cout << v_componentImport.at(i).type << " / " << v_componentImport.at(i).label
      << " / " << v_componentImport.at(i).address << '\n';
  }


  return 0;
}
