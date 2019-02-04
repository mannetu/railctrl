#ifndef LAYOUT_H
#define LAYOUT_H

#include <vector>

class BusHandler;
class Module;

class Layout
{
private:
  BusHandler *m_busHandler;
  std::vector<Module*> vModule;

  bool testPutTogether();

public:
  Layout(BusHandler* busHandler);
  virtual ~Layout() {};
  bool setup(std::string configFile);
  bool pingComponents();


};


#endif
