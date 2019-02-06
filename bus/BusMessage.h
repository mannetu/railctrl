#ifndef BUSMESSAGE_H
#define BUSMESSAGE_H

struct BusMessage
{
  int id      = 0;
  int data[8] = {0,0,0,0,0,0,0,0}; // cout type with "+0"
};


#endif
