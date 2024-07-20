#include <gtest/gtest.h>
#include "Queue.h"

namespace gtest
{

class QueueTest : public testing::Test
{
protected:

  QueueTest()
  {
  }

  ~QueueTest() override
  {
  }

  void SetUp() override
  {
  }

  void TearDown() override
  {
  }
};

TEST_F(QueueTest, Constructor)
{
  const uint64_t capacity = 543;
  Utils::Queue<uint8_t> queue(capacity, 0U);

  EXPECT_EQ(capacity, queue.capacity());

  //Starting size is still 0 until something is pushed to the queue
  EXPECT_EQ(0U, queue.size());
}

TEST_F(QueueTest, PushUntilFullThenPop)
{
  const uint64_t capacity = 5U;
  Utils::Queue<uint8_t> queue(capacity, 0U);

  for (uint64_t i = 0U; i < capacity; ++i)
  {
    ASSERT_LT(i, queue.capacity());
    
    queue.push(static_cast<uint8_t>(i));
    EXPECT_EQ(i + 1U, queue.size());
  }

  for (uint64_t i = 0U; i < capacity; ++i)
  {
    uint8_t val = queue.pop();
    EXPECT_EQ(i, static_cast<uint64_t>(val));
    EXPECT_EQ(capacity - i - 1U, queue.size());
  }
}

TEST_F(QueueTest, PushOverCapacity)
{
  const uint64_t capacity = 1U;
  Utils::Queue<uint8_t> queue(capacity, 2U);

  uint8_t firstVal = 23U;
  queue.push(firstVal);

  uint8_t secondVal = 32U;
  queue.push(secondVal);

  uint8_t poppedVal = queue.pop();

  EXPECT_EQ(firstVal, poppedVal);
}

TEST_F(QueueTest, PopEmpty)
{
  uint8_t defaultValue = 4U;
  Utils::Queue<uint8_t> queue(1U, defaultValue);

  uint8_t poppedVal = queue.pop();

  EXPECT_EQ(defaultValue, poppedVal);
}

TEST_F(QueueTest, clear)
{
  uint64_t capacity   = 5U;
  uint16_t defaultVal = 10U;
  Utils::Queue<uint16_t> queue(capacity, defaultVal);

  for (uint64_t i = 0U; i < capacity; ++i)
  {
    queue.push(static_cast<uint16_t>(i));
  }

  queue.clear();
  
  EXPECT_EQ(0U, queue.size());
  EXPECT_EQ(capacity, queue.capacity());
  uint16_t poppedVal = queue.pop();
  EXPECT_EQ(defaultVal, poppedVal);

}

} 



