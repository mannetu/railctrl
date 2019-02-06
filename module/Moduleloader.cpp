
#include <string>
#include <iostream>
#include <fstream>
#include "Moduleloader.h"
#include "BusHandler.h"
#include "IBusInterface.h" // for class BusMessage??
#include "IComponent.h"


std::vector<ComponentImport> v_componentImport;

ModuleLoader::ModuleLoader()
{
}

bool ModuleLoader::getComponents(const std::string &fileName, std::vector<ComponentImport> &v_componentImport)
{
  std::ifstream fileStream;
  fileStream.open(fileName, std::ios::in);
  if (!fileStream.is_open())
  {
    std::cout << "file not found" << '\n';
    return 1;
  }

  while (!fileStream.eof())
  {
    ComponentImport componentImport{"","",0};
    std::string line;
    int address = 0;
    fileStream >> line;

    if (line[0] == '#')
    {
      std::string comment;
      getline(fileStream, comment);
    //  std::cout << "Comment: " << comment << '\n';
    }
    else
    {
      componentImport.type = line;

      fileStream >> line;
      componentImport.label = line;

      fileStream >> address;
      if (!fileStream.good()) break;
      componentImport.address = address;

      fileStream.ignore(256,'\n');

      if (componentImport.type != "")
      {
        v_componentImport.push_back(componentImport);
      //  std::cout << componentImport.type << " / " << componentImport.label
      //    << " / " << componentImport.address << '\n';
      }
    }
  }
  fileStream.close();
  return 0;
}
