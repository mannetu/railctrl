/*
Railctrl

*/

#include <iostream>

#include "TestBusInterface.h"
#include "IBusInterface.h"
#include "BusHandler.h"
//#include "IComponent.h"
#include "Module.h"
//#include "Turnout.h"
//#include "Sign.h"

int main(int argc, char const *argv[])
{
  IBusInterface *busInterface = new TestBusInterface();
  BusHandler *busHandler = new BusHandler();

  busHandler->setInterface(busInterface);
  busInterface->setBusHandler(busHandler);

  Module *module1 = new Module(busHandler);
//  module1->addComponent("turnout", "Bahnhof");
//  module1->addComponent("sign", "Tunnel");
/*
  IComponent *turnout = new Turnout(3, busHandler);
  busHandler->registerComponent(turnout);
  IComponent *sign = new Sign(5, busHandler);
  busHandler->registerComponent(sign);
*/

  busHandler->listComponents();

  BusMessage msg;
  busInterface->notifyBusHandler(msg);

  //turnout->toggle();
  return 0;
}
