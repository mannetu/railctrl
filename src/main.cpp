/*
Railctrl



*/

#include <iostream>
#include "IBusinterface.h"
#include "TestBusInterface.h"

int main(int argc, char const *argv[])
{
  IBusInterface *busInterface = new TestBusInterface::TestBusInterface();

  Busmessage msg;

  msg.id = 1000;
  msg.data[3] = 45;
  busInterface->sendMsg(msg);

  busInterface->receiveMsg(msg);

  busInterface->sendMsg(msg);

  return 0;
}
