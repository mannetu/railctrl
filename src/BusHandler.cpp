
#include <iostream>
#include "BusHandler.h"

void BusHandler::sendMessage(const BusMessage &msg)
{
  m_interface->sendMsg(msg);
}
