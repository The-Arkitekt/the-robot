#include <gtest/gtest.h>
#include "SingletonMessageBroker.h"
#include "TestMessage.h"
#include "TestObserverMessage.h"
#include "Topics.h"

namespace gtest
{

class SingletonMessageBrokerTest : public testing::Test
{
protected:

  SingletonMessageBrokerTest():
    observer()
  {
  }

  ~SingletonMessageBrokerTest() override 
  {
    messaging::SingletonMessageBroker::killInstance();
  }

  void SetUp() override 
  {
  }

  void TearDown() override 
  {
  }

  TestObserverMessage observer;
};

TEST_F(SingletonMessageBrokerTest, RegisterObserver)
{
  messaging::SingletonMessageBroker::registerObserver(messaging::DRIVE_STATE_COMMAND_TOPIC, observer);

  EXPECT_EQ(1U, messaging::SingletonMessageBroker::numTopics());
}

TEST_F(SingletonMessageBrokerTest, UpdateTopic)
{
  messaging::SingletonMessageBroker::registerObserver(messaging::DRIVE_STATE_COMMAND_TOPIC, observer);
  ASSERT_EQ(1U, messaging::SingletonMessageBroker::numTopics());

  TestMessage message;
  message.value = 69U; // Nice!

  messaging::SingletonMessageBroker::updateTopic(messaging::DRIVE_STATE_COMMAND_TOPIC, message);

  ASSERT_TRUE(nullptr != observer.message);
  EXPECT_EQ(69U, static_cast<TestMessage const *>(observer.message)->value);
}

}

