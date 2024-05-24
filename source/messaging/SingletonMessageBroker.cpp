#include "SingletonMessageBroker.h"
#include <string.h>

const uint8_t SingletonMessageBroker::MAX_TOPICS = 255U;

SingletonMessageBroker::SingletonMessageBroker():
  instance      (nullptr),
  numTopics     (0U),
  topics        (nullptr)
{
}

SingletonMessageBroker::~SingletonMessageBroker()
{
  if (nullptr != instance)
  {
    delete(instance);
    instance = nullptr;
  }

  // Delete each Topic before deleting the array 
  if (nullptr != topics)
  {
    for (uint8_t i = 0U; i < numTopics; ++i)
    {
      if (nullptr != topics[i])
      {
        delete(topics[i]);
        topics[i] = nullptr;
      }
    }

    delete(topics);
    topics = nullptr;    
  }
}
   
SingletonMessageBroker * const SingletonMessageBroker::getInstance()
{
  if (nullptr == instance)
  {
    instance = new (std::nothrow) SingletonMessageBroker();
  }

  return instance;
}

void SingletonMessageBroker::killInstance()
{
  if (nullptr != instance)
  {
    delete(instance);
    instance = nullptr;
  }
}

const uint8_t SingletonMessageBroker::numTopics() const
{
  return numTopics;
}

void SingletonMessageBroker::register(char const * const topicName, Subscriber& subscriber)
{
  if (MAX_TOPICS == numTopics)
  {
    return;
  }

  // Search for topic in topics list
  for (uint8_t i = 0U; i < numTopics; ++i)
  {
    if (0 == strcmp(topics[i]->name(), topicName))
    {
       topics[i]->addSubscriber(subscriber);
       return;
    }
  }

  // If this point is reached a new topic needs to be created
  // Create the new Topic first to make sure it is successfully allocated
  topic = new (std::nothrow) Topic(topicName);
  if (nullptr == newTopic)
  {
    return;
  }

  newTopic->addSubscriber(subscriber);
  if (0U == newTopic->numSubscribers())
  {
    delete(newTopic)
    return;
  }

  Topic ** newTopics = new ((numTopics + 1), std::nothrow) Topic *;
  if (nullptr == newTopics)
  {
    delete newTopic;
    return;
  }

  // Copy over topics
  for (uint8_t i = 0U; i < numTopics; ++i)
  {
    newTopics[i] = topics[i];
  }

  // Set new topic at end of array
  newTopics[numTopics++] = newTopic;

  // Replace topics array
  if (nullptr != topics)
  {
    delete(topics);
    topics = nullptr;
  }

  topics = newTopics;
}

void SingletonMessageBroker::updateTopic(char const * const topicName, Message& message)
{
  // Search for topic in topics list
  for (uint8_t i = 0U; i < numTopics; ++i)
  {
    if (0 == strcmp(topics[i]->name(), topicName))
    {
      topics[i]->update(message);
    }
  }
}




