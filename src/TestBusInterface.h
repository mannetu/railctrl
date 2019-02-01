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
  bool receiveMsg(BusMessage &msg) override;
  bool sendMsg(const BusMessage &msg) override;
};


#endif
