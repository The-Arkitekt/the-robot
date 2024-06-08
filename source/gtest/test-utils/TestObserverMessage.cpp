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

void TestObserverMessage::update(const messaging::Message& object)
{
  message = &object;
}

}
