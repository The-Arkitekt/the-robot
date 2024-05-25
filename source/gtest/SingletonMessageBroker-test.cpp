#include <gtest/gtest.h>
#include "SingletonMessageBroker.h"
#include "Subscriber.h"

class TestSubscriber : public Subscriber
{
public:

  TestSubscriber():
    messageData(nullptr)
  {
  };

  ~TestSubscriber()
  {
  };

  const uint8_t size() const 
  {
    return 1U;
  }

  void push(Message& message)
  {
    if (nullptr != this->message)
    {
      this->message->unpack(message.pack(), message.size());
    }
  }

  void pop(Message& message)
  {
    if (nullptr != this->message)
    {
      message.unpack(this->message->pack(), this->message->size())
    }
  }

  void clear()
  {
    delete[] messageData;
  }

  uint8_t * messageData;

}

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
