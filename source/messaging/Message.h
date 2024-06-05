#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstdint>
#include "ArrayList.h"

class Message
{
public:

  virtual void                      init()                                 = 0;
  virtual const uint16_t            identifier() const                     = 0;
  virtual const uint32_t            size() const                           = 0;
  virtual const ArrayList<uint8_t>& pack()                                 = 0;
  virtual void                      unpack(const ArrayList<uint8_t>& data) = 0;

};

#endif // MESSAGE_H
