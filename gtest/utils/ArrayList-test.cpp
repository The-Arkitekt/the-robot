#include <gtest/gtest.h>
#include "ArrayList.h"

namespace gtest
{

class ArrayListTest : public testing::Test
{
protected:

  ArrayListTest():
    defaultValue(0U),
    arrayList   (defaultValue)
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

public:

  utils::ArrayList<uint8_t> arrayList;
  uint8_t                   defaultValue;

};

TEST_F(ArrayListTest, SizeZeroConstructor)
{
  EXPECT_EQ(0U, arrayList.size());
}

TEST_F(ArrayListTest, StartingSizeConstructor)
{
  const uint64_t startingSize = 5U;
  const uint8_t  defaultValue = 1U;
  
  utils::ArrayList<uint8_t> initializedArrayList(defaultValue, startingSize);
  
  EXPECT_EQ(startingSize, initializedArrayList.size());
  for (uint64_t i = 0U; i < startingSize; ++i)
  {
    EXPECT_EQ(defaultValue, initializedArrayList[i]);
  }
}

TEST_F(ArrayListTest, CopyConstructor)
{
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
  arrayList.resize(2U);

  arrayList[0U] = 10U;
  arrayList[1U] = 20U;

  utils::ArrayList<uint8_t> assignedArrayList(0U);

  assignedArrayList = arrayList;

  ASSERT_EQ(arrayList.size(), assignedArrayList.size());
  EXPECT_EQ(arrayList[0U], assignedArrayList[0U]);
  EXPECT_EQ(arrayList[1U], assignedArrayList[1U]);
}

TEST_F(ArrayListTest, Resize)
{
  const uint64_t newSize = 542U;
  arrayList.resize(newSize);
  EXPECT_EQ(newSize, arrayList.size());

  for (uint64_t i = 0U; i < newSize; ++i)
  {
    EXPECT_EQ(defaultValue, arrayList[i]);
  }
}

TEST_F(ArrayListTest, clear)
{
  arrayList.resize(3U);
  arrayList[0U] = 23U;
  arrayList[1U] = 42U;
  arrayList[2U] = 74U;

  arrayList.clear();

  EXPECT_EQ(0U, arrayList.size());
}

}
