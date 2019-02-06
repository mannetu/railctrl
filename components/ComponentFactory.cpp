

#include "IComponent.h"
#include "ComponentFactory.h"
#include "Turnout.h"
#include "Sign.h"


IComponent* ComponentFactory::getComponent(std::string type)
{
  IComponent* newComponent = nullptr;
  if (type == "Turnout") newComponent = new Turnout(label, address, m_busHandler);
  if (type == "Sign")    newComponent = new Sign(label, address, m_busHandler);

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
