#ifndef PUB_SUB_MESSAGE_H
#define PUB_SUB_MESSAGE_H

#include <cstdint>
#include "ArrayList.h"

namespace PubSub
{

class Message
{
public:

  virtual void                      initialize()                                  = 0;
  virtual unsigned int              getId() const                                 = 0;
  virtual Utils::ArrayList<uint8_t> pack()                                        = 0;
  virtual void                      unpack(const Utils::ArrayList<uint8_t>& data) = 0;

};

}

#endif // PUB_SUB_MESSAGE_H
