

#include "ComponentFactory.h"
#include "IComponent.h"
#include "Turnout.h"
#include "Sign.h"
#include "Track.h"


IComponent* ComponentFactory::getComponent(std::string type, std::string label, int address)
{
  IComponent* newComponent = nullptr;
  if (type == "Turnout") newComponent = new Turnout(label, address+1000);
  if (type == "Sign")    newComponent = new Sign(label, address+2000);
  if (type == "Track")  newComponent = new Track(label, address+3000);

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
