#IFNDEF SINGLETON_MESSAGE_BROKER_H
#DEFINE SINGLETON_MESSAGE_BROKER_H

#include "Subscriber.h"

class SingletonMessageBroker
{
public:

  static const uint8_t MAX_SUBSCRIBERS;

  static SingletonMessageBroker * const getInstance();
  static void                           killInstance();

  void register(char const * const topicName, Subscriber& subscriber);  
  void update(char const * const topicName, Message& message) const;

private:

  SingletonMessageBroker();
  ~SingletonMessageBroker();

  SingletonMessageBroker * instance;
  Subscriber **            subscribers;
  uint8_t                  numSubscribers;
}

#ENDIF // SINGLETON_MESSAGE_BROKER_H
