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

  Messages::DriveStateCommand driveStateCommand;

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

  Messages::DriveStateCommand initializedCommand(xDirection, yDirection, zDirection);
  EXPECT_EQ(1,       initializedCommand.xDirection);
  EXPECT_EQ(-1,      initializedCommand.yDirection);
  EXPECT_EQ(3,       initializedCommand.zDirection);
}

TEST_F(DriveStateCommandTest, initialize)
{
  driveStateCommand.xDirection = 1;
  driveStateCommand.yDirection = -1;
  driveStateCommand.zDirection = 3;

  driveStateCommand.initialize();

  EXPECT_EQ(0, driveStateCommand.xDirection);
  EXPECT_EQ(0, driveStateCommand.yDirection);
  EXPECT_EQ(0, driveStateCommand.zDirection);
}

TEST_F(DriveStateCommandTest, pack)
{
  Utils::ArrayList<uint8_t> bytes = driveStateCommand.pack();

  unsigned int identifier = driveStateCommand.getId();
  ASSERT_EQ(4U, sizeof(identifier));

  ASSERT_EQ(7U, bytes.size());
  EXPECT_EQ(1U, bytes[0U]);
  EXPECT_EQ(0U, bytes[1U]);
  EXPECT_EQ(0U, bytes[2U]);
  EXPECT_EQ(0U, bytes[3U]);
  EXPECT_EQ(0U, bytes[4U]);
  EXPECT_EQ(0U, bytes[5U]);
  EXPECT_EQ(0U, bytes[6U]);

  driveStateCommand.xDirection = -1;
  driveStateCommand.yDirection = -128;
  driveStateCommand.zDirection = 127;

  bytes = driveStateCommand.pack();

  ASSERT_EQ(7U,  bytes.size());
  EXPECT_EQ(1U,  bytes[0U]);
  EXPECT_EQ(0U,  bytes[1U]);
  EXPECT_EQ(0U,  bytes[2U]);
  EXPECT_EQ(0U,  bytes[3U]);
  EXPECT_EQ(255, bytes[4U]);
  EXPECT_EQ(128, bytes[5U]);
  EXPECT_EQ(127, bytes[6U]);
}

TEST_F(DriveStateCommandTest, unpack)
{
  Utils::ArrayList<uint8_t> packedBytes(7U, 0U);
  unsigned int id = driveStateCommand.getId();
  ASSERT_EQ(4U, sizeof(id));

  packedBytes[0U] = static_cast<uint8_t>(id);
  packedBytes[4U] = 255U;
  packedBytes[5U] = 128U;
  packedBytes[6U] = 127U;

  driveStateCommand.unpack(packedBytes);

  EXPECT_EQ(-1,   driveStateCommand.xDirection);
  EXPECT_EQ(-128, driveStateCommand.yDirection);
  EXPECT_EQ(127,  driveStateCommand.zDirection);

  packedBytes[0U] = 23;
  packedBytes[4U] = -3;
  packedBytes[5U] = 43;
  packedBytes[6U] = 72;

  driveStateCommand.unpack(packedBytes);

  EXPECT_EQ(-1,   driveStateCommand.xDirection);
  EXPECT_EQ(-128, driveStateCommand.yDirection);
  EXPECT_EQ(127,  driveStateCommand.zDirection);

}

}


