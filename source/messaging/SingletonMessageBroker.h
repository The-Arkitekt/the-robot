#ifndef MESSAGING_SINGLETON_MESSAGE_BROKER_H
#define MESSAGING_SINGLETON_MESSAGE_BROKER_H

#include "Topics.h"
#include "Message.h"
#include "Observer.h"
#include "HashMap.h"
#include "LinkedList.h"

namespace messaging
{

class SingletonMessageBroker
{
public:

  static const uint32_t MAX_TOPICS;
  static const uint64_t MAX_OBSERVERS_PER_TOPIC;

  static void          killInstance();
  static const uint8_t numTopics();
  static void          registerObserver(const Topic& topic, utils::Observer<Message>& observer);  
  static void          updateTopic(const Topic& topic, Message& message);

private:

  SingletonMessageBroker();
  ~SingletonMessageBroker();

  static void getInstance();

  static SingletonMessageBroker *                                                  instance;
  utils::HashMap<Topic, utils::LinkedList<utils::Observer<Message>*>> topics;

};

}

#endif // MESSAGING_SINGLETON_MESSAGE_BROKER_H
