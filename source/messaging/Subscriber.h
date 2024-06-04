#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Message.h"

class Subscriber
{
public:

  virtual const uint8_t numMessages() const             = 0;
  virtual void          update(Message& message)        = 0;
  virtual void          popLatest(Message& message)     = 0;
  virtual void          clear()                         = 0;
};


#endif // SUBSCRIBER_H
