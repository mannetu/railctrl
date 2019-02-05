#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <vector>

class BusHandler;
class IComponent;


enum lineReturnCode {IS_OK, IS_COMMENT};

struct ComponentInfo
{
  std::string type;
  std::string label;
};

struct ModuleComponents
{
  std::vector<IComponent*> turnoutsVector;
  std::vector<IComponent*> signsVector;
};

class ModuleLoader
{
  private:
  BusHandler *m_busHandler;
  lineReturnCode getLine(ComponentInfo &componentInfo, std::ifstream &fileStream);

  public:
  ModuleLoader(BusHandler *busHandler);
  bool getModuleComponents(const std::string &fileName);
};


#endif
