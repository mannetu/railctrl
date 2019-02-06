
#include <string>
#include <iostream>
#include <fstream>
#include "Moduleloader.h"
#include "BusHandler.h"
#include "IBusInterface.h" // for class BusMessage??
#include "IComponent.h"


bool ModuleLoader::getComponents(const std::string &fileName, std::vector<ComponentImport> &v_componentImport)
{
  std::ifstream fileStream;
  fileStream.open(fileName, std::ios::in);
  if (!fileStream.is_open())
  {
    throw std::runtime_error("ModuleLoader::getComponents: File "
      + fileName + " not found" + '\n');
  }

  while (!fileStream.eof())
  {
    ComponentImport componentImport{"","",0};
    std::string line;
    fileStream >> line;

    if (line[0] == '#')
    {
      std::string comment;
      getline(fileStream, comment);
    }
    else
    {
      componentImport.type = line;

      fileStream >> line;
      componentImport.label = line;

      int address = 0;
      fileStream >> address;
      if (!fileStream.good()) break;
      componentImport.address = address;

      fileStream.ignore(256,'\n');

      if (componentImport.type != "")
      {
        v_componentImport.push_back(componentImport);
      }
    }
  }
  fileStream.close();
  return 0;
}
