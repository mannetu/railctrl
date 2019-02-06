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

  bool putTogether();
  bool addComponent(std::string type, std::string label, int address);

public:
  Module(BusHandler* busHandler);
  virtual ~Module() {};

  bool pingComponents();


};


#endif
