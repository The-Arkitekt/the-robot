#include "SingletonMessageBroker.h"
#include <string.h>
#include <new>

const uint64_t SingletonMessageBroker::MAX_TOPICS              = 10U;
const uint64_t SingletonMessageBroker::MAX_OBSERVERS_PER_TOPIC = 10U;
SingletonMessageBroker * SingletonMessageBroker::instance = nullptr;

SingletonMessageBroker::SingletonMessageBroker():
  // TODO: topics(TOPICS_CAPACITY)
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
  
  // TODO: implement with hashmap
  // 
  // return instance->topics.size()
}

void SingletonMessageBroker::registerObserver(char const * const topicName, Observer& observer)
{
  getInstance();

  // Cant register for these reasons
  if ((nullptr == instance) || (// TODO: capacity == topics->size()))
  {
    return;
  }
  
  // TODO: implement with hash map
  //
  // topics[topicName][topics.size()] = &observer

}

void SingletonMessageBroker::updateTopic(char const * const topicName, Message& message)
{
  getInstance();

  if (nullptr == instance)
  {
    return;
  }

  // TODO: Get topic array list from hashmap
}




