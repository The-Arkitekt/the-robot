#include <gtest/gtest.h>
#include "DriveStateCommand.h"

namespace gtest
{

class DriveStateCommandTest : public testing::Test
{
protected:

  DriveStateCommandTest():
    driveStateCommand()
  {
  }

  ~DriveStateCommandTest() override 
  {
  }

  void SetUp() override 
  {
  }

  void TearDown() override 
  {
  }

public:

  messaging::DriveStateCommand driveStateCommand;

};

TEST_F(DriveStateCommandTest, DefaultConstructor) 
{
  EXPECT_EQ(0, driveStateCommand.xDirection);
  EXPECT_EQ(0, driveStateCommand.yDirection);
  EXPECT_EQ(0, driveStateCommand.zDirection);
}

TEST_F(DriveStateCommandTest, ParameterConstructor)
{
  int8_t xDirection = 1;
  int8_t yDirection = -1;
  int8_t zDirection = 3;

  messaging::DriveStateCommand initializedCommand(xDirection, yDirection, zDirection);
  EXPECT_EQ(1,       initializedCommand.xDirection);
  EXPECT_EQ(-1,      initializedCommand.yDirection);
  EXPECT_EQ(3,       initializedCommand.zDirection);
}

TEST_F(DriveStateCommandTest, init)
{
  driveStateCommand.xDirection = 1;
  driveStateCommand.yDirection = -1;
  driveStateCommand.zDirection = 3;

  driveStateCommand.init();

  EXPECT_EQ(0, driveStateCommand.xDirection);
  EXPECT_EQ(0, driveStateCommand.yDirection);
  EXPECT_EQ(0, driveStateCommand.zDirection);
}

TEST_F(DriveStateCommandTest, pack)
{
  utils::ArrayList<uint8_t> bytes = driveStateCommand.pack();

  ASSERT_EQ(4U, bytes.size());
  EXPECT_EQ(0U, bytes[0U]);
  EXPECT_EQ(0U, bytes[1U]);
  EXPECT_EQ(0U, bytes[2U]);

  driveStateCommand.xDirection = -1;
  driveStateCommand.yDirection = -128;
  driveStateCommand.zDirection = 127;

  bytes = driveStateCommand.pack();

  ASSERT_EQ(4U,  bytes.size());
  EXPECT_EQ(255, bytes[0U]);
  EXPECT_EQ(128, bytes[1U]);
  EXPECT_EQ(127, bytes[2U]);
}

TEST_F(DriveStateCommandTest, unpack)
{
  utils::ArrayList<uint8_t> packedBytes(4U, 0U);
  packedBytes[0U] = driveStateCommand.identifier();
  packedBytes[1U] = 255;
  packedBytes[2U] = 128;
  packedBytes[3U] = 127;

  driveStateCommand.unpack(packedBytes);

  EXPECT_EQ(-1,   driveStateCommand.xDirection);
  EXPECT_EQ(-128, driveStateCommand.yDirection);
  EXPECT_EQ(127,  driveStateCommand.zDirection);

  packedBytes[0U] = 23;
  packedBytes[1U] = -3;
  packedBytes[2U] = 43;
  packedBytes[3U] = 72;

  driveStateCommand.unpack(packedBytes);

  EXPECT_EQ(-1,   driveStateCommand.xDirection);
  EXPECT_EQ(-128, driveStateCommand.yDirection);
  EXPECT_EQ(127,  driveStateCommand.zDirection);

}

}


