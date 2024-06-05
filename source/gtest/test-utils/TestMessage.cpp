#include "TestMessage.h"
#include <new>

namespace gtest
{

const uint32_t TestMessage::TEST_MESSAGE_SIZE = 1U;
const uint8_t  TestMessage::TEST_MESSAGE_ID   = 0U;

TestMessage::TestMessage():
  packedBytes(TEST_MESSAGE_SIZE),
  value      (0U)
{
}

TestMessage::~TestMessage()
{
}

void TestMessage::init()
{
  value = 0U;
}

uint8_t TestMessage::identifier()
{
  return TEST_MESSAGE_ID;
}

uint32_t TestMessage::size() const
{
  return TEST_MESSAGE_SIZE;
}

const ArrayList<uint8_t>& TestMessage::pack()
{
  for (uint32_t i = 0U; i < TEST_MESSAGE_SIZE; ++i)
  {
    packedBytes[i] = value;
  }

  return packedBytes;
}

void TestMessage::unpack(const ArrayList<uint8_t>& data)
{
  if (TEST_MESSAGE_SIZE != data.size())
  {
    return;
  }

  for (uint32_t i = 0U; i < TEST_MESSAGE_SIZE; ++i)
  {
    packedBytes[i] = data[i];
  }
}

}
