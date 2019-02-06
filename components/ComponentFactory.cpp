

#include "ComponentFactory.h"
#include "IComponent.h"
#include "Turnout.h"
#include "Sign.h"


ComponentFactory::ComponentFactory() {};


IComponent* ComponentFactory::getComponent(std::string type, std::string label, int address)
{
  IComponent* newComponent = nullptr;
  if (type == "Turnout") newComponent = new Turnout(label, address);
  if (type == "Sign")    newComponent = new Sign(label, address);

  if (newComponent != nullptr)
  {
    return newComponent;
  }
  else
  {
    throw std::runtime_error("ComponentFactory::getComponent: Component type -" + type + "- is unknown" + '\n');
  }
  return 0;
};
