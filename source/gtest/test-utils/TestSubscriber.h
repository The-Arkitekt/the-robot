#ifndef TEST_SUBSCRIBER_H
#define TEST_SUBSCRIBER_H

#include "Subscriber.h"

class TestSubscriber : public Subscriber
{
public:

  TestSubscriber();
  ~TestSubscriber();

  const uint8_t size() const;
  void          push(Message& message);
  void          pop(Message& message);
  void          clear();

  const uint8_t * messageData;
};

#endif // TEST_SUBSCRIBER_H
