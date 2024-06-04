#ifndef SINGLETON_BROKER_SUBSCRIBER_H
#define SINGLETON_BROKER_SUBSCRIBER_H

#include "Subscriber.h"
#include "Queue.h"

class SingletonBrokerSubscriber : public Subscriber
{
public:

  SingletonBrokerSubscriber(char const * const topicName, const uint8_t capacity);
  ~SingletonBrokerSubscriber();

  const uint8_t numMessages() const;
  void          update(Message& message);
  void          popLatest(Message& message);
  void          clear();

private:

  const uint8_t capacity;
  Queue         byteStrings;
};

#endif // SINGLETON_BROKER_SUBSCRIBER_H
