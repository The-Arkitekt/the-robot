#include <gtest/gtest.h>
#include "LinkedList.h"

namespace gtest
{

class LinkedListTest : public testing::Test
{
protected:

  LinkedListTest()
  {
  }

  ~LinkedListTest() override
  {
  }

  void SetUp() override
  {
  }

  void TearDown() override
  {
  }
};

TEST_F(LinkedListTest, Constructor)
{
  const uint8_t defaultValue = 2U;
  Utils::LinkedList<uint8_t> linkedList(defaultValue);

  EXPECT_EQ(defaultValue, linkedList.head().object);
  EXPECT_EQ(defaultValue, linkedList.tail().object);
  EXPECT_EQ(nullptr, linkedList.head().child);
  EXPECT_EQ(nullptr, linkedList.tail().child);
}

TEST_F(LinkedListTest, PushFirstObjectToBack)
{
  const uint8_t defaultValue = 1U;
  Utils::LinkedList<uint8_t> linkedList(defaultValue);

  const uint8_t firstPushVal = 32U;
  linkedList.pushToBack(firstPushVal);

  EXPECT_EQ(firstPushVal, linkedList.head().object);
  EXPECT_EQ(firstPushVal, linkedList.tail().object);
  EXPECT_EQ(nullptr, linkedList.head().child);
  EXPECT_EQ(nullptr, linkedList.tail().child);
}

TEST_F(LinkedListTest, PushSecondObjectToBack)
{
  const uint8_t defaultValue = 2U;
  Utils::LinkedList<uint8_t> linkedList(defaultValue);

  const uint8_t firstPushVal  = 27U;
  const uint8_t secondPushVal = 87U;

  linkedList.pushToBack(firstPushVal);
  linkedList.pushToBack(secondPushVal);

  EXPECT_EQ(firstPushVal, linkedList.head().object);
  EXPECT_EQ(secondPushVal, linkedList.tail().object);
  ASSERT_NE(nullptr, linkedList.head().child);
  EXPECT_EQ(secondPushVal, linkedList.head().child->object);
}

TEST_F(LinkedListTest, PopFromFront)
{
  const uint8_t defaultValue = 2U;
  Utils::LinkedList<uint8_t> linkedList(defaultValue);

  const uint8_t firstPushVal  = 27U;
  const uint8_t secondPushVal = 87U;

  linkedList.pushToBack(firstPushVal);
  linkedList.pushToBack(secondPushVal);

  uint8_t frontValue = linkedList.popFromFront();

  EXPECT_EQ(firstPushVal, frontValue);
  EXPECT_EQ(secondPushVal, linkedList.head().object);
  EXPECT_EQ(nullptr, linkedList.head().child);
  EXPECT_EQ(secondPushVal, linkedList.tail().object);
  EXPECT_EQ(nullptr, linkedList.tail().child);
}

TEST_F(LinkedListTest, Clear)
{
  const uint8_t defaultValue = 2U;
  Utils::LinkedList<uint8_t> linkedList(defaultValue);

  const uint8_t firstPushVal  = 27U;
  const uint8_t secondPushVal = 87U;

  linkedList.pushToBack(firstPushVal);
  linkedList.pushToBack(secondPushVal);

  linkedList.clear();

  EXPECT_EQ(defaultValue, linkedList.head().object);
  EXPECT_EQ(defaultValue, linkedList.tail().object);
  EXPECT_EQ(nullptr, linkedList.head().child);
}

}

