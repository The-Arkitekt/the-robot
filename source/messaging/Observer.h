#ifndef OBSERVER_H
#define OBSERVER_H

#include "Message.h"

namespace messaging
{

class Observer
{
public:

  virtual void update(Message& message) = 0;

};

}

#endif // OBSERVER_H
