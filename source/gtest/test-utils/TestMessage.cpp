#include "TestMessage.h"
#include <new>

TestMessage::TestMessage():
  value(0U)
{
}

TestMessage::~TestMessage()
{
}

void TestMessage::init()
{
  value = 0U;
}

const uint32_t TestMessage::size() const
{
  return 1U;
}

uint8_t const * const TestMessage::pack()
{
  return &value;
}

void TestMessage::unpack(uint8_t const * const data, const uint32_t size)
{
  if ((nullptr == data) || (1U != size))
  {
    return;
  }

  value = *data;
}


