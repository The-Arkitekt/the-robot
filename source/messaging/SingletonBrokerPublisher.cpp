#include "SingletonBrokerPublisher.h"
#include "SingletonMessageBroker.h"

SingletonBrokerPublisher::SingletonBrokerPublisher(char * const * topicName):
  topicName    (topicName),
  messageBroker(nullptr)
{
}

SingletonBrokerPublisher::~SingletonBrokerPublisher()
{
  messageBroker = nullptr;
}

void SingletonBrokerPublisher::publish(const Message& message)
{
  // Try to get MessageBroker if necessary
  if (nullptr == messageBroker)
  {
    messageBroker = SingletonMessageBroker::getInstance();
    if (nullptr == messageBroker)
    {
      return;
    }
  }

  messageBroker->updateTopic(topicName, message);
}


  


