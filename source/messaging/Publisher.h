#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Message.h"

class Publisher
{
public:

  virtual void publish(const Message& message) = 0;

}

#endif // PUBLISHER_H
