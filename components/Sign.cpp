#include <iostream>
#include "BusMessage.h"
#include "Sign.h"

bool Sign::update(const BusMessage &msg)
{
std::cout << "Sign: " << m_label << " . Address: " << msg.id+0 << " - updating data:\n";
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Data " << i << ": " << msg.data[i] << '\n';
  }
  return 0;
}

void Sign::ping()
{
  std::cout << "Ping: Sign\t-" << m_label << "- \t Address: " << m_address
            << " \t Status: "<< m_status << '\n';
}

int Sign::getStatus()
{
  return m_status;
};
