#ifndef IBUSINTERFACE_H
#define IBUSINTERFACE_H

/*
Interface class for low-level bus controllers
(e.g. CAN bus)
*/

#include <cstdint>
//#include "Bushandler.h"

struct Busmessage
{
  int id = 0;
  int data[8] = {0,0,0,0,0,0,0,0}; // cout type with "+0"
};

class IBusInterface
{
  public:
  virtual bool receiveMsg(Busmessage &msg) = 0;
  virtual bool sendMsg(const Busmessage &msg) = 0;
  virtual ~IBusInterface() {};
  private:
  //Bushandler &Bushandler;
};


#endif
