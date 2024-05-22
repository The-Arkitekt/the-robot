#include "SingletonMessageBroker.h"

const uint8_t SingletonMessageBroker::MAX_SUBSCRIBERS = 255U;

SingletonMessageBroker::SingletonMessageBroker():
  instance      (nullptr),
  subscribers   (nullptr),
  numSubscribers(0U)
{
}

SingletonMessageBroker::~SingletonMessageBroker()
{
  if (nullptr != instance)
  {
    delete(instance);
    instance = nullptr;
  }

  if` (nullptr != subscribers)
  {
    
  }
    
