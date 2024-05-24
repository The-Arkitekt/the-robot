#IFNDEF SINGLETON_BROKER_SUBSCRIBER_H
#DEFINE SINGLETON_BROKER_SUBSCRIBER_H

#include "Subscriber.h"
#include "ByteString.h"

class SingletonBrokerSubscriber : public Subscriber
{
public:

  static const uint8_t MAX_MESSAGES_PER_SUBSCRIBER;

  SingletonBrokerSubscriber(char const * const topicName);
  ~SingletonBrokerSubscriber();

  const uint8_t size() const;
  void          push(Message& message);
  void          pop(Message& message);
  void          clear();

private:

  uint8_t       numMessages;
  ByteString ** messagesData;
}

#ENDIF // SINGLETON_BROKER_SUBSCRIBER_H
