#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <vector>


class IComponent;


enum lineReturnCode {IS_OK, IS_COMMENT};

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
