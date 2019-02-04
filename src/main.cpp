/*
Railctrl

*/

#include <iostream>

#include "IBusInterface.h"
#include "TestBusInterface.h"
#include "BusHandler.h"
#include "Module.h"

int main(int argc, char const *argv[])
{
  IBusInterface *busInterface = new TestBusInterface();
  BusHandler *busHandler = new BusHandler();

  busHandler->setInterface(busInterface);
  busInterface->setBusHandler(busHandler);

  Module *module01 = new Module(busHandler);

  busHandler->listComponents();

/*
  Only for testing. Later put as method into IbusInterface.
  Will be called once physical message arrives
*/
  //BusMessage msg;
  //busInterface->notifyBusHandler(msg);


  module01->pingComponents();

  return 0;
}
