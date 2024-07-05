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

TEST_F(QueueTest, CapacityConstructor)
{
  const uint64_t capacity = 543;
  utils::Queue queue(capacity);

  //Starting size is still 0 until something is pushed to the queue
  EXPECT_EQ(0U, queue.size());
}

}
