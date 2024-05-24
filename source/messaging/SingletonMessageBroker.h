#ifndef SINGLETON_MESSAGE_BROKER_H
#define SINGLETON_MESSAGE_BROKER_H

#include "Subscriber.h"
#include "Topic.h"

class SingletonMessageBroker
{
public:

  static const uint8_t MAX_TOPICS;

  static SingletonMessageBroker * const getInstance();
  static void                           killInstance();

  const uint8_t numTopics() const;

  void register(char const * const topicName, Subscriber& subscriber);  
  void update(char const * const topicName, Message& message) const;

private:

  SingletonMessageBroker();
  ~SingletonMessageBroker();

  SingletonMessageBroker * instance;
  uint8_t                  numTopics;
  Topic **                 topics;
}

#endif // SINGLETON_MESSAGE_BROKER_H
