/*
Railctrl

*/

#include <iostream>

#include "IBusInterface.h"
#include "TestBusInterface.h"
#include "BusHandler.h"
#include "Layout.h"

int main(int argc, char const *argv[])
{
  IBusInterface *busInterface = new TestBusInterface();
  BusHandler *busHandler = new BusHandler();

  busHandler->setInterface(busInterface);
  busInterface->setBusHandler(busHandler);

  Layout *layout = new Layout(busHandler);
  layout->setup();

  //layout->pingComponents();

  busHandler->listComponents();

//*
  // Only for testing. Later put as method into IbusInterface.
  // Will be called once physical message arrives
  //BusMessage msg;
  //busInterface->notifyBusHandler(msg);
//*/

  return 0;
}
