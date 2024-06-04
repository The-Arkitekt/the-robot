#include <gtest/gtest.h>
#include "Observer.h"
#include "SingletonMessageBroker.h"
#include "TestMessage.h"

class ObserverTest : public testing::Test
{
protected:

  ObserverTest():
    subscriber()
  {
  }

  ~SingletonBrokerSubscriberTest() override 
  {
    SingletonMessageBroker::killInstance();
  }

  void SetUp() override 
  {
    SingletonMessageBroker::registerObserver(observer);
  }

  void TearDown() override 
  {
  }

  Observer observer;
};

TEST_F(SingletonBrokerSubscriberTest, Constructor)
{
  EXPECT_EQ(1U, SingletonMessageBroker::numSubscribers());
  EXPECT_EQ(0U, subscriber.numMessages());
}

TEST_F(SingletonBrokerSubscriberTest, UpdatePopSize)
{
  TestMessage firstMessage;
  firstMessage.value = 69U;
  subscriber.update(firstMessage);

  EXPECT_EQ(1U, subscriber.numMessages());

  TestMessage secondMessage;
  secondMessage.value = 42U;
  subscriber.update(secondMessage);

  EXPECT_EQ(2U, subscriber.numMessages());

  TestMessage firstReceivedMessage;
  subscriber.popLatest(firstReceivedMessage);

  EXPECT_EQ(1U, subscriber.numMesssages());
  EXPECT_EQ(69U, firstReceivedMessage.value);

  TestMessage secondReceivedMessage;
  subscriber.popLatest(secondReceivedMessage);

  EXPECT_EQ(0U, subscriber.numMessages());
  EXPECT_EQ(42U, secondReceivedMessage.value);
}

TEST_F(SingletonBrokerSubscriberTest, Clear)
{
  TestMessage message;
  message.value = 69U;
  subscriber.update(message);
  subscriber.update(message);
  subscriber.update(message);

  ASSERT_EQ(3U, subscriber.numMessages());

  subscriber.clear();

  EXPECT_EQ(0U, subscriber.numMessages());

  TestMessage receivedMessage;
  subscriber.popLatest(receivedMessage);

  EXPECT_EQ(0U, receivedMessage.value);
}
