#ifndef GTEST_TEST_MESSAGE_H
#define GTEST_TEST_MESSAGE_H

#include "Message.h"

namespace gtest
{

static const uint32_t TEST_MESSAGE_SIZE;
static const uint8_t  TEST_MESSAGE_ID;

class TestMessage : public Message
{
public:

  TestMessage();
  ~TestMessage();

  void               init();
  uint8_t            identifier();
  ArrayList<uint8_t> pack();
  void               unpack(const ArrayList<uint8_t>& data);

  ArrayList<uint8_t> packedBytes;
  uint8_t            value;
};

}

#endif // GTEST_TEST_MESSAGE_H
