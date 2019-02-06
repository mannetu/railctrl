#ifndef COMPONENTFACTORY
#define COMPONENTFACTORY

#include <string>

class IComponent;

class ComponentFactory
{
  public:
  ComponentFactory();
  IComponent* getComponent(std::string type, std::string label, int address);
};


#endif
