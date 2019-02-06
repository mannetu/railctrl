
#include <iostream>
#include "BusMessage.h"
#include "Turnout.h"

bool Turnout::update(const BusMessage &msg)
{
  std::cout << "Turnout: Updating with address: " << msg.id+0 << '\n';
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Data " << i << " :" << msg.data[i] << '\n';
  }
  return 0;
}

void Turnout::ping()
{
  std::cout << "Ping: Turnout\t-" << m_label << "- \t Address: " << m_address << '\n';
}

void Turnout::toggle()
{
  BusMessage msg;
  msg.id = m_address;
  msg.data[0] = 1000;
  sendMessage(msg);
};
