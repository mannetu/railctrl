#ifndef TRACKS_H
#define TRACKS_H

#include <iostream>
#include "IComponent.h"

struct BusMessage;

class Track : public IComponent
{
  public:
  Track(std::string label, int address)
    : IComponent(label, address) {};

  bool update(const BusMessage &msg) override;
  void ping() override;
  void toggle() override;
  int  getStatus() override;
};

#endif
