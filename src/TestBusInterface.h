#ifndef TESTBUSINTERFACE_H
#define TESTBUSINTERFACE_H

/*
Implementation of IBusinterface for Testing
*/

#include <iostream>


class TestBusInterface : public IBusInterface
{
  public:
  bool receiveMsg(Busmessage &msg) override;
  bool sendMsg(const Busmessage &msg) override;

};


#endif
