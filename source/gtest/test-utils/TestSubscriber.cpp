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

const uint8_t TestSubscriber::size() const
{
  if (nullptr == messageData) 
  {
    return 0U;
  }

  return 1U;
}

void TestSubscriber::push(Message& message)
{
  clear();

  messageData = new (std::nothrow) uint8_t[message.size()];
  if (nullptr == messageData)
  {
    return;
  }

  messageData = message.pack();
}

void TestSubscriber::pop(Message& message)
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
  delete[] messageData;
}


