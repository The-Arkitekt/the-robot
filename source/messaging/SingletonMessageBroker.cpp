#include "SingletonMessageBroker.h"
#include <string.h>
#include <new>

const uint32_t SingletonMessageBroker::MAX_TOPICS              = 10U;
const uint64_t SingletonMessageBroker::MAX_OBSERVERS_PER_TOPIC = 10U;
SingletonMessageBroker * SingletonMessageBroker::instance      = nullptr;

SingletonMessageBroker::SingletonMessageBroker():
  topics(static_cast<uint64_t>(2U * MAX_TOPICS))
{
}

SingletonMessageBroker::~SingletonMessageBroker()
{
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

const uint8_t SingletonMessageBroker::numTopics()
{
  getInstance();

  if (nullptr == instance)
  {
    return 0U;
  }
  
  return instance->topics.size()
}

void SingletonMessageBroker::registerObserver(char const * const topicName, utils::Observer<Message>& observer)
{
  getInstance();

  // Cant register for these reasons
  if ((nullptr == instance) || (MAX_TOPICS == topics->size()))
  {
    return;
  }

  topics[topicName].push(&observer);
}

void SingletonMessageBroker::updateTopic(char const * const topicName, Message& message)
{
  getInstance();

  if (nullptr == instance)
  {
    return;
  }

  Node<utils::Observer*> const * currentTopicNode = topics[topicName];

  while((nullptr != currentTopicNode) && (nullptr != currentTopicNode->object))
  {
    currentTopicNode->object->update(message);
    currentTopicNode = currentTopicNode->child;
  }
}
