#include "Topic.h"
#include <new>

const uint8_t MAX_SUBSCRIBERS_PER_TOPIC = 255U;

Topic::Topic(char const * const name):
  name       (name),
  subscribers(nullptr)
{
}

Topic::~Topic()
{
  // Only delete the one pointer because 
  // Subscribers are passed as a reference
  // and not allocated in this class
  if (nullptr != subscribers)
  {
    delete(subscribers);
    subscribers = nullptr;
  }
}

const uint8_t Topic::numSubscribers() const
{
  return numSubscribers;
}

void Topic::addSubscriber(Subscriber& subscriber)
{
  if (MAX_SUBSCRIBERS_PER_TOPIC == numSubscribers)
  {
    return;
  }
  
  // Reallocate a new subscribers list with one more memory location for the new subscriber
  Subscriber** newSubscribers = new((numSubscribers + 1) * sizeof(Subscriber*), std::nothrow) Subscriber*;
  if (nullptr == newSubscribers)
  {
    // Allocation failed
    return;
  }

  // Copy over subscribers
  for (uint8_t i = 0U; i < numSubscribers; ++i)
  {
    newSubscribers[i] = subscribers[i];
  }

  // Set the new subscriber at the end of new list
  newSubscribers[++numSubscribers] = subscriber;

  // Free old subscribers pointer, not each subscriber!
  if (nullptr != subscribers)
  {
    delete subscribers;
    subscribers = nullptr;
  }

  // Set subscribers to new list
  subscribers = newSubscribers;
}

  

