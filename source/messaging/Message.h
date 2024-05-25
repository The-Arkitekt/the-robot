#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstdint>

class Message
{
public:

  virtual void                  init()                                                  = 0;
  virtual const uint32_t        size() const                                            = 0;
  virtual uint8_t const * const pack()                                                  = 0;
  virtual void                  unpack(uint8_t const * const data, const uint32_t size) = 0;

};

#endif // MESSAGE_H
