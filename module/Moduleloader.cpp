
#include <string>
#include <iostream>
#include <fstream>
#include "Moduleloader.h"
#include "BusHandler.h"
#include "IBusInterface.h" // for class BusMessage??
#include "IComponent.h"

/*
struct ModuleComponents
{
  std::vector<IComponent*> turnoutsVector;
  std::vector<IComponent*> signsVector;
}
*/

ModuleLoader::ModuleLoader(BusHandler *busHandler) : m_busHandler(busHandler)
{
}

bool ModuleLoader::getModuleComponents(const std::string &fileName)
{
  std::ifstream fileStream;
  fileStream.open(fileName, std::ios::in);
  if (!fileStream.is_open())
  {
    std::cout << "file not found" << '\n';
    return 1;
  }

  ComponentInfo componentInfo;

  while (!fileStream.eof())
  {
    std::string line;
    std::getline(fileStream, line, ',');
    if (line[0] == '#') std::cout << "Comment: " << line << '\n';
    else
    {
      componentInfo.type = line;
      std::getline(fileStream, line, ',');
      componentInfo.label = line;
      std::cout << componentInfo.type << " / " << componentInfo.label << '\n';
    }
  }
  fileStream.close();
  return 0;
}
