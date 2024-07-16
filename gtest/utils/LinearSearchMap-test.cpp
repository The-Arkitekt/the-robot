#include <gtest/gtest.h>
#include "LinearSearchMap.h"

namespace gtest
{

class LinearSearchMapTest : public testing::Test
{
protected:

  LinearSearchMapTest()
  {
  }

  ~LinearSearchMapTest() override
  {
  }

  void SetUp() override
  {
  }

  void TearDown() override
  {
  }
};

TEST_F(LinearSearchMapTest, SetAndGetValues)
{
  utils::LinearSearchMap<uint8_t, int32_t> linearSearchMap;

  int32_t firstVal = -2;
  uint8_t firstKey = 1U;

  linearSearchMap[firstKey] = firstVal;

  EXPECT_EQ(firstVal, linearSearchMap[firstKey]);

  int32_t secondVal = -43;
  uint8_t secondKey = 3U;

  linearSearchMap[secondKey] = secondVal;

  EXPECT_EQ(firstVal, linearSearchMap[firstKey]);
  EXPECT_EQ(secondVal, linearSearchMap[secondKey]);
}

TEST_F(LinearSearchMapTest, CopyConstructor)
{
  utils::LinearSearchMap<uint8_t, int32_t> linearSearchMap;
  
  int32_t firstVal = -2;
  uint8_t firstKey = 1U;

  linearSearchMap[firstKey] = firstVal;

  utils::LinearSearchMap<uint8_t, int32_t> copyMap(linearSearchMap);

  EXPECT_EQ(firstVal, copyMap[firstKey]);
}

TEST_F(LinearSearchMapTest, CopyAssignment)
{
  utils::LinearSearchMap<uint8_t, int32_t> linearSearchMap;
  
  int32_t firstVal = -2;
  uint8_t firstKey = 1U;

  linearSearchMap[firstKey] = firstVal;

  utils::LinearSearchMap<uint8_t, int32_t> copyMap;

  copyMap = linearSearchMap;

  EXPECT_EQ(firstVal, copyMap[firstKey]);
}

TEST_F(LinearSearchMapTest, GetKeys)
{
  utils::LinearSearchMap<uint8_t, int32_t> linearSearchMap;

  int32_t firstVal = -2;
  uint8_t firstKey = 1U;

  linearSearchMap[firstKey] = firstVal;

  int32_t secondVal = -43;
  uint8_t secondKey = 3U;

  linearSearchMap[secondKey] = secondVal;

  utils::ArrayList<uint8_t> keys = linearSearchMap.getKeys();

  ASSERT_EQ(2U, keys.size());
  EXPECT_EQ(1U, keys[0U]);
  EXPECT_EQ(3U, keys[1U]);
}

}
