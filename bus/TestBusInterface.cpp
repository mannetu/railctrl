/*
Implementation of IBusinterface for Testing
*/

#include <iostream>
#include "BusMessage.h"
#include "TestBusInterface.h"
#include "BusHandler.h"

bool TestBusInterface::notifyBusHandler(BusMessage &msg)
{
  std::cout << "\nInput message:\n" << "ID: ? ";
  std::cin >> msg.id;
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Databyte " << i << " ? " << '\n';
    std::cin >> msg.data[i];
  }
  std::cout << '\n';
  m_busHandler->update(msg);
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
