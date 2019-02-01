/*
Railctrl

*/

#include <iostream>

#include "TestBusInterface.h"
#include "IBusInterface.h"
#include "BusHandler.h"

int main(int argc, char const *argv[])
{
  IBusInterface *busInterface = new TestBusInterface::TestBusInterface();
  BusHandler *busHandler = new BusHandler::BusHandler();

  busHandler->setInterface(busInterface);
  busInterface->setBusHandler(busHandler);

  BusMessage msg;

  busHandler->sendMessage(msg);

  return 0;
}
