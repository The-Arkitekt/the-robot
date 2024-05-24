#IFNDEF SINGLETON_BROKER_PUBLISHER_H
#DEFINE SINGLETON_BROKER_PUBLISHER_H

#include "Publisher.h"

class SingletonBrokerPublisher : public Publisher
{
public:

  SingletonBrokerPublisher(char * const * topicName);
  ~SingletonBrokerPublisher();

  void publish(const Message& message);

private:

  char * const *           topicName;
  SingletonMessageBroker * messageBroker;
}

#ENDIF // SINGLETON_BROKER_PUBLISHER_H
