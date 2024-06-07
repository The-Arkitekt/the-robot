#include "TestObserverMessage.h"

namespace gtest
{

TestObserverMessage::TestObserverMessage():
  message(nullptr)
{
}

TestObserverMessage::~TestObserverMessage()
{
}

void TestObserverMessage::update(const Message& object)
{
  message = &object;
}

Message * const TestObserverMessage::getMessage()
{
  return message;
}

}
