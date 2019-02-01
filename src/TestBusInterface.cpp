/*
Implementation of IBusinterface for Testing
*/

#include <iostream>
#include "IBusinterface.h"
#include "TestBusInterface.h"



bool TestBusInterface::receiveMsg(Busmessage &msg)
{
  std::cout << "Input message:\n" << "ID: ? ";
  std::cin >> msg.id;
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Databyte " << i << " ? " << '\n';
    std::cin >> msg.data[i];
  }
  std::cout << '\n';
  return 0;
}

bool TestBusInterface::sendMsg(const Busmessage &msg)
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
