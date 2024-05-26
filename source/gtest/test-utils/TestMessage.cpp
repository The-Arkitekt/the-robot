#include "TestMessage.h"

TestMessage::TestMessage():
  messageValue(0U);
{
}

TestMessage::~TestMessage()
{
}

void TestMessage::init()
{
  messageValue = 0U;
}

const uint32_t TestMessage::size() const
{
  return 1U;
}

uint8_t const * const TestMessage::pack()
{
  return &messageValue;
}

void TestMessage::unpack(uint8_t const * const data, const uint32_t size)
{
  if ((nullptr == data) || (1U != size))
  {
    return;
  }

  messageValue = *data;
}


