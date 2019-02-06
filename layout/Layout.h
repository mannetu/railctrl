#ifndef LAYOUT_H
#define LAYOUT_H

#include <string>
#include <vector>

class BusHandler;
class Module;

class Layout
{
private:
  BusHandler *m_busHandler;
  std::vector<Module*> vModule;

  bool addModule(std::string configFile);

public:
  Layout(BusHandler* busHandler);
  virtual ~Layout() {};
  bool setup();
  bool pingComponents();


};


#endif
