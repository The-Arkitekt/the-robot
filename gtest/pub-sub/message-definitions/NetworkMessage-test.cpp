#include <gtest/gtest.h>
#include "NetworkMessage.h"

namespace gtest
{

class NetworkMessageTest : public testing::Test
{
protected:

  NetworkMessageTest():
    networkMessage()
  {
  }

  ~NetworkMessageTest() override 
  {
  }

  void SetUp() override 
  {
  }

  void TearDown() override 
  {
  }

public:

  Messages::NetworkMessage networkMessage;

};

TEST_F(NetworkMessageTest, DefaultConstructor) 
{
  EXPECT_EQ(0,  networkMessage.senderId);
  EXPECT_EQ(0,  networkMessage.recipientId);
  EXPECT_EQ(0U, networkMessage.messageData.size());
  EXPECT_EQ(0U, networkMessage.messageData[0U]);
}

TEST_F(NetworkMessageTest, ParameterConstructor)
{
  unsigned int              senderId    = 1U;
  unsigned int              recipientId = 2U;
  Utils::ArrayList<uint8_t> messageData(1U, 0U);
  messageData[0U] = 3U;

  Messages::NetworkMessage initializedMessage(senderId, recipientId, messageData);
  EXPECT_EQ(1U, initializedMessage.senderId);
  EXPECT_EQ(2U, initializedMessage.recipientId);
  ASSERT_EQ(1U, initializedMessage.messageData.size());
  EXPECT_EQ(3U, initializedMessage.messageData[0U]);
}

TEST_F(NetworkMessageTest, initialize)
{
  networkMessage.senderId    = 1U;
  networkMessage.recipientId = 2U;
  networkMessage.messageData.resize(1U);
  networkMessage.messageData[0U] = 3U;

  networkMessage.initialize();

  EXPECT_EQ(0U, networkMessage.senderId);
  EXPECT_EQ(0U, networkMessage.recipientId);
  EXPECT_EQ(0U, networkMessage.messageData.size());
}

TEST_F(NetworkMessageTest, pack)
{
  Utils::ArrayList<uint8_t> bytes = networkMessage.pack();
  
  unsigned int messageId   = networkMessage.getId();
  unsigned int intSize     = sizeof(messageId);
  unsigned int headerBytes = 3U * intSize;

  ASSERT_EQ(headerBytes, bytes.size());
  for (unsigned int i = 0U; i < headerBytes; ++i)
  {
    EXPECT_EQ(0U, bytes[i]);
  }

  networkMessage.senderId    = 1U;
  networkMessage.recipientId = 2U;
  networkMessage.messageData.resize(2U);
  networkMessage.messageData[0U] = 3U;
  networkMessage.messageData[1U] = 4U;

  bytes = networkMessage.pack();

  ASSERT_EQ(4U, sizeof(intSize));
 
  ASSERT_EQ(14U, bytes.size());

  EXPECT_EQ(0U, bytes[0U]);
  EXPECT_EQ(0U, bytes[1U]);
  EXPECT_EQ(0U, bytes[2U]);
  EXPECT_EQ(0U, bytes[3U]);

  EXPECT_EQ(1U, bytes[4U]);
  EXPECT_EQ(0U, bytes[5U]);
  EXPECT_EQ(0U, bytes[6U]);
  EXPECT_EQ(0U, bytes[7U]);

  EXPECT_EQ(2U, bytes[8U]);
  EXPECT_EQ(0U, bytes[9U]);
  EXPECT_EQ(0U, bytes[10U]);
  EXPECT_EQ(0U, bytes[11U]);

  EXPECT_EQ(3U, bytes[12U]);
  EXPECT_EQ(4U, bytes[13U]);
}

TEST_F(NetworkMessageTest, unpack)
{
  Utils::ArrayList<uint8_t> packedBytes(16U, 0U);
  unsigned int messageId = networkMessage.getId();
  packedBytes[0U]  = static_cast<uint8_t>(messageId);
  packedBytes[4U]  = 12U;
  packedBytes[8U]  = 13U;
  packedBytes[12U] = 5U;
  packedBytes[13U] = 8U;
  packedBytes[14U] = 9U;
  packedBytes[15U] = 11U;

  networkMessage.unpack(packedBytes);

  EXPECT_EQ(12U, networkMessage.senderId);
  EXPECT_EQ(13U, networkMessage.recipientId);
  ASSERT_EQ(4U,  networkMessage.messageData.size());
  EXPECT_EQ(5U,  networkMessage.messageData[0U]);
  EXPECT_EQ(8U,  networkMessage.messageData[1U]);
  EXPECT_EQ(9U,  networkMessage.messageData[2U]);
  EXPECT_EQ(11U, networkMessage.messageData[3U]);
  
}

}


