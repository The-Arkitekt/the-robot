#ifndef TEST_SUBSCRIBER_H
#define TEST_SUBSCRIBER_H

#include "Subscriber.h"

class TestSubscriber : public Subscriber
{
public:

  TestSubscriber();
  ~TestSubscriber();

  const uint8_t numMessages() const;
  void          update(Message& message);
  void          popLatest(Message& message);
  void          clear();

  uint8_t * messageData;
};

#endif // TEST_SUBSCRIBER_H
