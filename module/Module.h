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

  bool putTogetherModule();
  bool addComponent(std::string component);

public:
  Module(BusHandler* busHandler);
  virtual ~Module() {};

  bool pingComponents();


};


#endif
