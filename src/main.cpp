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



  busHandler->listComponents();

/*
  Only for testing. Later put as method into IbusInterface.
  Will be called once physical message arrives
*/
  //BusMessage msg;
  //busInterface->notifyBusHandler(msg);

  Layout *layout = new Layout(busHandler);
  layout->pingComponents();

  return 0;
}
