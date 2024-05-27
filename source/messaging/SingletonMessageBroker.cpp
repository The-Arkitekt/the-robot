#include "SingletonMessageBroker.h"
#include <string.h>
#include <new>

const uint8_t SingletonMessageBroker::MAX_TOPICS          = 255U;
SingletonMessageBroker * SingletonMessageBroker::instance = nullptr;

SingletonMessageBroker::SingletonMessageBroker():
  numTopics     (0U),
  topics        (nullptr)
{
}

SingletonMessageBroker::~SingletonMessageBroker()
{
  delete[] topics;
  topics = nullptr;    
}
   
void SingletonMessageBroker::getInstance()
{
  if (nullptr == instance)
  {
    instance = new (std::nothrow) SingletonMessageBroker();
  }
}

void SingletonMessageBroker::killInstance()
{
  delete instance;
  instance = nullptr;
}

const uint8_t SingletonMessageBroker::size()
{
  getInstance();

  if (nullptr == instance)
  {
    return 0U;
  }
  
  return instance->numTopics;
}

void SingletonMessageBroker::registerSubscriber(char const * const topicName, Subscriber& subscriber)
{
  getInstance();

  if (nullptr == instance)
  {
    return;
  }

  if (MAX_TOPICS == instance->numTopics)
  {
    return;
  }

  // Search for topic in topics list
  for (uint8_t i = 0U; i < instance->numTopics; ++i)
  {
    if (0 == strcmp(instance->topics[i]->name(), topicName))
    {
       instance->topics[i]->addSubscriber(subscriber);
       return;
    }
  }

  // If this point is reached a new topic needs to be created
  // Create the newew Topic first to make sure it is successfully allocated
  Topic * newTopic = new (std::nothrow) Topic(topicName);
  if (nullptr == newTopic)
  {
    return;
  }

  newTopic->addSubscriber(subscriber);

  Topic ** newTopics = new (std::nothrow) Topic *[instance->numTopics + 1U];
  if (nullptr == newTopics)
  {
    delete newTopic;
    return;
  }

  // Copy over topics
  for (uint8_t i = 0U; i < instance->numTopics; ++i)
  {
    newTopics[i] = instance->topics[i];
  }

  // Set new topic at end of array
  newTopics[instance->numTopics++] = newTopic;

  // Replace topics array
  if (nullptr != instance->topics)
  {
    delete[] instance->topics;
  }

  instance->topics = newTopics;
}

void SingletonMessageBroker::updateTopic(char const * const topicName, Message& message)
{
  getInstance();

  if (nullptr == instance)
  {
    return;
  }

  // Search for topic in topics list
  for (uint8_t i = 0U; i < instance->numTopics; ++i)
  {
    if (0 == strcmp(instance->topics[i]->name(), topicName))
    {
      instance->topics[i]->update(message);
    }
  }
}




