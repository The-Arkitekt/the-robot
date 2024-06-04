#include <gtest/gtest.h>
#include "SingletonMessageBroker.h"
#include "TestMessage.h"
#include "TestSubscriber.h"

class SingletonMessageBrokerTest : public testing::Test
{
protected:

  SingletonMessageBrokerTest() 
  {
  }

  ~SingletonMessageBrokerTest() override 
  {
    SingletonMessageBroker::killInstance();
  }

  void SetUp() override 
  {
  }

  void TearDown() override 
  {
  }
};

TEST_F(SingletonMessageBrokerTest, RegisterSubscriber)
{
  TestSubscriber subscriber;

  SingletonMessageBroker::registerSubscriber("TestTopic", subscriber);

  EXPECT_EQ(1U, SingletonMessageBroker::numTopics());

  SingletonMessageBroker::registerSubscriber("NextTestTopic", subscriber);

  EXPECT_EQ(2U, SingletonMessageBroker::numTopics());
}

TEST_F(SingletonMessageBrokerTest, UpdateTopic)
{
  TestSubscriber subscriber;

  SingletonMessageBroker::registerSubscriber("TestTopic", subscriber);
  ASSERT_EQ(1U, SingletonMessageBroker::numTopics());

  TestMessage message;
  message.value = 69U; // Nice!

  SingletonMessageBroker::updateTopic("TestTopic", message);

  TestMessage receivedMessage;
  subscriber.popLatest(receivedMessage);

  EXPECT_EQ(69U, receivedMessage.value);
}

