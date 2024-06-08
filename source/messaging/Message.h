#ifndef MESSAGING_MESSAGE_H
#define MESSAGING_MESSAGE_H

#include <cstdint>
#include "ArrayList.h"

namespace messaging
{

class Message
{
public:

  virtual void                      init()                                        = 0;
  virtual uint8_t                   identifier() const                            = 0;
  virtual utils::ArrayList<uint8_t> pack()                                        = 0;
  virtual void                      unpack(const utils::ArrayList<uint8_t>& data) = 0;

};

}

#endif // MESSAGING_MESSAGE_H
