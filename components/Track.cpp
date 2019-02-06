
#include <iostream>
#include "BusMessage.h"
#include "Track.h"

bool Track::update(const BusMessage &msg)
{
  std::cout << "Tracks: " << m_label << " . Address: " << msg.id+0 << " - updating data:\n";
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "Data " << i << ": " << msg.data[i] << '\n';
  }
  return 0;
}

void Track::ping()
{
  std::cout << "Ping: Track\t-" << m_label << "- \t Address: " << m_address << '\n';
}

void Track::toggle()
{
  BusMessage msg;
  msg.id = m_address;
  msg.data[0] = 1000;
  sendMessage(msg);
};
