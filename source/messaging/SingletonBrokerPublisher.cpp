#include "SingletonBrokerPublisher.h"
#include "SingletonMessageBroker.h"

SingletonBrokerPublisher::SingletonBrokerPublisher(char const * const topicName):
  topicName(topicName)
{
}

SingletonBrokerPublisher::~SingletonBrokerPublisher()
{
}

void SingletonBrokerPublisher::publish(Message& message)
{
  SingletonMessageBroker::updateTopic(topicName, message);
}


  


