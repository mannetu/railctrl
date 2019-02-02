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
  IBusInterface *busInterface = new TestBusInterface::TestBusInterface();
  BusHandler *busHandler = new BusHandler::BusHandler();

  busHandler->setInterface(busInterface);
  busInterface->setBusHandler(busHandler);

  BusMessage msg;

  IComponent *turnout = new Turnout::Turnout(3, busHandler);
  busHandler->registerComponent(turnout);

  IComponent *sign = new Sign::Sign(5, busHandler);
  busHandler->registerComponent(sign);

  busHandler->listComponents();

  busInterface->receiveMessage(msg);

  //turnout->sendMessage(msg);
  //sign->sendMessage(msg);

  return 0;
}
