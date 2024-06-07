#ifndef GTEST_TEST_OBSERVER_MESSAGE_H
#define GTEST_TEST_OBSERVER_MESSAGE`_H

#include "Observer.h"
#include "Message.h"

namespace gtest
{

class TestObserverMessage : public Observer<Message&>
{
public:

  TestObserverMessage();
  ~TestObserverMessage();

  void update(const Message& object);

  Message * const getMessage();

private:

  Message * message;

};

}

#endif // GTEST_TEST_OBSERVER_MESSAGE_H
