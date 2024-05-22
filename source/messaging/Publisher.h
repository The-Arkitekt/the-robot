#IFNDEF PUBLISHER_H
#DEFINE PUBLISHER_H

#include "Message.h"

class Publisher
{
public:

  virtual void setTopic(char const * const topicName)  = 0;
  virtual void publish (const Message& message)        = 0;

}

#ENDIF // PUBLISHER_H
