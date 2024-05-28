#include <gtest/gtest.h>
#include "SingletonBrokerPublisher.h"
#include "SingletonMessageBroker.h"
#include "TestMessage.h"
#include "TestSubscriber.h"

class SingletonBrokerPublisherTest : public testing::Test
{
protected:

  SingletonBrokerPublisherTest():
    publisher("Test Topic")
  {
  }

  ~SingletonBrokerPublisherTest() override 
  {
    SingletonMessageBroker::killInstance();
  }

  void SetUp() override 
  {
  }

  void TearDown() override 
  {
  }

  SingletonBrokerPublisher publisher;
};

TEST_F(SingletonBrokerPublisherTest, Publish)
{
  TestSubscriber subscriber;
  SingletonMessageBroker::registerSubscriber("Test Topic", subscriber);
  ASSERT_EQ(1U, SingletonMessageBroker::size());

  TestMessage message;
  message.value = 69U;
  publisher.publish(message);

  TestMessage receivedMessage;
  subscriber.pop(receivedMessage);

  EXPECT_EQ(message.value, receivedMessage.value);
}
