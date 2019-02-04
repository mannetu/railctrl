#ifndef MODULE_H
#define MODULE_H

#include <vector>
#include <string>

class IComponent;

class Module
{
private:
  std::vector<IComponent*> turnoutsVector;
  std::vector<IComponent*> signsVector;

  bool addComponent(std::string component, std::string name);

public:
  Module ();
  virtual ~Module ();

};


#endif
