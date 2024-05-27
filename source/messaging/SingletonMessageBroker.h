#ifndef SINGLETON_MESSAGE_BROKER_H
#define SINGLETON_MESSAGE_BROKER_H

#include "Subscriber.h"
#include "Topic.h"

class SingletonMessageBroker
{
public:

  static const uint8_t MAX_TOPICS;

  static void          killInstance();
  static const uint8_t size();
  static void          registerSubscriber(char const * const topicName, Subscriber& subscriber);  
  static void          updateTopic(char const * const topicName, Message& message);

private:

  SingletonMessageBroker();
  ~SingletonMessageBroker();

  static void getInstance();

  static SingletonMessageBroker * instance;
  uint8_t                         numTopics;
  Topic **                        topics;

};

#endif // SINGLETON_MESSAGE_BROKER_H
