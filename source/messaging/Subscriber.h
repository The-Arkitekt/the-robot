#IFNDEF SUBSCRIBER_H
#DEFINE SUBSCRIBER_H

#include "Message.h"

class Subscriber
{
public:

  static const uint8_t MAX_MESSAGES_PER_SUBSCRIBER = 255U;

  virtual const uint8_t size() const                       = 0;
  virtual void          push(Message& message)             = 0;
  virtual void          pop(Message& message)              = 0;
  virtual void          clear()                            = 0;

}


#ENDIF // SUBSCRIBER_H
