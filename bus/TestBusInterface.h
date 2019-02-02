#ifndef TESTBUSINTERFACE_H
#define TESTBUSINTERFACE_H

/*
Implementation of IBusinterface for testing purpose
*/

#include <iostream>
#include "IBusInterface.h"


class TestBusInterface : public IBusInterface
{
  public:
  //bool receiveMessage(BusMessage &msg) override;
  bool sendMessage(const BusMessage &msg) override;

  public:
  bool notifyBusHandler(BusMessage &msg) override;


};


#endif
