#include <gtest/gtest.h>
#include "DriveStateCommand.h"

class DriveStateCommandTest : public testing::Test
{
protected:

  DriveStateCommandTest() 
  {
    driveStateCommand = new (std::nothrow) DriveStateCommand();
  }

  ~DriveStateCommandTest() override 
  {
    delete driveStateCommand;
  }

   void SetUp() override 
  {
    ASSERT_NE(nullptr, driveStateCommand);
  }

  void TearDown() override 
  {
  }

public:

  DriveStateCommand * driveStateCommand;

};

TEST_F(DriveStateCommandTest, DefaultConstructor) 
{
  EXPECT_EQ(0, driveStateCommand->xDirection);
  EXPECT_EQ(0, driveStateCommand->yDirection);
  EXPECT_EQ(0, driveStateCommand->zDirection);
}

TEST_F(DriveStateCommandTest, ParameterConstructor)
{
  int8_t xDirection = 1;
  int8_t yDirection = -1;
  int8_t zDirection = 3;

  DriveStateCommand * initializedCommand = new (std::nothrow) DriveStateCommand(xDirection,
                                                                                yDirection,
                                                                                zDirection);
  ASSERT_NE(nullptr, initializedCommand);
  EXPECT_EQ(1, initializedCommand->xDirection);
  EXPECT_EQ(-1, initializedCommand->yDirection);
  EXPECT_EQ(3, initializedCommand->zDirection);

  delete initializedCommand;
}

TEST_F(DriveStateCommandTest, init)
{
  driveStateCommand->xDirection = 1;
  driveStateCommand->yDirection = -1;
  driveStateCommand->zDirection = 3;

  driveStateCommand->init();

  EXPECT_EQ(0, driveStateCommand->xDirection);
  EXPECT_EQ(0, driveStateCommand->yDirection);
  EXPECT_EQ(0, driveStateCommand->zDirection);
}

TEST_F(DriveStateCommandTest, size)
{
  EXPECT_EQ(3U, driveStateCommand->size());
}

TEST_F(DriveStateCommandTest, pack)
{
  uint8_t const * const initialBytes = driveStateCommand->pack();

  ASSERT_NE(nullptr, initialBytes);
  EXPECT_EQ(0U, initialBytes[0U]);
  EXPECT_EQ(0U, initialBytes[1U]);
  EXPECT_EQ(0U, initialBytes[2U]);

  driveStateCommand->xDirection = -1;
  driveStateCommand->yDirection = -128;
  driveStateCommand->zDirection = 127;

  uint8_t const * const modifiedBytes = driveStateCommand->pack();

  ASSERT_NE(nullptr, initialBytes);
  EXPECT_EQ(255, modifiedBytes[0U]);
  EXPECT_EQ(128, modifiedBytes[1U]);
  EXPECT_EQ(127, modifiedBytes[2U]);
}

TEST_F(DriveStateCommandTest, unpack)
{
  uint8_t packedBytes[3U];
  packedBytes[0U] = 255;
  packedBytes[1U] = 128;
  packedBytes[2U] = 127;

  driveStateCommand->unpack(packedBytes, 3U);

  EXPECT_EQ(-1, driveStateCommand->xDirection);
  EXPECT_EQ(-128, driveStateCommand->yDirection);
  EXPECT_EQ(127, driveStateCommand->zDirection);

  packedBytes[0U] = 23;
  packedBytes[1U] = -3;
  packedBytes[2U] = 43;

  driveStateCommand->unpack(packedBytes, 4U);

  EXPECT_EQ(-1, driveStateCommand->xDirection);
  EXPECT_EQ(-128, driveStateCommand->yDirection);
  EXPECT_EQ(127, driveStateCommand->zDirection);

}


