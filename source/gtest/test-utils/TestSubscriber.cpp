#include "TestSubscriber.h"
#include <new>

TestSubscriber::TestSubscriber():
  messageData(nullptr)
{
}

TestSubscriber::~TestSubscriber()
{
  clear();
}

const uint8_t TestSubscriber::numMessages() const
{
  if (nullptr == messageData) 
  {
    return 0U;
  }

  return 1U;
}

void TestSubscriber::update(Message& message)
{
  const uint8_t * fromMessage = message.pack();
  if (nullptr == fromMessage)
  {
    return;
  }

  clear();

  messageData = new (std::nothrow) uint8_t[message.size()];
  if (nullptr == messageData)
  {
    return;
  }
  
  for (uint8_t i = 0U; i < message.size(); ++i)
  {
    messageData[i] = fromMessage[i];
  }
}

void TestSubscriber::popLatest(Message& message)
{
  if (nullptr == messageData)
  {
    message.unpack(nullptr, 0U);
    return;
  }

  message.unpack(messageData, 1U);
}

void TestSubscriber::clear()
{
  if (nullptr != messageData)
  {
    delete[] messageData;
  }

  messageData = nullptr;
}


