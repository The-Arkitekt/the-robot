#include <gtest/gtest.h>
#include "ArrayList.h"

namespace gtest
{

class ArrayListTest : public testing::Test
{
protected:

  ArrayListTest()
  {
  }

  ~ArrayListTest() override
  {
  }

  void SetUp() override
  {
  }

  void TearDown() override
  {
  }
};

TEST_F(ArrayListTest, SizeZeroConstructor)
{
  utils::ArrayList<uint8_t> arrayList(0U);
  EXPECT_EQ(0U, arrayList.size());
}

TEST_F(ArrayListTest, StartingSizeConstructor)
{
  const uint64_t startingSize = 5U;
  const uint8_t  defaultValue = 1U;
  
  utils::ArrayList<uint8_t> initializedArrayList(startingSize, defaultValue);
  
  EXPECT_EQ(startingSize, initializedArrayList.size());
  for (uint64_t i = 0U; i < startingSize; ++i)
  {
    EXPECT_EQ(defaultValue, initializedArrayList[i]);
  }
}

TEST_F(ArrayListTest, CopyConstructor)
{
  utils::ArrayList<uint8_t> arrayList(0U);
  const uint64_t size = 12U;
  arrayList.resize(size);

  for (uint64_t i = 0U; i < size; ++i)
  {
    arrayList[i] = i;
  }

  utils::ArrayList<uint8_t> copiedArrayList(arrayList);

  ASSERT_EQ(arrayList.size(), copiedArrayList.size());
  
  for (uint64_t i = 0U; i < size; ++i)
  {
    EXPECT_EQ(arrayList[i], copiedArrayList[i]);
  }
}

TEST_F(ArrayListTest, AssignmentOperator)
{
  utils::ArrayList<uint8_t> arrayList(0U);
  arrayList.resize(2U);

  arrayList[0U] = 10U;
  arrayList[1U] = 20U;

  utils::ArrayList<uint8_t> assignedArrayList(0U);

  assignedArrayList = arrayList;

  ASSERT_EQ(arrayList.size(), assignedArrayList.size());
  EXPECT_EQ(arrayList[0U], assignedArrayList[0U]);
  EXPECT_EQ(arrayList[1U], assignedArrayList[1U]);
}

TEST_F(ArrayListTest, ResizeBigger)
{
  const uint8_t defaultValue = 3U;
  utils::ArrayList<uint8_t> arrayList(0U, defaultValue);
  const uint64_t newSize = 542U;
  arrayList.resize(newSize);
  EXPECT_EQ(newSize, arrayList.size());

  for (uint64_t i = 0U; i < newSize; ++i)
  {
    EXPECT_EQ(defaultValue, arrayList[i]);
  }
}

TEST_F(ArrayListTest, ResizeSmaller)
{
  utils::ArrayList<uint8_t> arrayList(5U, 0U);
  for (uint64_t i = 0U; i < arrayList.size(); ++i)
  {
    arrayList[i] = i;
  }

  arrayList.resize(2U);
  EXPECT_EQ(2U, arrayList.size());
  for (uint64_t i = 0U; i < arrayList.size(); ++i)
  {
    EXPECT_EQ(i, arrayList[i]);
  }
}


TEST_F(ArrayListTest, clear)
{
  utils::ArrayList<uint8_t> arrayList(3U, 0U);
  arrayList[0U] = 23U;
  arrayList[1U] = 42U;
  arrayList[2U] = 74U;

  arrayList.clear();

  EXPECT_EQ(0U, arrayList.size());
}

}
