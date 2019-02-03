/*
Railctrl

*/

#include <iostream>

#include "TestBusInterface.h"
#include "IBusInterface.h"
#include "BusHandler.h"
#include "IComponent.h"
#include "Turnout.h"
#include "Sign.h"

int main(int argc, char const *argv[])
{
  IBusInterface *busInterface = new TestBusInterface();
  BusHandler *busHandler = new BusHandler();

  busHandler->setInterface(busInterface);
  busInterface->setBusHandler(busHandler);


  IComponent *turnout = new Turnout(3, busHandler);
  busHandler->registerComponent(turnout);
  IComponent *sign = new Sign(5, busHandler);
  busHandler->registerComponent(sign);

  busHandler->listComponents();

  BusMessage msg;
  busInterface->notifyBusHandler(msg);

  turnout->toggle();


  return 0;
}
#sdf
