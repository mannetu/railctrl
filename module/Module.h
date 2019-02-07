#ifndef MODULE_H
#define MODULE_H

#include <vector>
#include <string>

class BusHandler;
class IComponent;

class Module
{
private:
  BusHandler *m_busHandler;

  std::vector<IComponent*> turnoutsVector;
  std::vector<IComponent*> signsVector;

public:
  Module(BusHandler* busHandler);

  bool load(std::string configFile);

  bool pingComponents();
};


#endif
