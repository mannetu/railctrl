/*
Implementation of IBusinterface for Testing
*/

#include <iostream>
#include "BusHandler.h"
#include "TestBusInterface.h"


bool TestBusInterface::receiveMessage(BusMessage &msg)
{
  std::cout << "Input message:\n" << "ID: ? ";
  std::cin >> msg.id;
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Databyte " << i << " ? " << '\n';
    std::cin >> msg.data[i];
  }
  std::cout << '\n';
  m_busHandler->notifyComponent(msg);
  return 0;
}

bool TestBusInterface::sendMessage(const BusMessage &msg)
{
  std::cout << "Send message: Id " << msg.id;
  std::cout << "  Data: " << " ";
  for (size_t i = 0; i < 8; i++)
    {
      std::cout << msg.data[i]+0 << " | ";
    }
  std::cout << '\n';
  return 0;
}
