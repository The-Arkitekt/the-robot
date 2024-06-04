#include <new>
#include "SingletonBrokerSubscriber.h"
#include "SingletonMessageBroker.h"
#include "ByteString.h"

SingletonBrokerSubscriber::SingletonBrokerSubscriber(char const * const topicName, const uint8_t capacity):
  capacity   (capacity),
  byteStrings(capacity)
{
  SingletonMessageBroker::registerSubscriber(topicName, *this);
}

SingletonBrokerSubscriber::~SingletonBrokerSubscriber()
{
  clear();
}

const uint8_t SingletonBrokerSubscriber::numMessages() const
{
  return byteStrings.size();
}

void SingletonBrokerSubscriber::update(Message& message)
{
  // Cant push for these reasons
  if ((capacity == byteStrings.size()) || (0U == message.size()))
  {
    return;
  }

  // Create a new ByteString to push into the queue
  ByteString * byteString = new (std::nothrow) ByteString(message.pack(), message.size());
  if (nullptr == byteString)
  {
    return;
  }

  byteStrings.push(byteString);
}

void SingletonBrokerSubscriber::popLatest(Message& message)
{
  // Cant pop for these reasons
  if (0U == byteStrings.size())
  {
    return;
  }

  ByteString * byteString = static_cast<ByteString*>(byteStrings.pop());
  if (nullptr == byteString)
  {
    return;
  }

  message.unpack(byteString->bytes, byteString->size);

  // byteString must be deleted before going out of scope
  delete byteString;
}

void SingletonBrokerSubscriber::clear()
{
  const uint8_t numMessages = byteStrings.size();
  void * byteString         = nullptr;

  // Must delete all bytestrings from queue before clearing
  // it since they will be going out of scope
  for (uint8_t i = 0U; i < numMessages; ++i)
  {
    byteString = byteStrings.pop();
    delete byteString;
  }

  byteStrings.clear();
}

