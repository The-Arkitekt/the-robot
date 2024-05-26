#include <gtest/gtest.h>
#include "SingletonMessageBroker.h"
#include "TestMessage.h"
#include "TestSubscriber.h"

class SingletonMessageBrokerTest : public testing::Test
{
protected:

  SingletonMessageBrokerTest() 
  {
    broker = SingletonMessageBroker::getInstance();
  }

  ~SingletonMessageBrokerTest() override 
  {
    delete broker;
  }

  void SetUp() override 
  {
    ASSERT_NE(nullptr, broker);
  }

  void TearDown() override 
  {
  }

public:

  SingletonMessageBroker * broker;

};

TEST_F(SingletonMessageBrokerTest, GetInstance)
{
  SingletonMessageBroker * testBrokerInstance = SingletonMessageBroker::getInstance();

  EXPECT_EQ(broker, testBrokerInstance);
}

TEST_F(SingletonMessageBrokerTest, KillInstance)
{
  SingletonMessageBroker::killInstance();

  EXPECT_EQ(nullptr, broker);
}

TEST_F(SingletonMessageBrokerTest, RegisterSubscriber)
{
  TestSubscriber subscriber;

  broker->registerSubscriber("TestTopic", subscriber);

  EXPECT_EQ(1U, broker->size());

  broker->registerSubscriber("NextTestTopic", subscriber);

  EXPECT_EQ(2U, broker->size());
}

TEST_F(SingletonMessageBrokerTest, UpdateTopic)
{
  TestSubscriber subscriber;

  broker->registerSubscriber("TestTopic", subscriber);
  ASSERT_EQ(1U, broker->size());

  TestMessage message;
  message.messageValue = 69U; // Nice!

  broker->update("TestTopic", message);

  TestMessage receivedMessage;
  subscriber.pop(receivedMessage);

  EXPECT_EQ(69U, receivedMessage.messageValue);
}

