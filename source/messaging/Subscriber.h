#IFNDEF SUBSCRIBER_H
#DEFINE SUBSCRIBER_H

#include "Message.h"

class Subscriber
{
public:

  virtual void          setTopic(char * const * topicName) = 0;
  virtual void          setCapacity(const uint8_t cap)     = 0;
  virtual const uint8_t capacity() const                   = 0;
  virtual const uint8_t size() const                       = 0;
  virtual void          push(Message& message)             = 0;
  virtual void          pop(Message& message)              = 0;
  virtual void          clear()                            = 0;

}


#ENDIF // SUBSCRIBER_H
