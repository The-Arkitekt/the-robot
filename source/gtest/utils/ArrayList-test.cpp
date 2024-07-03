#include <gtest/gtest.h>
#include "ArrayList.h"

namespace gtest
{

class ArrayListTest : public testing::Test
{
protected:

  ArrayListTest():
    arrayList()
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

};

TEST_F(ArrayListTest, DefaultConstructor)
{
  EXPECT_EQ(0U, arrayList.size());
}

TEST_F(ArrayListTest, StartingSizeConstructor)
{
  const uint64_t startingSize = 5U;
  
  utils::ArrayList<uint8_t> initializedArrayList(startingSize);
  
  EXPECT_EQ(startingSize, initializedArrayList.size());
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

  utils::ArrayList<uint8_t> assignedArrayList;

  assignedArrayList = arrayList;

  ASSERT_EQ(arrayList.size(), assignedArrayList.size());
  EXPECT_EQ(arrayList[0U], assignedArrayList[0U]);
  EXPECT_EQ(arrayList[1U], assignedArrayList[1U]);
}

TEST_F(ArrayListTest, Resize)
{
  arrayList.resize(542);
  EXPECT_EQ(542, arrayList.size());
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
