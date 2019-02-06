#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <string>
#include <vector>


struct ComponentImport
{
  std::string type;
  std::string label;
  int address;
};


class ModuleLoader
{
  public:
  ModuleLoader() {};
  bool getComponents(const std::string &fileName, std::vector<ComponentImport> &v_componentImport);
};


#endif
