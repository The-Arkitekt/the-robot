#ifndef SINGLETON_MESSAGE_BROKER_H
#define SINGLETON_MESSAGE_BROKER_H

#include "Observer.h"
#include "Topic.h"

class SingletonMessageBroker
{
public:

  static const uint64_t MAX_TOPICS;
  static const uint64_t MAX_OBSERVERS_PER_TOPIC;

  static void          killInstance();
  static const uint8_t numTopics();
  static void          registerObserver(char const * const topicName, Observer& observer);  
  static void          updateTopic(char const * const topicName, Message& message);

private:

  SingletonMessageBroker();
  ~SingletonMessageBroker();

  static void getInstance();

  static SingletonMessageBroker * instance;
  // TODO : implement hash map for topics list
  // utils::HashMap<char * const *, ArrayList<Observer> *> topics

};

#endif // SINGLETON_MESSAGE_BROKER_H
