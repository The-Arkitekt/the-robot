#include "SingletonMessageBroker.h"
#include <string.h>
#include <new>

namespace messaging
{

const uint64_t SingletonMessageBroker::MAX_OBSERVERS_PER_TOPIC = 10U;
SingletonMessageBroker * SingletonMessageBroker::instance      = nullptr;

SingletonMessageBroker::SingletonMessageBroker():
  topicCounter(0U),
  topics      ()
{
}

SingletonMessageBroker::~SingletonMessageBroker()
{
}
   
void SingletonMessageBroker::getInstance()
{
  if (nullptr == instance)
  {
    instance = new(std::nothrow) SingletonMessageBroker();
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
  
  return instance->topicCounter;
}

void SingletonMessageBroker::registerObserver(const Topic& topic, utils::Observer<Message>& observer)
{
  getInstance();

  // Cant register for these reasons
  if (nullptr == instance)
  {
    return;
  }

  instance->topics[static_cast<uint8_t>(topic)].push(&observer);
  ++(instance->topicCounter);
}

void SingletonMessageBroker::updateTopic(const Topic& topic, Message& message)
{
  getInstance();

  if (nullptr == instance)
  {
    return;
  }

  utils::LinkedList<utils::Observer<Message>*>* topicList = &(instance->topics[static_cast<uint8_t>(topic)]);
  utils::Node<utils::Observer<Message>*>* currentNode     = &(topicList->head());

  for (uint64_t i = 0U; i < topicList->size(); ++i)
  {
    currentNode->object->update(message);
    currentNode = currentNode->child;
  }
}

}
