
#include <iostream>
#include "Module.h"
#include "IComponent.h"
#include "Turnout.h"
#include "Sign.h"

bool Module::addComponent(std::string component, std::string name)
{
  IComponent *newComponent;
  if (component == "turnout") newComponent = new Turnout();
  if (component == "sign")    newComponent = new Turnout();

  if (newComponent != nullptr)
  {
    turnoutsVector.push_back(newComponent);
    return 0;
  }
  else
  {
    std::cerr << "Error: Component to add not available" << '\n';
    return 1;
  }

}

Module::Module()
{


}
