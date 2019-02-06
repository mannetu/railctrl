#include <iostream>
#include "Sign.h"
//#include "IBusInterface.h"

struct BusMessage;

bool Sign::update(const BusMessage &msg)
{
  std::cout << "Sign: Updating with address: " << msg.id+0 << '\n';
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Data " << i << " :" << msg.data[i] << '\n';
  }
  return 0;
}

void Sign::ping()
{
  std::cout << "Ping: Sign\t-" << m_label << "- \t Address: " << m_address << '\n';
}
