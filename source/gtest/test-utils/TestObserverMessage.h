#ifndef GTEST_TEST_OBSERVER_MESSAGE_H
#define GTEST_TEST_OBSERVER_MESSAGE_H

#include "Observer.h"
#include "Message.h"

namespace gtest
{

class TestObserverMessage : public utils::Observer<messaging::Message>
{
public:

  TestObserverMessage();
  ~TestObserverMessage();

  void update(const messaging::Message& object);

  messaging::Message const * message;

};

}

#endif // GTEST_TEST_OBSERVER_MESSAGE_H
