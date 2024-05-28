#ifndef TEST_MESSAGE_H
#define TEST_MESSAGE_H

#include "Message.h"

class TestMessage : public Message
{
public:

  TestMessage();
  ~TestMessage();

  void                  init();
  const uint32_t        size() const;
  uint8_t const * const pack();
  void                  unpack(uint8_t const * const data, const uint32_t size);

  uint8_t value;
};

#endif // TEST_MESSAGE_H
