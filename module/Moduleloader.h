#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <vector>

class BusHandler;
class IComponent;


enum lineReturnCode {IS_OK, IS_COMMENT};

struct ComponentImport
{
  std::string type;
  std::string label;
  int address;
};
/*
struct ModuleComponents
{
  std::vector<IComponent*> turnoutsVector;
  std::vector<IComponent*> signsVector;
};
*/
class ModuleLoader
{
  private:
  BusHandler *m_busHandler;

  public:
  ModuleLoader(BusHandler *busHandler);
  bool getComponents(const std::string &fileName, std::vector<ComponentImport> &v_componentImport);
};


#endif
